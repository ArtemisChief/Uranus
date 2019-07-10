#include "drone_stream.hpp"

DroneStream* DroneStream::drone_stream_ = nullptr;

DroneStream::DroneStream() {
	socket_ = new QUdpSocket(this);
	buffer_ = new char[4096];
}

DroneStream* DroneStream::GetInstance() {
	if (drone_stream_ == nullptr)
		drone_stream_ = new DroneStream();
	return drone_stream_;
}
