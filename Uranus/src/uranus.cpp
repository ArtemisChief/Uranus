#include "uranus.hpp"

Uranus::Uranus(QWidget *parent) : QMainWindow(parent) {

	// GUI
	ui.setupUi(this);
	ui.frame_label->setScaledContents(true);
	ui.battery_bar->setStyleSheet("QProgressBar{border:2px solid grey;"
								  "border-radius:4px;text-align:center;}"
								  "QProgressBar::chunk{background-color:skyblue;"
								  "width:8px;margin:0.5px;}");
	setCursor(Qt::CrossCursor);

	// 鼠标变量初始化
	is_mouse_down_ = false;

	// 能获取键盘焦点
	this->grabKeyboard();

	// 控制命令收发线程
	drone_control_ = DroneControl::GetInstance();
	drone_control_->moveToThread(&drone_control_thread_);
	connect(this, &Uranus::connect_signal, drone_control_, &DroneControl::Connect);
	connect(this, &Uranus::takeoff_signal, drone_control_, &DroneControl::Takeoff);
	connect(this, &Uranus::land_signal, drone_control_, &DroneControl::Land);
	connect(this, &Uranus::stream_open_signal, drone_control_, &DroneControl::OpenStream);
	connect(this, &Uranus::stream_close_signal, drone_control_, &DroneControl::CloseStream);
	connect(this, &Uranus::rc_signal, drone_control_, &DroneControl::SetRC);
	connect(this, &Uranus::flip_signal, drone_control_, &DroneControl::Flip);
	connect(this, &Uranus::speed_change_signal, drone_control_, &DroneControl::SetSpeed);
	drone_control_thread_.start();

	// 状态接收更新线程
	drone_status_ = DroneStatus::GetInstance();
	drone_status_->moveToThread(&drone_status_thread_);
	connect(drone_status_, &DroneStatus::update_states_signal, this, &Uranus::ShowStatus);
	drone_status_thread_.start();

	// 视频流接收线程
	drone_stream_ = DroneStream::GetInstance();
	drone_stream_->moveToThread(&drone_stream_thread_);
	drone_stream_thread_.start();

	// 帧处理线程
	frame_processor_ = FrameProcessor::GetInstance();
	frame_processor_->moveToThread(&frame_processor_thread_);
	connect(frame_processor_, &FrameProcessor::frame_ready_signal, this, &Uranus::ShowFrame);
	connect(drone_stream_, &DroneStream::construct_frame_signal, frame_processor_, &FrameProcessor::ConsturctFrame);
	connect(this, &Uranus::target_select_signal, frame_processor_, &FrameProcessor::ReadyToSelectTarget);
	connect(TargetTracker::GetInstance(), &TargetTracker::update_roi_signal, this, &Uranus::TrackTarget);
	frame_processor_thread_.start();

	// UI主线程
	connect(&timer_, SIGNAL(timeout()), this, SLOT(SendHeartBeat()));
	timer_.start(1000);
}

Uranus::~Uranus() {
	// 关闭视频流
	emit stream_close_signal();
	
	drone_control_->deleteLater();
	drone_control_thread_.quit();
	drone_control_thread_.wait();

	drone_status_->deleteLater();
	drone_status_thread_.quit();
	drone_status_thread_.wait();

	drone_stream_->deleteLater();
	drone_stream_thread_.quit();
	drone_stream_thread_.wait();

	frame_processor_->deleteLater();
	frame_processor_thread_.quit();
	frame_processor_thread_.wait();
}

void Uranus::SendHeartBeat() {
	// 发送连接指令
	emit connect_signal();

	// 发送推流指令
	if (drone_control_->get_is_connected() && !drone_control_->get_is_streaming())
		emit stream_open_signal();
}

