#pragma once

#include <QKeyEvent>
#include <QThread>
#include "ui_uranus.h"
#include "video_processor.hpp"
#include "Drone/drone_control.hpp"
#include "Drone/drone_status.hpp"
#include "Drone/drone_stream.hpp"

class Uranus : public QMainWindow {

	Q_OBJECT

public:
	Uranus(QWidget *parent = Q_NULLPTR);
	void SetFrameToBlack() const;

protected:
	void keyPressEvent(QKeyEvent *key_event) override;
	void keyReleaseEvent(QKeyEvent *key_event) override;

private:
	Ui::UranusClass ui;

	DroneControl* drone_control_;
	QThread drone_control_thread_;

	DroneStatus* drone_status_;
	QThread drone_status_thread_;

	//DroneStream* drone_stream__;
	//QThread drone_stream_thread_;

	// 0 - roll
	// 1 - pitch
	// 2 - throttle
	// 3 - yaw
	int rc_[4] = { 0 };
	int stick_ = 50;

	VideoProcessor video_processor_;
	QThread video_processor_thread_;

	char* url_drone_ = "udp://0.0.0.0:11111";

private slots:
	void on_connect_btn_clicked();
	void on_stick_slider_value_changed(const int value);
	void on_speed_slider_value_changed(const int value);
	void show_frame(QImage* frame);
	void show_status(int* params_);
	void show_all_status(QString buff);

signals:
	void connect_signal();
	void takeoff_signal();
	void land_signal();
	void stream_open_signal();
	void stream_close_signal();
	void rc_signal(const int roll, const int pitch, const int throttle, const int yaw);
	void flip_signal(const char direction);
	void speed_change_signal(const int value);
	
	void start_getting_frame(char* url);
};
