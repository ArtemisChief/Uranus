#pragma once
#include <qobject.h>
#include <QImage>
#include <qudpsocket.h>

extern "C"
{
#include "libavcodec\avcodec.h"
#include "libswscale\swscale.h"
#include "libavutil\imgutils.h"
#include "libavformat\avformat.h"
}

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName&);             \
    TypeName& operator=(const TypeName&)

class DroneStream : public QObject {

	Q_OBJECT

public:

	static DroneStream* GetInstance();

	void ConsturctFrame(QByteArray& bytes);

private:

	// 限制编译器自动生成的拷贝构造函数和赋值构造函数
	DISALLOW_COPY_AND_ASSIGN(DroneStream);

	// 构造函数
	DroneStream();

	// 单例
	static DroneStream* drone_stream_;

	// 收发视频流的UDP Socket
	QUdpSocket* socket_;

	// 无人机视频流本地接收端口地址
	int local_port_stream_ = 11111;

	// 用于存储一个包的缓存
	QByteArray datagram_buffer_;

	// 用于缓存一帧的缓存区
	QByteArray frame_buffer_;

	// 
	AVCodec *codec_;
	AVCodecContext *codec_context_;
	AVCodecParserContext *parser_context_;
	AVFrame *frame_;
	AVPacket *packet_;
	SwsContext *sws_context_;
	AVFrame *rgb_frame_;

private slots:

	void ReceiveDatagram();

signals:

	void frame_ready_signal(QImage image);

};