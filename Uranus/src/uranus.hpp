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

	QTimer timer_;

	// 0 - roll
	// 1 - pitch
	// 2 - throttle
	// 3 - yaw
	int rc_[4] = { 0 };
	int stick_ = 50;

	bool is_mouse_down_;
	QPoint mouse_start_point_;
	QPoint mouse_end_point_;

	bool start_tracking_ = false;
	int goal_x_ = 355;
	int last_error_x_ = 0;
	int total_error_x_ = 0;
	int goal_y_ = 355;
	int last_error_y_ = 0;
	int total_error_y_ = 0;
	int goal_diagonal_ = 190;
	int last_error_diagonal_ = 0;
	int total_error_diagonal_ = 0;

private slots:

	void on_rc_factor_slider_valueChanged(const int value);
	void on_speed_slider_valueChanged(const int value);
	void SendHeartBeat();
	void ShowFrame(QImage frame) const;
	void ShowStatus(int* params_) const;
	void TrackTarget(const cv::Rect2d roi);

signals:

	void connect_signal();
	void takeoff_signal();
	void land_signal();
	void stream_open_signal();
	void stream_close_signal();
	void rc_signal(const int roll, const int pitch, const int throttle, const int yaw);
	void flip_signal(const char direction);
	void speed_change_signal(const int value);
	void target_select_signal(cv::Rect2d roi);
	void emergency_signal();
};
