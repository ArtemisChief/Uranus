#pragma once
#include <qobject.h>
#include <qudpsocket.h>
#include <stddef.h>

extern "C"
{
#include "libavformat\avformat.h"  
#include "libswscale\swscale.h"      
};

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName&);             \
    TypeName& operator=(const TypeName&)

class DroneStream : public QObject {

	Q_OBJECT

public:
	static DroneStream* GetInstance();

public slots:
	void GetFrame();

signals:
	void frame_ready_signal(QImage *image);


private:

	DroneStream();

	// ����
	static DroneStream* drone_stream_;

	// ���Ʊ������Զ����ɵĿ������캯���͸�ֵ���캯��
	DISALLOW_COPY_AND_ASSIGN(DroneStream);

	// �շ���Ƶ����UDP Socket
	QUdpSocket* socket_;

	// ����ֵ������
	char* buffer_;
	// QByteArray buffer_;

	// ���˻���Ƶ�����ؽ��ն˿ڵ�ַ
	int local_port_stream_ = 11111;

	AVCodec *codec;
	AVCodecContext *codec_context;
	AVCodecParserContext  *parser;
	AVFrame *frame, *frame_rgb;
	AVPacket *packet;
	static struct SwsContext *img_convert_ctx;
	uint8_t *input_buffer;
	std::string video_data;

};