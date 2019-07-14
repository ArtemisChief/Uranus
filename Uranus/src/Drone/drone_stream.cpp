#include "drone_stream.hpp"

DroneStream* DroneStream::drone_stream_ = nullptr;

DroneStream* DroneStream::GetInstance() {
	if (drone_stream_ == nullptr)
		drone_stream_ = new DroneStream();
	return drone_stream_;
}

DroneStream::DroneStream() {
	socket_ = new QUdpSocket(this);
	socket_->bind(LOCAL_PORT_STREAM);

	// 每当socket收到信息时调用ReceiveDatagram
	connect(socket_, SIGNAL(readyRead()), this, SLOT(ReceiveDatagram()));
}

void DroneStream::ReceiveDatagram() {
	while (socket_->hasPendingDatagrams()) {
		const auto datagram_size = socket_->pendingDatagramSize();
		datagram_buffer_.resize(datagram_size);
		socket_->readDatagram(datagram_buffer_.data(), datagram_size);
		frame_buffer_.append(datagram_buffer_);

		// 收到一帧的最后一个包
		if (datagram_buffer_.length() != 1460) {
			emit construct_frame_signal(frame_buffer_);
			frame_buffer_.clear();
		}
	}
}
