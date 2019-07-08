#include "drone.h"
#include <iostream>

Drone::Drone() {
	socket_control_ = new QUdpSocket(this);
	buf_control_ = new char[8];

	socket_status_ = new QUdpSocket(this);
	buf_status_ = new char[256];
	socket_status_->bind(local_port_status_);
	connect(socket_status_, SIGNAL(readyRead()), this, SLOT(receive_and_update_status()));

	socket_stream_ = new QUdpSocket(this);
	socket_stream_->bind(local_port_stream_);
}

bool Drone::Connect() const {
	socket_control_->writeDatagram("command", static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
	if (!strcmp(buf_control_, "ok"))
		return false;
	return true;
}

bool Drone::Takeoff() const {
	socket_control_->writeDatagram("takeoff", static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
	if (!strcmp(buf_control_, "ok"))
		return false;
	return true;
}

bool Drone::Land() const {
	socket_control_->writeDatagram("land", static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
	if (!strcmp(buf_control_, "ok"))
		return false;
	return true;
}

void Drone::MoveForward(const int distance) const {
	QString data = "forward " + distance;
	socket_control_->writeDatagram(data.toLocal8Bit(), static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
}

void Drone::MoveBackward(const int distance) const {
	QString data = "back " + distance;
	socket_control_->writeDatagram(data.toLocal8Bit(), static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
}

void Drone::MoveLeft(const int distance) const {
	QString data = "left " + distance;
	socket_control_->writeDatagram(data.toLocal8Bit(), static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
}

void Drone::MoveRight(const int distance) const {
	QString data = "right " + distance;
	socket_control_->writeDatagram(data.toLocal8Bit(), static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
}

void Drone::MoveUp(const int distance) const {
	QString data = "up " + distance;
	socket_control_->writeDatagram(data.toLocal8Bit(), static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
}

void Drone::MoveDown(const int distance) const {
	QString data = "down " + distance;
	socket_control_->writeDatagram(data.toLocal8Bit(), static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
}

void Drone::RotateLeft(const int degree) const {
	QString data = "ccw " + degree;
	socket_control_->writeDatagram(data.toLocal8Bit(), static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
}

void Drone::RotateRight(const int degree) const {
	QString data = "cw " + degree;
	socket_control_->writeDatagram(data.toLocal8Bit(), static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
}

bool Drone::SetSpeed(const int value) const {
	QString data = "speed " + value;
	socket_control_->writeDatagram(data.toLocal8Bit(), static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
	if (!strcmp(buf_control_, "ok"))
		return false;
	return true;
}

bool Drone::OpenStream() const {
	socket_control_->writeDatagram("streamon", static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
	if (!strcmp(buf_control_, "ok"))
		return false;
	return true;
}


bool Drone::CloseStream() const {
	socket_control_->writeDatagram("streamoff", static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
	if (!strcmp(buf_control_, "ok"))
		return false;
	return true;
}

void Drone::receive_and_update_status() {
	while (socket_status_->hasPendingDatagrams()) {
		socket_status_->readDatagram(buf_status_, sizeof buf_status_);
		char* next_token = nullptr;
		char* token = strtok_s(buf_status_, ";", &next_token);
		for (auto i = 0; i < 16; i++) {
			params_[i] = atoi(token);
			token = strtok_s(nullptr, ";", &next_token);
		}
	}
}

inline int Drone::get_pitch() const { return params_[0]; }

inline int Drone::get_roll() const { return params_[1]; }

inline int Drone::get_yaw() const { return params_[2]; }

inline int Drone::get_vgx() const { return params_[3]; }

inline int Drone::get_vgy() const { return params_[4]; }

inline int Drone::get_vgz() const { return params_[5]; }

inline int Drone::get_templ() const { return params_[6]; }

inline int Drone::get_temph() const { return params_[7]; }

inline int Drone::get_tof() const { return params_[8]; }

inline int Drone::get_height() const { return params_[9]; }

inline int Drone::get_battery() const { return params_[10]; }

inline int Drone::get_baro() const { return params_[11]; }

inline int Drone::get_time() const { return params_[12]; }

inline int Drone::get_agx() const { return params_[13]; }

inline int Drone::get_agy() const { return params_[14]; }

inline int Drone::get_agz() const { return params_[15]; }