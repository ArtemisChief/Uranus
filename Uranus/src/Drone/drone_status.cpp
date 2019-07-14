#include "drone_status.hpp"

DroneStatus* DroneStatus::drone_status_ = nullptr;

DroneStatus* DroneStatus::GetInstance() {
	if (drone_status_ == nullptr)
		drone_status_ = new DroneStatus();
	return drone_status_;
}

DroneStatus::DroneStatus() {
	socket_ = new QUdpSocket(this);
	socket_->bind(LOCAL_PORT_STATUS);

	// 每当socket收到信息时调用ReceiveStatus
	connect(socket_, SIGNAL(readyRead()), this, SLOT(ReceiveStatus()));
}

void DroneStatus::ReceiveStatus() {
	while (socket_->hasPendingDatagrams()) {
		// 读取socket中收到的状态信息，放入messages中
		QByteArray recevied_bytes;
		recevied_bytes.resize(socket_->pendingDatagramSize());
		socket_->readDatagram(recevied_bytes.data(), recevied_bytes.size());
		auto messages = QString(recevied_bytes.data());

		// 分割buffer_字符串，放入params_[]中
		auto list = messages.split(";");
		for (auto i = 5; i < 21; i++) {
			auto content = list[i];
			content = content.mid(content.indexOf(":") + 1);
			if (i > 12)
				content = content.left(content.indexOf("."));
			params_[i - 5] = content.toInt();
		}

		// 发出更新信号
		emit update_states_signal(params_);
	}
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