#include "uranus.h"

using namespace cv;
using namespace std;

Uranus::Uranus(QWidget *parent) : QMainWindow(parent) {
	ui.setupUi(this);

	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(getFrame()));
}

void Uranus::on_startBtn_clicked() {
	capture.open(0);
	timer->start(20);
}

void Uranus::getFrame() {
	capture >> frame;

	cv::resize(frame, frame, Size(256, 256));

	Mat cvRgbImg;
	cvtColor(frame, cvRgbImg, CV_BGR2RGB);
	QImage dstImage_RGB(static_cast<const uchar *>(cvRgbImg.data), cvRgbImg.cols, cvRgbImg.rows, cvRgbImg.step, QImage::Format_RGB888);
	dstImage_RGB.bits();
	pic_origin = dstImage_RGB;
	ui.label1->setScaledContents(true);
	ui.label1->setPixmap(QPixmap::fromImage(pic_origin));

	Mat cvGrayImg;
	cvtColor(frame, cvGrayImg, CV_BGR2GRAY);
	QImage dstImage_GRAY(static_cast<const uchar *>(cvGrayImg.data), cvGrayImg.cols, cvGrayImg.rows, cvGrayImg.step, QImage::Format_Grayscale8);
	dstImage_GRAY.bits();
	pic_target = dstImage_GRAY;
	ui.label2->setScaledContents(true);
	ui.label2->setPixmap(QPixmap::fromImage(pic_target));
}

void Uranus::on_stopBtn_clicked()
{
	timer->stop();
	ui.label1->clear();
	capture.release();
}
