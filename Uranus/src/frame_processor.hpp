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

	// ���Ʊ������Զ����ɵĿ������캯���͸�ֵ���캯��
	DISALLOW_COPY_AND_ASSIGN(FrameProcessor);

	// ���캯��
	FrameProcessor();

	// ����
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
