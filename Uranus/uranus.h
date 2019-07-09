#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/types_c.h>
#include <QTimer>
#include <QKeyEvent>
#include "ui_uranus.h"
#include "drone.h"

class Uranus : public QMainWindow
{
	Q_OBJECT

public:
	Uranus(QWidget *parent = Q_NULLPTR);
	void SetImageBlack();

protected:
	void keyPressEvent(QKeyEvent *key_event);
	void keyReleaseEvent(QKeyEvent *key_event);

private:
	Ui::UranusClass ui;
	Drone* drone_;

	char* url_drone_ = "udp://0.0.0.0:11111";
	QTimer timer_;
	cv::Mat frame_;
	cv::VideoCapture capture_;

	cv::Mat black_;

private slots:
	void set_text();
	void get_frame();
	void on_connectBtn_clicked();
	void on_takeoffBtn_clicked();
	void on_landBtn_clicked();
	void on_streamonBtn_clicked();
	void on_streamoffBtn_clicked();
};
