#include "uranus.hpp"

Uranus::Uranus(QWidget *parent) : QMainWindow(parent) {
	drone_control_ = DroneControl::GetInstance();
	video_processor_.moveToThread(&video_processor_thread_);
	connect(&video_processor_thread_, &QThread::finished, &video_processor_, &QObject::deleteLater);
	connect(this, &Uranus::start_getting_frame, &video_processor_, &VideoProcessor::get_frame);
	connect(&video_processor_, &VideoProcessor::pass_frame, this, &Uranus::show_frame);
	video_processor_thread_.start();

	ui.setupUi(this);
	this->grabKeyboard();
	ui.videoLabel->setScaledContents(true);

	black_= cv::Mat(1280, 720, CV_8UC1,cv::Scalar(0));
	SetImageBlack();
}

void Uranus::SetImageBlack() const {
	QImage image_rgb(static_cast<const uchar *>(black_.data), black_.cols, black_.rows, black_.step, QImage::Format_Grayscale8);
	image_rgb.bits();
	ui.videoLabel->setPixmap(QPixmap::fromImage(image_rgb));
}

void Uranus::keyPressEvent(QKeyEvent* key_event) {
	if (!drone_control_->get_is_connected())
		return;

	const auto key_value = key_event->key();
	switch (key_value) {
	case Qt::Key_W:
		rc_[1] = 50 * rc_factor_;
		break;
	case Qt::Key_A:
		rc_[0] = -50 * rc_factor_;
		break;
	case Qt::Key_S:
		rc_[1] = -50 * rc_factor_;
		break;
	case Qt::Key_D:
		rc_[0] = 50 * rc_factor_;
		break;
	case Qt::Key_Q:
		rc_[3] = -50 * rc_factor_;
		break;
	case Qt::Key_E:
		rc_[3] = 50 * rc_factor_;
		break;
	case Qt::Key_Space:
		rc_[2] = 50 * rc_factor_;
		break;
	case Qt::Key_Control:
		rc_[2] = -50 * rc_factor_;
		break;
	case Qt::Key_Shift:
		rc_factor_ = 2;
		break;
	case Qt::Key_Up:
		drone_control_->Flip('f');
		break;
	case Qt::Key_Left:
		drone_control_->Flip('l');
		break;
	case Qt::Key_Right:
		drone_control_->Flip('r');
		break;
	case Qt::Key_Down:
		drone_control_->Flip('b');
		break;
	case Qt::Key_R:
		if (drone_control_->get_is_streaming()) {
			drone_control_->CloseStream();
			//emit stop_getting_frame();
			SetImageBlack();
		}
		else {
			drone_control_->OpenStream();
			emit start_getting_frame(url_drone_);
		}
		break;
	case Qt::Key_Tab:
		if (drone_control_->get_is_takeoff())
			drone_control_->Land();
		else
			drone_control_->Takeoff();
		break;
	default:
		break;
	}

	drone_control_->SetRC(rc_[0], rc_[1], rc_[2], rc_[3]);
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
	case Qt::Key_Control:
		rc_[2] = 0;
		break;
	case Qt::Key_Shift:
		rc_factor_ = 1;
		break;
	default:
		break;
	}

	drone_control_->SetRC(rc_[0], rc_[1], rc_[2], rc_[3]);
}

void Uranus::show_frame(QImage* frame) {
	ui.videoLabel->setPixmap(QPixmap::fromImage(*frame));
}

void Uranus::on_connectBtn_clicked() {
	drone_control_->Connect();
}

