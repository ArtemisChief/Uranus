#include "drone_stream.hpp"
#include <qimage.h>

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
	avcodec_open2(codec_context, codec, nullptr);
	avcodec_open2(codec_context, codec, NULL);
	// video_data.resize(2920);
	video_data = new char[2920];
}

DroneStream* DroneStream::GetInstance() {
	if (drone_stream_ == nullptr)
		drone_stream_ = new DroneStream();
	return drone_stream_;
}

void DroneStream::GetFrame()
{
	int size = socket_->pendingDatagramSize();
	buffer_=new char[size];
	socket_->readDatagram(buffer_, size);
	if (*buffer_ == '\0')
		return;
	strcat_s(video_data, 2920, buffer_);
	delete buffer_;
	if (size == 1460)
		return;
	frame = av_frame_alloc();
	frame_rgb = av_frame_alloc();

	av_new_packet(&packet, strlen(video_data));

	memcpy_s(packet.data, strlen(video_data), video_data, strlen(video_data));

	delete video_data;
	video_data = new char[2920];


	int ret, got_picture;
	ret = avcodec_decode_video2(codec_context, frame, &got_picture, &packet);

	if (ret < 0) {
		printf("decode error.\n");
		return;
	}

	if (got_picture) {

		int numBytes = avpicture_get_size(AV_PIX_FMT_RGB32, codec_context->width, codec_context->height);

		out_buffer = (uint8_t *)av_malloc(numBytes * sizeof(uint8_t));

		av_parser_parse2(parser, codec_context, &packet.data, &packet.size,
			out_buffer, sizeof out_buffer,
			0, 0, AV_NOPTS_VALUE);

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
	av_free_packet(&packet);

	
}