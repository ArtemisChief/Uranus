#include "uranus.hpp"

Uranus::Uranus(QWidget *parent) : QMainWindow(parent) {
	drone_control_ = DroneControl::GetInstance();
	drone_control_->moveToThread(&drone_control_thread_);
	connect(&drone_control_thread_, &QThread::finished, drone_control_, &QObject::deleteLater);
	connect(this, &Uranus::connect_signal, drone_control_, &DroneControl::Connect);
	connect(this, &Uranus::takeoff_signal, drone_control_, &DroneControl::Takeoff);
	connect(this, &Uranus::land_signal, drone_control_, &DroneControl::Land);
	connect(this, &Uranus::stream_open_signal, drone_control_, &DroneControl::OpenStream);
	connect(this, &Uranus::stream_close_signal, drone_control_, &DroneControl::CloseStream);
	connect(this, &Uranus::rc_signal, drone_control_, &DroneControl::SetRC);
	connect(this, &Uranus::flip_signal, drone_control_, &DroneControl::Flip);
	connect(this, &Uranus::speed_change_signal, drone_control_, &DroneControl::SetSpeed);
	drone_control_thread_.start();

	//drone_status_ = DroneStatus::GetInstance();
	//drone_status_->moveToThread(&drone_status_thread_);
	//connect
	//drone_status_thread_.start();

	//drone_stream_ = DroneStream::GetInstance();
	//drone_stream_->moveToThread(&drone_stream_thread_);
	//connect
	//drone_stream_thread_.start();

	video_processor_.moveToThread(&video_processor_thread_);
	connect(&video_processor_thread_, &QThread::finished, &video_processor_, &QObject::deleteLater);
	connect(this, &Uranus::start_getting_frame, &video_processor_, &VideoProcessor::get_frame);
	connect(&video_processor_, &VideoProcessor::pass_frame, this, &Uranus::show_frame);
	video_processor_thread_.start();

	ui.setupUi(this);
	ui.frame_label->setScaledContents(true);

	// 设置初始视频帧为纯黑单色图
	SetFrameToBlack();

	// 能获取键盘焦点
	this->grabKeyboard();
}

void Uranus::SetFrameToBlack() const {
	const auto black_image = cv::Mat(1280, 720, CV_8UC1, cv::Scalar(0));
	QImage image_rgb(static_cast<const uchar *>(black_image.data), black_image.cols, black_image.rows, black_image.step, QImage::Format_Grayscale8);
	image_rgb.bits();
	ui.frame_label->setPixmap(QPixmap::fromImage(image_rgb));
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
	case Qt::Key_CapsLock:
		if (drone_control_->get_is_takeoff())
			emit land_signal();
		else
			emit takeoff_signal();
		break;
	case Qt::Key_R:
		if (drone_control_->get_is_streaming()) {
			emit stream_close_signal();
			//emit stop_getting_frame();
			SetFrameToBlack();
		}
		else {
			emit stream_open_signal();
			emit start_getting_frame(url_drone_);
		}
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
		rc_[0] =0;
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
	default:
		break;
	}

	emit rc_signal(rc_[0], rc_[1], rc_[2], rc_[3]);
}

void Uranus::on_connect_btn_clicked() {
	emit connect_signal();
}

void Uranus::on_stick_slider_value_changed(const int value) {
	stick_ = value;
}

void Uranus::on_speed_slider_value_changed(const int value) {
	emit speed_change_signal(value);
}

void Uranus::show_frame(QImage* frame) {
	ui.frame_label->setPixmap(QPixmap::fromImage(*frame));
}



