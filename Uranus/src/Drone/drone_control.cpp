#include <iostream>
#include "drone_control.hpp"

DroneControl* DroneControl::drone_control_ = nullptr;

DroneControl::DroneControl() {
	socket_ = new QUdpSocket(this);
	buffer_ = new char[10];

	is_connected_ = false;
	is_takeoff_ = false;
	is_streaming_ = false;
}

DroneControl* DroneControl::GetInstance() {
	if (drone_control_ == nullptr)
		drone_control_ = new DroneControl();
	return drone_control_;
}

bool DroneControl::Connect() {
	socket_->writeDatagram("command", static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_->readDatagram(buffer_, sizeof buffer_);
	if (!strcmp(buffer_, "ok"))
		return false;
	is_connected_ = true;
	return true;
}

bool DroneControl::Takeoff() {
	socket_->writeDatagram("takeoff", static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_->readDatagram(buffer_, sizeof buffer_);
	if (!strcmp(buffer_, "ok"))
		return false;
	is_takeoff_ = true;
	return true;
}

bool DroneControl::Land() {
	socket_->writeDatagram("land", static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_->readDatagram(buffer_, sizeof buffer_);
	if (!strcmp(buffer_, "ok"))
		return false;
	is_takeoff_ = false;
	return true;
}

void DroneControl::MoveForward(const int distance) const {
	QString data = QString("fordward %1").arg(distance);
	socket_->writeDatagram(data.toLocal8Bit(), static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_->readDatagram(buffer_, sizeof buffer_);
}

void DroneControl::MoveBackward(const int distance) const {
	QString data = QString("back %1").arg(distance);
	socket_->writeDatagram(data.toLocal8Bit(), static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_->readDatagram(buffer_, sizeof buffer_);
}

void DroneControl::MoveLeft(const int distance) const {
	QString data = QString("left  %1").arg(distance);
	socket_->writeDatagram(data.toLocal8Bit(), static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_->readDatagram(buffer_, sizeof buffer_);
}

void DroneControl::MoveRight(const int distance) const {
	QString data = QString("right  %1").arg(distance);
	socket_->writeDatagram(data.toLocal8Bit(), static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_->readDatagram(buffer_, sizeof buffer_);
}

void DroneControl::MoveUp(const int distance) const {
	QString data = QString("up  %1").arg(distance);
	socket_->writeDatagram(data.toLocal8Bit(), static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_->readDatagram(buffer_, sizeof buffer_);
}

void DroneControl::MoveDown(const int distance) const {
	QString data = QString("down  %1").arg(distance);
	socket_->writeDatagram(data.toLocal8Bit(), static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_->readDatagram(buffer_, sizeof buffer_);
}

void DroneControl::RotateLeft(const int degree) const {
	QString data = QString("ccw  %1").arg(degree);
	socket_->writeDatagram(data.toLocal8Bit(), static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_->readDatagram(buffer_, sizeof buffer_);
}

void DroneControl::RotateRight(const int degree) const {
	QString data = QString("cw  %1").arg(degree);
	socket_->writeDatagram(data.toLocal8Bit(), static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_->readDatagram(buffer_, sizeof buffer_);
}

void DroneControl::Flip(const char direction) const {
	QString data = QString("flip  %1").arg(direction);
	socket_->writeDatagram(data.toLocal8Bit(), static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_->readDatagram(buffer_, sizeof buffer_);
}

void DroneControl::SetRC(const int roll, const int pitch, const int throttle, const int yaw) const {
	QString data = QString("rc %1 %2 %3 %4").arg(roll).arg(pitch).arg(throttle).arg(yaw);
	socket_->writeDatagram(data.toLocal8Bit(), static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_->readDatagram(buffer_, sizeof buffer_);
}

bool DroneControl::SetSpeed(const int value) const {
	QString data = QString("speed  %1").arg(value);
	socket_->writeDatagram(data.toLocal8Bit(), static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_->readDatagram(buffer_, sizeof buffer_);
	if (!strcmp(buffer_, "ok"))
		return false;
	return true;
}

bool DroneControl::OpenStream() {
	socket_->writeDatagram("streamon", static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_->readDatagram(buffer_, sizeof buffer_);
	if (!strcmp(buffer_, "ok"))
		return false;
	is_streaming_ = true;
	return true;
}

bool DroneControl::CloseStream() {
	socket_->writeDatagram("streamoff", static_cast<QHostAddress>(ip_drone_), remote_port_control_);
	socket_->readDatagram(buffer_, sizeof buffer_);
	if (!strcmp(buffer_, "ok"))
		return false;
	is_streaming_ = false;
	return true;
}

bool DroneControl::get_is_connected() const { return is_connected_; }

bool DroneControl::get_is_takeoff() const { return is_takeoff_; }

bool DroneControl::get_is_streaming() const { return is_streaming_; }
