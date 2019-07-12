#pragma once
#include <qobject.h>
#include "Drone/drone_stream.hpp"

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

	// 构造函数
	FrameProcessor();

	// 单例
	static FrameProcessor* frame_processor_;

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

signals:

	void frame_ready_signal(const QImage image);

};