void Uranus::keyPressEvent(QKeyEvent* key_event) {
	if (!drone_control_->get_is_connected())
		return;

	const auto key_value = key_event->key();
	switch (key_value) {
	case Qt::Key_W:
		rc_[1] = stick_;
		break;
	case Qt::Key_A:
		rc_[0] = -stick_;
		break;
	case Qt::Key_S:
		rc_[1] = -stick_;
		break;
	case Qt::Key_D:
		rc_[0] = stick_;
		break;
	case Qt::Key_Q:
		rc_[3] = -stick_;
		break;
	case Qt::Key_E:
		rc_[3] = stick_;
		break;
	case Qt::Key_Space:
		rc_[2] = stick_;
		break;
	case Qt::Key_Shift:
		rc_[2] = -stick_;
		break;
	case Qt::Key_Up:
		emit flip_signal('f');
		break;
	case Qt::Key_Left:
		emit flip_signal('l');
		break;
	case Qt::Key_Right:
		emit flip_signal('r');
		break;
	case Qt::Key_Down:
		emit flip_signal('b');
		break;
	case Qt::Key_F1:
		rc_[0] = rc_[1] = rc_[2] = rc_[3] = 0;
		start_tracking_ = !start_tracking_;
		total_error_width_ = total_error_x_ = last_error_width_ = last_error_x_ = 0;
		break;
	case Qt::Key_CapsLock:
		if (drone_control_->get_is_takeoff())
			emit land_signal();
		else
			emit takeoff_signal();
		break;
	default:
		break;
	}

	emit rc_signal(rc_[0], rc_[1], rc_[2], rc_[3]);
}

void Uranus::keyReleaseEvent(QKeyEvent* key_event) {
	if (!drone_control_->get_is_connected())
		return;

	const auto key_value = key_event->key();
	switch (key_value) {
	case Qt::Key_W:
		rc_[1] = 0;
		break;
	case Qt::Key_A:
		rc_[0] = 0;
		break;
	case Qt::Key_S:
		rc_[1] = 0;
		break;
	case Qt::Key_D:
		rc_[0] = 0;
		break;
	case Qt::Key_Q:
		rc_[3] = 0;
		break;
	case Qt::Key_E:
		rc_[3] = 0;
		break;
	case Qt::Key_Space:
		rc_[2] = 0;
		break;
	case Qt::Key_Shift:
		rc_[2] = 0;
		break;

	case Qt::Key_F1:
		rc_[0] = rc_[1] = rc_[2] = rc_[3] = 0;
		break;

	default:
		break;
	}

	emit rc_signal(rc_[0], rc_[1], rc_[2], rc_[3]);
}

void Uranus::mousePressEvent(QMouseEvent* event) {
	if (event->button() == Qt::LeftButton) {
		is_mouse_down_ = true;
		mouse_start_point_ = event->pos();
		mouse_end_point_ = event->pos();
	}
}

void Uranus::mouseMoveEvent(QMouseEvent* event) {
	if (is_mouse_down_) {
		mouse_end_point_ = event->pos();
	}
}

void Uranus::mouseReleaseEvent(QMouseEvent* event) {
	if(event->pos()== mouse_start_point_)
		return;
	if (is_mouse_down_) {
		is_mouse_down_ = false;
		mouse_end_point_ = event->pos();

		int width = mouse_start_point_.x() - mouse_end_point_.x();
		int height = mouse_start_point_.y() - mouse_end_point_.y();
		width = width > 0 ? width : -width;
		height = height > 0 ? height : -height;
		emit target_select_signal(cv::Rect2d(mouse_start_point_.x(), mouse_start_point_.y(), width, height));
	}
}

void Uranus::on_rc_factor_slider_valueChanged(const int value) {
	stick_ = value;
}

void Uranus::on_speed_slider_valueChanged(const int value) {
	emit speed_change_signal(value);
}

void Uranus::ShowFrame(QImage image) const {
	if (is_mouse_down_) {
		QPainter painter(&image);
		painter.setPen(QPen(Qt::green, 2));
		if(mouse_start_point_!=mouse_end_point_)
			painter.drawRect(QRect(mouse_start_point_, mouse_end_point_));
	}
	ui.frame_label->setPixmap(QPixmap::fromImage(image));
}

