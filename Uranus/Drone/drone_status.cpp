#include "drone_status.h"

DroneStatus* DroneStatus::drone_status_ = nullptr;

DroneStatus::DroneStatus() {
	socket_ = new QUdpSocket(this);
	buffer_ = new char[256];
}

DroneStatus* DroneStatus::GetInstance() {
	if (drone_status_ == nullptr)
		drone_status_ = new DroneStatus();
	return drone_status_;
}

int DroneStatus::get_pitch() const { return params_[0]; }

int DroneStatus::get_roll() const { return params_[1]; }

int DroneStatus::get_yaw() const { return params_[2]; }

int DroneStatus::get_vgx() const { return params_[3]; }

int DroneStatus::get_vgy() const { return params_[4]; }

int DroneStatus::get_vgz() const { return params_[5]; }

int DroneStatus::get_templ() const { return params_[6]; }

int DroneStatus::get_temph() const { return params_[7]; }

int DroneStatus::get_tof() const { return params_[8]; }

int DroneStatus::get_height() const { return params_[9]; }

int DroneStatus::get_battery() const { return params_[10]; }

int DroneStatus::get_baro() const { return params_[11]; }

int DroneStatus::get_time() const { return params_[12]; }

int DroneStatus::get_agx() const { return params_[13]; }

int DroneStatus::get_agy() const { return params_[14]; }

int DroneStatus::get_agz() const { return params_[15]; }