#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgproc/types_c.h>
#include <QtWidgets/QMainWindow>
#include <QTimer>
#include "ui_uranus.h"

using namespace cv;

class Uranus : public QMainWindow
{
	Q_OBJECT

public:
	Uranus(QWidget *parent = Q_NULLPTR);


private:
	Ui::UranusClass ui;

	QImage pic_origin;
	QImage pic_target;
	Mat frame;
	QTimer *timer;
	VideoCapture capture;

private slots:
	void on_startBtn_clicked();
	void on_stopBtn_clicked();
	void getFrame();
};
