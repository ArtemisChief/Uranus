#include "frame_processor.hpp"

FrameProcessor* FrameProcessor::frame_processor_ = nullptr;

FrameProcessor* FrameProcessor::GetInstance() {
	if (frame_processor_ == nullptr)
		frame_processor_ = new FrameProcessor();
	return frame_processor_;
}

FrameProcessor::FrameProcessor() {

	// Ŀ�����
	is_ready_to_select_target_ = false;
	is_ready_to_track_target_ = false;
	target_tracker_ = TargetTracker::GetInstance();

	// ʹ��H264������
	codec_ = avcodec_find_decoder(AV_CODEC_ID_H264);

	// ���ý�����������
	codec_context_ = avcodec_alloc_context3(codec_);

	if (codec_->capabilities & AV_CODEC_CAP_TRUNCATED)
		codec_context_->flags |= AV_CODEC_CAP_TRUNCATED;

	avcodec_open2(codec_context_, codec_, nullptr);

	// ʹ��H264��Ƶ��������
	parser_context_ = av_parser_init(AV_CODEC_ID_H264);

	// ����YUV֡�ڴ�ռ�
	frame_ = av_frame_alloc();

	// ����֡���ݰ��ڴ�ռ�
	packet_ = new AVPacket;

	// ֡���ݰ���ʼ��
	av_init_packet(packet_);

	// ����YUV-RGB�任������
	sws_context_ = nullptr;

	// ����RGB֡�ڴ�ռ�
	rgb_frame_ = av_frame_alloc();
}

void FrameProcessor::ConsturctFrame(QByteArray& bytes) {
	auto length = bytes.length();
	auto data_in = new uchar[length];
	auto *data_in_ptr = data_in;

	// ���ﲻʹ��ǿ������ת��������char���͵�ǿ������ת������\0ֱ��ֹͣ�����¶�ʧ����
	memcpy(data_in, bytes.data(), length);

	while (length > 0) {
		// ��һ�����ݰ��н�����һ֡�����ݣ���䵽packet_->data��
		const size_t num_consumed = av_parser_parse2(parser_context_, codec_context_, &packet_->data, &packet_->size,
													 data_in, length, 0, 0, AV_NOPTS_VALUE);

		// ���֮���packet_size����0������ɹ�������һ֡������
		const auto is_frame_available = packet_->size > 0;

		if (is_frame_available) {
			// ��һ֡h264���������н����YUV��ʽ��ͼ��
			if (avcodec_send_packet(codec_context_, packet_) == 0 && avcodec_receive_frame(codec_context_, frame_) == 0) {
				const auto width = frame_->width;
				const auto height = frame_->height;

				// ������������֡��Buffer�ռ�
				const auto out_buffer = static_cast<uint8_t *>(av_malloc(av_image_get_buffer_size(AV_PIX_FMT_RGB24, width, height, 1) * sizeof(uint8_t)));

				// ��Ҫ��õ�һ֡���ܵ�֪������
				sws_context_ = sws_getCachedContext(sws_context_, width, height, static_cast<AVPixelFormat>(frame_->format),
													width, height, AV_PIX_FMT_RGB24, SWS_BILINEAR, nullptr, nullptr, nullptr);

				// ��YUV��ʽת����RGB��ʽ
				av_image_fill_arrays(rgb_frame_->data, rgb_frame_->linesize, out_buffer, AV_PIX_FMT_RGB24, width, height, 1);

				sws_scale(sws_context_, frame_->data, frame_->linesize, 0, height,
						  rgb_frame_->data, rgb_frame_->linesize);
				rgb_frame_->width = width;
				rgb_frame_->height = height;

				const auto image_raw = cv::Mat(height, width, CV_8UC3, out_buffer);

				// ��ѡĿ��
				if (is_ready_to_select_target_) {
					if (is_ready_to_track_target_)
						target_tracker_->ClearTarget();
					target_tracker_->SelectTarget(image_raw, roi_);
					is_ready_to_select_target_ = false;
					is_ready_to_track_target_ = true;
				}

				// ����
				if (is_ready_to_track_target_) 
					target_tracker_->TrackTarget(image_raw);

				rectangle(image_raw, cv::Rect2d(335, 275, 250, 375), cv::Scalar(255, 0, 0), 2);
				rectangle(image_raw, cv::Rect2d(385, 325, 150, 275), cv::Scalar(255, 0, 0), 2);
				line(image_raw, cv::Point(335, 225), cv::Point(335, 375), cv::Scalar(0, 0, 255), 2);
				line(image_raw, cv::Point(385, 225), cv::Point(385, 375), cv::Scalar(0, 0, 255), 2);
				line(image_raw, cv::Point(285, 275), cv::Point(435, 275), cv::Scalar(0, 0, 255), 2);
				line(image_raw, cv::Point(285, 325), cv::Point(435, 325), cv::Scalar(0, 0, 255), 2);

				// ��RGB����������һ��QImageͼ��
				auto image_temp = QImage(static_cast<const uchar*>(image_raw.data), width, height, QImage::Format_RGB888);

				// �������һ��
				const auto image_out = image_temp.copy();
				
				// �ͷ�Buffer	
				av_free(out_buffer);

				emit frame_ready_signal(image_out);
			}
		}
		length -= num_consumed;
		data_in += num_consumed;
	}

	data_in = data_in_ptr;
	delete[] data_in;
	av_packet_unref(packet_);
}

void FrameProcessor::ReadyToSelectTarget(const cv::Rect2d roi) {
	is_ready_to_select_target_ = true;
	roi_ = roi;
}