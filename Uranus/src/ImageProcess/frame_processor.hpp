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

	// 限制编译器自动生成的拷贝构造函数和赋值构造函数
	DISALLOW_COPY_AND_ASSIGN(FrameProcessor);

	// 构造与析构函数
	FrameProcessor();
	~FrameProcessor();

	// 单例
	static FrameProcessor* frame_processor_;

	// 目标跟踪
	bool is_ready_to_select_target_;
	bool is_ready_to_track_target_;
	TargetTracker* target_tracker_;
	QPoint mouse_start_point_;
	QPoint mouse_end_point_;

	// FFmpeg
	AVCodec *codec_;
	AVCodecContext *codec_context_;
	AVCodecParserContext *parser_context_;
	AVFrame *frame_;
	AVPacket *packet_;
	SwsContext *sws_context_;
	AVFrame *rgb_frame_;

public slots:

	void ConsturctFrame(QByteArray& bytes);
	void ReadyToSelectTarget(QPoint mouse_start_point, QPoint mouse_end_point);

signals:

	void frame_ready_signal(const QImage image);

};
