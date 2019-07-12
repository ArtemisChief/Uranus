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

	// ���Ʊ������Զ����ɵĿ������캯���͸�ֵ���캯��
	DISALLOW_COPY_AND_ASSIGN(DroneStream);

	// ���캯��
	DroneStream();

	// ����
	static DroneStream* drone_stream_;

	// �շ���Ƶ����UDP Socket
	QUdpSocket* socket_;

	// ���˻���Ƶ�����ؽ��ն˿ڵ�ַ
	int local_port_stream_ = 11111;

	// ���ڴ洢һ�����Ļ���
	QByteArray datagram_buffer_;

	// ���ڻ���һ֡�Ļ�����
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