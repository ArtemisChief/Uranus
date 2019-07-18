#pragma once
#include <QObject>
#include <QImage>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/types_c.h>
#include "target_tracker.hpp"

extern "C"
{
#include "libavcodec\avcodec.h"
#include "libswscale\swscale.h"
#include "libavutil\imgutils.h"
}

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName&);             \
    TypeName& operator=(const TypeName&)

class FrameProcessor :public QObject {

	Q_OBJECT

public:

	static FrameProcessor* GetInstance();

private:

	// ���Ʊ������Զ����ɵĿ������캯���͸�ֵ���캯��
	DISALLOW_COPY_AND_ASSIGN(FrameProcessor);

	// ���캯��
	FrameProcessor();

	// ����
	static FrameProcessor* frame_processor_;

	// Ŀ�����
	bool is_ready_to_select_target_;
	bool is_ready_to_track_target_;
	TargetTracker* target_tracker_;
	cv::Rect2d roi_;

	// FFmpeg
	AVCodec *codec_;
	AVCodecContext *codec_context_;
	AVCodecParserContext *parser_context_;
	AVFrame *frame_;
	AVPacket *packet_;
	SwsContext *sws_context_;
	AVFrame *rgb_frame_;

	//
	int aim_rec_width_;
	int aim_rec_height_;
	int aim_rec_x_;
	int aim_rec_y_;
public slots:

	void ConsturctFrame(QByteArray& bytes);
	void ReadyToSelectTarget(const cv::Rect2d roi);

signals:

	void frame_ready_signal(const QImage image);

};
