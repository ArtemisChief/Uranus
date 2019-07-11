#pragma once
#include <qobject.h>
#include <qudpsocket.h>
extern "C"
{
#include "libavcodec\avcodec.h"  
#include "libavformat\avformat.h"  
#include "libavutil\channel_layout.h"  
#include "libavutil\common.h"  
#include "libavutil\imgutils.h"  
#include "libswscale\swscale.h"   
#include "libavutil\imgutils.h"      
#include "libavutil\opt.h"         
#include "libavutil\mathematics.h"      
#include "libavutil\samplefmt.h"   
};
#pragma comment(lib, "avcodec.lib")  
#pragma comment(lib, "avformat.lib")  
#pragma comment(lib, "avdevice.lib")  
#pragma comment(lib, "avfilter.lib")  
#pragma comment(lib, "avutil.lib")  
#pragma comment(lib, "postproc.lib")  
#pragma comment(lib, "swresample.lib")  
#pragma comment(lib, "swscale.lib")  
using namespace std;

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

	// 单例
	static DroneStream* drone_stream_;

	// 限制编译器自动生成的拷贝构造函数和赋值构造函数
	DISALLOW_COPY_AND_ASSIGN(DroneStream);

	// 收发视频流的UDP Socket
	QUdpSocket* socket_;

	// 返回值缓存区
	char* buffer_;
	// QByteArray buffer_;

	// 无人机视频流本地接收端口地址
	int local_port_stream_ = 11111;

	AVCodec *codec;
	AVCodecContext *codec_context;
	AVCodecParserContext  *parser;
	AVFrame *frame, *frame_rgb;
	AVPacket packet;
	static struct SwsContext *img_convert_ctx;
	uint8_t *input_buffer;
	std::string video_data;

};