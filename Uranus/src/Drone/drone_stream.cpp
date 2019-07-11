#include "drone_stream.hpp"
#include <qimage.h>
#include <iostream>

DroneStream* DroneStream::drone_stream_ = nullptr;
SwsContext* DroneStream::img_convert_ctx = nullptr;

DroneStream::DroneStream() {
	socket_ = new QUdpSocket(this);
	socket_->bind(local_port_stream_);
	// buffer_ = new char[10240];
	// buffer_ = new QByteArray(10240,Qt::Initialization());
	connect(socket_, SIGNAL(readyRead()), this, SLOT(GetFrame()));
	av_register_all();
	codec = avcodec_find_decoder(AV_CODEC_ID_H264);
	codec_context = avcodec_alloc_context3(codec);
	parser = av_parser_init(AV_CODEC_ID_H264);
	avcodec_open2(codec_context, codec, NULL);
	// video_data.resize(2920);
	//video_data = new char[2920];
	video_data = "";
}

DroneStream* DroneStream::GetInstance() {
	if (drone_stream_ == nullptr)
		drone_stream_ = new DroneStream();
	return drone_stream_;
}

void DroneStream::GetFrame()
{
	while (socket_->hasPendingDatagrams())
	{
		int size = socket_->pendingDatagramSize();
		buffer_ = new char[size];
		socket_->readDatagram(buffer_, size);
		if (*buffer_ == '\0')
			continue;
		std::string temp(buffer_, size);
		video_data += temp;
		delete buffer_;
		std::cout << size << std::endl;;
		if (size == 1460)
			continue;
		frame = av_frame_alloc();
		frame_rgb = av_frame_alloc();

		packet = new AVPacket;
		av_init_packet(packet);


		input_buffer = (uint8_t *)av_malloc(video_data.size());
		memcpy_s(input_buffer, video_data.size(), video_data.data(), video_data.size());

		int len = video_data.size();
		int used;
		while (len) {
			used=av_parser_parse2(parser, codec_context, &packet->data, &packet->size,
				input_buffer, len,
				0, 0, AV_NOPTS_VALUE);
			input_buffer += used;
			len -= used;
		}
		std::cout << packet->size << std::endl;	

		video_data = "";

		int ret;
		int got_picture;
		std::cout << codec_context->width << "   " << codec_context->height << std::endl;
		ret = avcodec_decode_video2(codec_context, frame, &got_picture, packet);

		if (ret < 0) {
			printf("decode error.\n");
			return;
		}

		if (got_picture) {

			int numBytes = avpicture_get_size(AV_PIX_FMT_RGB32, codec_context->width, codec_context->height);

			uint8_t* out_buffer = (uint8_t *)av_malloc(numBytes * sizeof(uint8_t));


			avpicture_fill((AVPicture *)frame_rgb, out_buffer, AV_PIX_FMT_RGB32,
				codec_context->width, codec_context->height);

			img_convert_ctx = sws_getContext(
				codec_context->width, codec_context->height, codec_context->pix_fmt,
				codec_context->width, codec_context->height, AV_PIX_FMT_RGB32, SWS_BICUBIC,
				nullptr, nullptr, nullptr);

			sws_scale(img_convert_ctx, frame->data, frame->linesize, 0, frame->height,
				frame_rgb->data, frame_rgb->linesize);

			QImage image((uchar *)out_buffer, codec_context->width, codec_context->height, QImage::Format_RGB32);

			emit frame_ready_signal(&image);
		}
		av_free_packet(packet);

	}

	
}