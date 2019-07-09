#include "uranus.h"

Uranus::Uranus(QWidget *parent) : QMainWindow(parent) {
	drone_ = Drone::GetInstance();
	video_processor_.moveToThread(&video_processor_thread_);
	connect(&video_processor_thread_, &QThread::finished, &video_processor_, &QObject::deleteLater);
	connect(this, &Uranus::start_getting_frame, &video_processor_, &VideoProcessor::get_frame);
	connect(&video_processor_, &VideoProcessor::pass_frame, this, &Uranus::show_video);
	video_processor_thread_.start();

	ui.setupUi(this);
	this->grabKeyboard();
	ui.videoLabel->setScaledContents(true);
	//connect(&timer_, SIGNAL(timeout()), this, SLOT(set_text()));

	black_= cv::Mat(1280, 720, CV_8UC1,cv::Scalar(0));
	SetImageBlack();
}

void Uranus::SetImageBlack() const {
	QImage image_rgb(static_cast<const uchar *>(black_.data), black_.cols, black_.rows, black_.step, QImage::Format_Grayscale8);
	image_rgb.bits();
	ui.videoLabel->setPixmap(QPixmap::fromImage(image_rgb));
}

void Uranus::keyPressEvent(QKeyEvent* key_event) {
	if(!drone_->get_is_connected())
		return;

	const auto key_value = key_event->key();
	switch (key_value) {
	case Qt::Key_W:
		drone_->MoveForward(5);
		break;
	case Qt::Key_A:
		drone_->MoveLeft(5);
		break;
	case Qt::Key_S:
		drone_->MoveBackward(5);
		break;
	case Qt::Key_D:
		drone_->MoveRight(5);
		break;
	case Qt::Key_Q:
		drone_->RotateLeft(5);
		break;
	case Qt::Key_E:
		drone_->RotateRight(5);
		break;
	case Qt::Key_Space:
		drone_->MoveUp(5);
		break;
	case Qt::Key_Shift:
		drone_->MoveDown(5);
		break;
	default:
		break;
	}
}

void Uranus::keyReleaseEvent(QKeyEvent* key_event)
{

}

void Uranus::set_text() {
	ui.label->setText(QString::number(drone_->get_time()));
}

void Uranus::show_video(QImage* image) {
	ui.videoLabel->setPixmap(QPixmap::fromImage(*image));
}

void Uranus::on_connectBtn_clicked() {
	drone_->Connect();
}


void Uranus::on_takeoffBtn_clicked() {
	drone_->Takeoff();
}

void Uranus::on_landBtn_clicked() {
	drone_->Land();
}

void Uranus::on_streamonBtn_clicked() {
	drone_->OpenStream();
	emit start_getting_frame(url_drone_);
}

void Uranus::on_streamoffBtn_clicked() {
	drone_->CloseStream();
	//emit stop_getting_frame();
	SetImageBlack();
}




