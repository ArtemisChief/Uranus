#include "drone.h"
#include <iostream>

Drone* Drone::drone_ = nullptr;

Drone::Drone() {
	is_connected_ = false;
	is_takeoff_ = false;
	is_streaming_ = false;

	socket_control_ = new QUdpSocket(this);
	buf_control_ = new char[8];

	socket_status_ = new QUdpSocket(this);
	buf_status_ = new char[256];
	socket_status_->bind(local_port_status_);
	//connect(socket_status_, SIGNAL(readyRead()), this, SLOT(receive_and_update_status()));

	socket_stream_ = new QUdpSocket(this);
	socket_stream_->bind(local_port_stream_);
}

Drone* Drone::GetInstance() {
	if (drone_ == nullptr)
		drone_ = new Drone();
	return drone_;
}

bool Drone::Connect() {
	socket_control_->writeDatagram("command", static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
	if (!strcmp(buf_control_, "ok"))
		return false;
	is_connected_ = true;
	return true;
}

bool Drone::Takeoff() {
	socket_control_->writeDatagram("takeoff", static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
	if (!strcmp(buf_control_, "ok"))
		return false;
	is_takeoff_ = true;
	return true;
}

bool Drone::Land() {
	socket_control_->writeDatagram("land", static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
	if (!strcmp(buf_control_, "ok"))
		return false;
	is_takeoff_ = false;
	return true;
}

void Drone::MoveForward(const int distance) const {
	QString data = "forward " + distance;
	socket_control_->writeDatagram(data.toStdString().c_str(), static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
}

void Drone::MoveBackward(const int distance) const {
	QString data = "back " + distance;
	socket_control_->writeDatagram(data.toStdString().c_str(), static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
}

void Drone::MoveLeft(const int distance) const {
	QString data = "left " + distance;
	socket_control_->writeDatagram(data.toStdString().c_str(), static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
}

void Drone::MoveRight(const int distance) const {
	QString data = "right " + distance;
	socket_control_->writeDatagram(data.toStdString().c_str(), static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
}

void Drone::MoveUp(const int distance) const {
	QString data = "up " + distance;
	socket_control_->writeDatagram(data.toStdString().c_str(), static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
}

void Drone::MoveDown(const int distance) const {
	QString data = "down " + distance;
	socket_control_->writeDatagram(data.toStdString().c_str(), static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
}

void Drone::RotateLeft(const int degree) const {
	QString data = "ccw " + degree;
	socket_control_->writeDatagram(data.toStdString().c_str(), static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
}

void Drone::RotateRight(const int degree) const {
	QString data = "cw " + degree;
	socket_control_->writeDatagram(data.toStdString().c_str(), static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
}

bool Drone::SetSpeed(const int value) const {
	QString data = "speed " + value;
	socket_control_->writeDatagram(data.toStdString().c_str(), static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
	if (!strcmp(buf_control_, "ok"))
		return false;
	return true;
}

bool Drone::OpenStream() {
	socket_control_->writeDatagram("streamon", static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
	if (!strcmp(buf_control_, "ok"))
		return false;
	is_streaming_ = true;
	return true;
}


bool Drone::CloseStream() {
	socket_control_->writeDatagram("streamoff", static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_control_->readDatagram(buf_control_, sizeof buf_control_);
	if (!strcmp(buf_control_, "ok"))
		return false;
	is_streaming_ = false;
	return true;
}

void Drone::receive_and_update_status() {
	while (socket_status_->hasPendingDatagrams()) {
		socket_status_->readDatagram(buf_status_, sizeof buf_status_);
		
		int i = 0;
		char* next_token = nullptr;
		char* token = strtok_s(buf_status_, ";", &next_token);
		while(token) {
			params_[i] = atoi(token);
			token = strtok_s(nullptr, ";", &next_token);
			i++;
		}
	}
}

int Drone::get_pitch() const { return params_[0]; }

int Drone::get_roll() const { return params_[1]; }

int Drone::get_yaw() const { return params_[2]; }

int Drone::get_vgx() const { return params_[3]; }

int Drone::get_vgy() const { return params_[4]; }

int Drone::get_vgz() const { return params_[5]; }

int Drone::get_templ() const { return params_[6]; }

int Drone::get_temph() const { return params_[7]; }

int Drone::get_tof() const { return params_[8]; }

int Drone::get_height() const { return params_[9]; }

int Drone::get_battery() const { return params_[10]; }

int Drone::get_baro() const { return params_[11]; }

int Drone::get_time() const { return params_[12]; }

int Drone::get_agx() const { return params_[13]; }

int Drone::get_agy() const { return params_[14]; }

int Drone::get_agz() const { return params_[15]; }

bool Drone::get_is_connected() const { return is_connected_; }

bool Drone::get_is_takeoff() const { return is_takeoff_; }

bool Drone::get_is_streaming() const { return is_streaming_; }
