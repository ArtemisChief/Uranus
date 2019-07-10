#pragma once
#include <qobject.h>
#include <qudpsocket.h>

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName&);             \
    TypeName& operator=(const TypeName&)

class DroneStream : public QObject {

	Q_OBJECT

public:
	static DroneStream* GetInstance();

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

	// 无人机IP地址以及视频流本地接收端口地址
	char* ip_drone_ = "192.168.10.1";
	int local_port_stream_ = 11111;

};