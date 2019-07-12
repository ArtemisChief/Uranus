#pragma once
#include <qobject.h>
#include <QImage>
#include <qudpsocket.h>

#define LOCAL_PORT_STREAM 11111

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName&);             \
    TypeName& operator=(const TypeName&)

class DroneStream : public QObject {

	Q_OBJECT

public:

	static DroneStream* GetInstance();

private:

	// 限制编译器自动生成的拷贝构造函数和赋值构造函数
	DISALLOW_COPY_AND_ASSIGN(DroneStream);

	// 构造与析构函数
	DroneStream();
	~DroneStream();

	// 单例
	static DroneStream* drone_stream_;

	// 收发视频流的UDP Socket
	QUdpSocket* socket_;

	// 用于存储一个包的缓存
	QByteArray datagram_buffer_;

	// 用于缓存一帧的缓存区
	QByteArray frame_buffer_;

private slots:

	void ReceiveDatagram();

signals:

	void construct_frame_signal(QByteArray& bytes);

};