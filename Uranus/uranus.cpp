#include "uranus.h"

using namespace cv;
using namespace std;

Uranus::Uranus(QWidget *parent) : QMainWindow(parent) {
	ui.setupUi(this);
}

void Uranus::on_connectBtn_clicked() {
	if (drone_ != nullptr)
		drone_ = new Drone();
}


void Uranus::on_takeoffBtn_clicked() {
	drone_->Takeoff();
}

void Uranus::on_landBtn_clicked() {
	drone_->Land();
}

void Uranus::on_streamonBtn_clicked() {
	drone_->OpenStream();
	String url = "udp://0.0.0.0:11111";
	VideoCapture cap(url);
	Mat frame;
	cap >> frame;
	cv::resize(frame, frame, Size(256, 256));

	Mat cvRgbImg;
	cvtColor(frame, cvRgbImg, CV_BGR2RGB);
	QImage dstImage_RGB(static_cast<const uchar *>(cvRgbImg.data), cvRgbImg.cols, cvRgbImg.rows, cvRgbImg.step, QImage::Format_RGB888);
	dstImage_RGB.bits();
	QImage pic_origin = dstImage_RGB;
	ui.videoLabel->setScaledContents(true);
	ui.videoLabel->setPixmap(QPixmap::fromImage(pic_origin));


}

