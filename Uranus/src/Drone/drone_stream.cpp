#include "drone_stream.hpp"
#include <iostream>

DroneStream* DroneStream::drone_stream_ = nullptr;

DroneStream::DroneStream() {
	socket_ = new QUdpSocket(this);
	socket_->bind(QHostAddress("0.0.0.0"), local_port_stream_);
	connect(socket_, SIGNAL(readyRead()), this, SLOT(ReceiveDatagram()));

	avcodec_register_all();

	codec_ = avcodec_find_decoder(AV_CODEC_ID_H264);
	if (!codec_)
		std::cout << "cannot find decoder" << std::endl;

	codec_context_ = avcodec_alloc_context3(codec_);
	if (!codec_context_)
		std::cout << "cannot allocate context" << std::endl;

	if (codec_->capabilities & AV_CODEC_CAP_TRUNCATED) {
		codec_context_->flags |= AV_CODEC_CAP_TRUNCATED;
	}

	if (avcodec_open2(codec_context_, codec_, nullptr) < 0)
		std::cout << "cannot open context" << std::endl;

	parser_context_ = av_parser_init(AV_CODEC_ID_H264);
	if (!parser_context_)
		std::cout << "cannot init parser" << std::endl;

	frame_ = av_frame_alloc();
	if (!frame_)
		std::cout << "cannot allocate frame" << std::endl;

	packet_ = new AVPacket;
	if (!packet_)
		std::cout << "cannot allocate packet" << std::endl;

	av_init_packet(packet_);

	sws_context_ = nullptr;

	rgb_frame_ = av_frame_alloc();
	if (!rgb_frame_)
		std::cout << "cannot allocate rgb_frame" << std::endl;
}

DroneStream* DroneStream::GetInstance() {
	if (drone_stream_ == nullptr)
		drone_stream_ = new DroneStream();
	return drone_stream_;
}

void DroneStream::ConsturctFrame(QByteArray& bytes) {
	auto length = bytes.length();
	auto data_in = new uchar[length];
	memcpy(data_in, bytes.data(), length);

	while (length > 0) {

		const size_t num_consumed = av_parser_parse2(parser_context_, codec_context_,
													 &packet_->data, &packet_->size,
													 data_in, length,
													 0, 0, AV_NOPTS_VALUE);

		const auto is_frame_available = packet_->size > 0;

		if (is_frame_available) {
			auto got_picture = 0;
			const auto nread = avcodec_decode_video2(codec_context_, frame_, &got_picture, packet_);
			if (nread < 0 || got_picture == 0) {
				std::cout << "error decoding frame" << std::endl;
			}
			else {

				const auto width = frame_->width;
				const auto height = frame_->height;
				const auto out_buffer = static_cast<uint8_t *>(av_malloc(avpicture_get_size(AV_PIX_FMT_RGB32, width, height) * sizeof(uint8_t)));

				sws_context_ = sws_getCachedContext(sws_context_,
													width, height, static_cast<AVPixelFormat>(frame_->format),
													width, height, AV_PIX_FMT_RGB32, SWS_BILINEAR,
													nullptr, nullptr, nullptr);
				if (!sws_context_)
					std::cout << "can't allocate sws_context" << std::endl;

				avpicture_fill(reinterpret_cast<AVPicture*>(rgb_frame_), out_buffer, AV_PIX_FMT_RGB32, width, height);

				sws_scale(sws_context_, frame_->data, frame_->linesize, 0, height,
						  rgb_frame_->data, rgb_frame_->linesize);
				rgb_frame_->width = width;
				rgb_frame_->height = height;

				QImage *tempImage = new QImage(static_cast<uchar*>(out_buffer), width, height, QImage::Format_RGB32);
				const auto image = tempImage->copy();
				av_free(out_buffer);

				emit frame_ready_signal(image);
			}
		}
		length -= num_consumed;
		data_in += num_consumed;
	}

	av_packet_unref(packet_);
}

void DroneStream::ReceiveDatagram() {
	while (socket_->hasPendingDatagrams()) {

		std::cout << std::endl << "PendingDatagramSize: " << socket_->pendingDatagramSize() << std::endl;

		const auto datagram_size = socket_->pendingDatagramSize();
		datagram_buffer_.resize(datagram_size);
		socket_->readDatagram(datagram_buffer_.data(), datagram_size);
		frame_buffer_.append(datagram_buffer_);

		std::cout << "Datagram Length: " << datagram_buffer_.length() << std::endl << "Frame Length: " << frame_buffer_.length() << std::endl;

		// 收到一帧的最后一个包
		if (datagram_buffer_.length() != 1460) {
			ConsturctFrame(frame_buffer_);
			std::cout << "----Frame complete----" << std::endl;
			frame_buffer_.clear();
		}
	}
}
