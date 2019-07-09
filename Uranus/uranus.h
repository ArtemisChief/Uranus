#pragma once

#include <QKeyEvent>
#include <QThread>
#include "ui_uranus.h"
#include "drone.h"
#include "video_processor.h"

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
	Drone* drone_;
	VideoProcessor video_processor_;
	QThread video_processor_thread_;

	char* url_drone_ = "udp://0.0.0.0:11111";

	cv::Mat black_;

private slots:
	void set_text();
	void show_video(QImage* image);
	void on_connectBtn_clicked();
	void on_takeoffBtn_clicked();
	void on_landBtn_clicked();
	void on_streamonBtn_clicked();
	void on_streamoffBtn_clicked();

signals:
	void start_getting_frame(char* url);
};
