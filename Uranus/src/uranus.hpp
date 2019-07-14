#pragma once

#include <QPainter>
#include <QKeyEvent>
#include <QThread>
#include <QtConcurrent/QtConcurrent>
#include <opencv2/opencv.hpp>
#include "ui_uranus.h"
#include "Drone/drone_control.hpp"
#include "Drone/drone_status.hpp"
#include "Drone/drone_stream.hpp"
#include "ImageProcess/frame_processor.hpp"

class Uranus : public QMainWindow {

	Q_OBJECT

public:

	Uranus(QWidget *parent = Q_NULLPTR);
	~Uranus();

	void AutoConnect();

protected:

	void keyPressEvent(QKeyEvent *key_event) override;
	void keyReleaseEvent(QKeyEvent *key_event) override;
	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;

private:

	Ui::UranusClass ui;

	DroneControl* drone_control_;
	QThread drone_control_thread_;

	DroneStatus* drone_status_;
	QThread drone_status_thread_;

	DroneStream* drone_stream_;
	QThread drone_stream_thread_;

	FrameProcessor* frame_processor_;
	QThread frame_processor_thread_;

	bool should_auto_connect_;

	// 0 - roll
	// 1 - pitch
	// 2 - throttle
	// 3 - yaw
	int rc_[4] = { 0 };
	int stick_ = 50;

	bool is_mouse_down_;
	QPoint mouse_start_point_;
	QPoint mouse_end_point_;

private slots:

	void on_rc_factor_slider_valueChanged(const int value);
	void on_speed_slider_valueChanged(const int value);
	void show_frame(QImage frame) const;
	void show_status(int* params_) const;

signals:

	void connect_signal();
	void takeoff_signal();
	void land_signal();
	void stream_open_signal();
	void stream_close_signal();
	void rc_signal(const int roll, const int pitch, const int throttle, const int yaw);
	void flip_signal(const char direction);
	void speed_change_signal(const int value);
	void target_select_signal(QPoint mouse_start_point, QPoint mouse_end_point);

};
