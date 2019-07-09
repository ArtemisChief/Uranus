#include "uranus.h"

Uranus::Uranus(QWidget *parent) : QMainWindow(parent) {
	drone_ = Drone::GetInstance();

	ui.setupUi(this);
	ui.videoLabel->setScaledContents(true);
	connect(&timer_, SIGNAL(timeout()), this, SLOT(get_frame()));
	//connect(&timer_, SIGNAL(timeout()), this, SLOT(set_text()));

	black_= cv::Mat(1280, 720, CV_8UC1,cv::Scalar(0));
	SetImageBlack();
}

void Uranus::SetImageBlack() {
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
		drone_->MoveForward(1);
		break;
	case Qt::Key_A:
		drone_->MoveLeft(1);
		break;
	case Qt::Key_S:
		drone_->MoveBackward(1);
		break;
	case Qt::Key_D:
		drone_->MoveRight(1);
		break;
	case Qt::Key_Q:
		drone_->RotateLeft(1);
		break;
	case Qt::Key_E:
		drone_->RotateRight(1);
		break;
	case Qt::Key_Space:
		drone_->MoveUp(1);
		break;
	case Qt::Key_Shift:
		drone_->MoveDown(1);
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

void Uranus::get_frame() {
	*capture_ >> frame_;
	cv::resize(frame_, frame_, cv::Size(1280, 720));

	cv::Mat rgb_img;
	cvtColor(frame_, rgb_img, CV_BGR2RGB);
	QImage image_rgb(static_cast<const uchar *>(rgb_img.data), rgb_img.cols, rgb_img.rows, rgb_img.step, QImage::Format_RGB888);
	image_rgb.bits();
	ui.videoLabel->setPixmap(QPixmap::fromImage(image_rgb));
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
	capture_ = new cv::VideoCapture(url_drone_);
	capture_->open(0);
	timer_.start(20);
}

void Uranus::on_streamoffBtn_clicked() {
	drone_->CloseStream();
	timer_.stop();
	capture_->release();
	delete capture_;
	capture_ = nullptr;
	SetImageBlack();
}




