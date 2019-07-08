#include "drone.h"
#include <iostream>


Drone::Drone() {
	socket_control_ = new QUdpSocket(this);
	socket_status_ = new QUdpSocket(this);
	socket_stream_ = new QUdpSocket(this);

	socket_control_->bind(port_control_);
	socket_status_->bind(port_status_);
	socket_stream_->bind(port_stream_);

	buf_control_ = new char[10];
	buf_status_ = new char[100];
	buf_stream_ = new char[4096]; // 未知，暂定

	// 发送"command"命令启动Tello的SDK模式
	socket_control_->writeDatagram("command", static_cast<QHostAddress>(ip_drone_), port_control_);

	// 接收返回值
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
}

void Drone::Takeoff() const {
	socket_control_->writeDatagram("takeoff", static_cast<QHostAddress>(ip_drone_), port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
}

void Drone::Land() const {
	socket_control_->writeDatagram("land", static_cast<QHostAddress>(ip_drone_), port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
}

void Drone::MoveForward(const int distance) const {
	QString data = "forward " + distance;
	socket_control_->writeDatagram(data.toLocal8Bit(), static_cast<QHostAddress>(ip_drone_), port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
}

void Drone::MoveBackward(const int distance) const {
	QString data = "back " + distance;
	socket_control_->writeDatagram(data.toLocal8Bit(), static_cast<QHostAddress>(ip_drone_), port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
}

void Drone::MoveLeft(const int distance) const {
	QString data = "left " + distance;
	socket_control_->writeDatagram(data.toLocal8Bit(), static_cast<QHostAddress>(ip_drone_), port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
}

void Drone::MoveRight(const int distance) const {
	QString data = "right " + distance;
	socket_control_->writeDatagram(data.toLocal8Bit(), static_cast<QHostAddress>(ip_drone_), port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
}

void Drone::MoveUp(const int distance) const {
	QString data = "up " + distance;
	socket_control_->writeDatagram(data.toLocal8Bit(), static_cast<QHostAddress>(ip_drone_), port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
}

void Drone::MoveDown(const int distance) const {
	QString data = "down " + distance;
	socket_control_->writeDatagram(data.toLocal8Bit(), static_cast<QHostAddress>(ip_drone_), port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
}

void Drone::RotateLeft(const int degree) const {
	QString data = "ccw " + degree;
	socket_control_->writeDatagram(data.toLocal8Bit(), static_cast<QHostAddress>(ip_drone_), port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
}

void Drone::RotateRight(const int degree) const {
	QString data = "cw " + degree;
	socket_control_->writeDatagram(data.toLocal8Bit(), static_cast<QHostAddress>(ip_drone_), port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
}

void Drone::SetSpeed(const int value) const {
	QString data = "speed " + value;
	socket_control_->writeDatagram(data.toLocal8Bit(), static_cast<QHostAddress>(ip_drone_), port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
}

void Drone::OpenStream() const {
	socket_control_->writeDatagram("streamon", static_cast<QHostAddress>(ip_drone_), port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
}


void Drone::CloseStream() const {
	socket_control_->writeDatagram("streamoff", static_cast<QHostAddress>(ip_drone_), port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
}

inline int Drone::get_vgx() const { return vgx_; }

inline int Drone::get_vgy() const { return vgy_; }

inline int Drone::get_vgz() const { return vgz_; }

inline int Drone::get_agx() const { return agx_; }

inline int Drone::get_agy() const { return agy_; }

inline int Drone::get_agz() const { return agz_; }

inline int Drone::get_battery() const { return battery_; }

inline int Drone::get_height() const { return height_; }

inline int Drone::get_pitch() const { return pitch_; }

inline int Drone::get_roll() const { return roll_; }

inline int Drone::get_yaw() const { return yaw_; }