void Uranus::ShowStatus(int* params) const {
	// 计算合速度
	const auto recent_speed = sqrt(params[3] * params[3] + params[4] * params[4] + params[5] * params[5]);

	// 更新合速度
	ui.speed_label->setText(QString("Speed: %1 cm/s").arg(QString::number(recent_speed, 'f', 2)));

	// 更新俯仰角度、横滚角度、偏航角度
	ui.pitch_label->setText(QString::fromLocal8Bit("pitch: %1 °").arg(params[0]));
	ui.roll_label->setText(QString::fromLocal8Bit("roll: %1 °").arg(params[1]));
	ui.yaw_label->setText(QString::fromLocal8Bit("yaw: %1 °").arg(params[2]));

	// 更新x、y、z轴速度
	ui.vgx_label->setText(QString("vgx: %1 cm/s").arg(params[3]));
	ui.vgy_label->setText(QString("vgy: %1 cm/s").arg(params[4]));
	ui.vgz_label->setText(QString("vgz: %1 cm/s").arg(params[5]));

	// 更新主板最低/高温度
	ui.templ_label->setText(QString::fromLocal8Bit("templ: %1 °C").arg(params[6]));
	ui.temph_label->setText(QString::fromLocal8Bit("temph: %1 °C").arg(params[7]));

	// ToF距离、相对起飞点高度、当前电量、气压计测量高度、电机运转时间
	ui.tof_label->setText(QString("tof: %1 cm").arg(params[8]));
	ui.h_label->setText(QString("h: %1 cm").arg(params[9]));
	ui.battery_bar->setValue(params[10]);
	ui.baro_label->setText(QString("baro: %1 cm").arg(params[11]));
	ui.time_label->setText(QString("time: %1 s").arg(params[12]));

	// 更新x、y、z轴加速度
	ui.agx_label->setText(QString("agx: %1 mg").arg(params[13]));
	ui.agy_label->setText(QString("agy: %1 mg").arg(params[14]));
	ui.agz_label->setText(QString("agz: %1 mg").arg(params[15]));
}

//Todo: Optimize with Switch Case
void Uranus::TrackTarget(const cv::Rect2d roi) {
	if (!start_tracking_) {
		return;
	}
	const int x = roi.x;
	const int y = roi.y;
	const int width = roi.width;
	const int height = roi.height;

	//通过矩形宽判断远近，调整前进或后退
	const int error_width = goal_width_ - width;
	const int d_error_width = error_width - last_error_width_;
	last_error_width_ = error_width;

	if (abs(error_width) > 200)
		rc_[1] = error_width / abs(error_width)*stick_;
	else
	{
		total_error_width_ += error_width;
		rc_[1] = static_cast<int>(stick_ * (static_cast<float>(error_width) / 200 + total_error_width_ * 0.00001 + d_error_width * 0.0001));
	}

	//if (width > 210) {
	//	//目标框过大，距离过近,后退
	//	if (width > 410)
	//		rc_[1] = -stick_;
	//	else
	//	{
	//		total_error_width_ += width - 210;
	//		rc_[1] = static_cast<int>(-stick_ * (static_cast<float>(width - 210) / 200 + total_error_width_ * 0.001));
	//	}

	//}
	//else if (width < 170) {
	//	//目标框过小，距离过远，前进
	//	if (width < 120)
	//		rc_[1] = stick_;
	//	else
	//		rc_[1] = static_cast<int>(stick_ * static_cast<float>(170 - width) / 100);
	//}
	//else {
	//	//不动
	//	rc_[1] = 0;
	//}

	//通过顶点的横坐标x大小判断目标左右偏向
	const int error_x = goal_x_ - x;
	const int d_error_x = x - last_error_x_;
	last_error_x_ = error_x;

	if (abs(error_x) > 200)
		rc_[0] = -error_x / abs(error_x)*stick_;
	else
	{
		total_error_x_ += error_x;
		rc_[0] = static_cast<int>(-stick_ * (static_cast<float>(error_x) / 200 + total_error_x_ * 0.00001 + d_error_x * 0.0001));
	}

	//if (x < 335) {
	//	//x在左，目标在左，往左偏航
	//	if (x < 135)
	//		rc_[0] = -stick_;
	//	else
	//		rc_[0] = static_cast<int>(-stick_ * static_cast<float>(335 - x) / 200);
	//}
	//else if (x > 375) {
	//	//x在右，目标在右，往右偏航
	//	if (x > 575)
	//		rc_[0] = stick_;
	//	else
	//		rc_[0] = static_cast<int>(stick_ * static_cast<float>(x - 375) / 200);
	//}
	//else {
	//	//不动
	//	rc_[0] = 0;
	//}

	//通过顶点纵坐标y大小判断目标高低偏向
	if (y < 275) {
		//y在上，目标在上方，无人机上升
		rc_[2] = stick_ / 5;
		if (drone_status_->get_tof() > 350)
			rc_[2] = 0;
	}
	else if (y > 335) {
		//y在下，目标在下方，无人机下降
		rc_[2] = -stick_ / 5;
		if (drone_status_->get_tof() < 150)
			rc_[2] = 0;
	}
	else {
		rc_[2] = 0;
	}


	emit rc_signal(rc_[0], rc_[1], rc_[2], rc_[3]);
}
