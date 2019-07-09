#pragma once
#include <qobject.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <qimage.h>

class VideoProcessor :public QObject {

	Q_OBJECT

public slots:
	void get_frame(char* url);

signals:
	void pass_frame(QImage *image);

private:
	cv::Mat frame_;
	cv::VideoCapture capture_;
	QImage* image_;

};
