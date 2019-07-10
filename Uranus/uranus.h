#pragma once

#include <QKeyEvent>
#include <QThread>
#include "ui_uranus.h"
#include "video_processor.h"
#include "Drone/drone_control.h"

class Uranus : public QMainWindow {

	Q_OBJECT

public:
	Uranus(QWidget *parent = Q_NULLPTR);
	void SetImageBlack() const;

protected:
	virtual void keyPressEvent(QKeyEvent *key_event);
	virtual void keyReleaseEvent(QKeyEvent *key_event);

private:
	Ui::UranusClass ui;
	DroneControl* drone_control_;

	// 0 - roll
	// 1 - pitch
	// 2 - throttle
	// 3 - yaw
	int rc_[4] = { 0 };
	int rc_factor_ = 1;

	VideoProcessor video_processor_;
	QThread video_processor_thread_;

	char* url_drone_ = "udp://0.0.0.0:11111";

	cv::Mat black_;

private slots:
	void show_frame(QImage* frame);
	void on_connectBtn_clicked();

signals:
	void start_getting_frame(char* url);
};
