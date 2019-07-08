#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgproc/types_c.h>
#include <QtWidgets/QMainWindow>
#include <QTimer>
#include "ui_uranus.h"
#include "drone.h"

using namespace cv;

class Uranus : public QMainWindow
{
	Q_OBJECT

public:
	Uranus(QWidget *parent = Q_NULLPTR);

private:
	Ui::UranusClass ui;
	Drone* drone_;
	

private slots:
	void on_connectBtn_clicked();
	void on_takeoffBtn_clicked();
	void on_landBtn_clicked();
	void on_streamonBtn_clicked();
};
