#pragma once
#include <qobject.h>
#include <qudpsocket.h>

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName&);             \
    TypeName& operator=(const TypeName&)

class Drone : public QObject {

	Q_OBJECT

public:
	Drone();

	void Takeoff() const;
	void Land() const;
	void MoveForward(const int distance) const;
	void MoveBackward(const int distance) const;
	void MoveLeft(const int distance) const;
	void MoveRight(int distance) const;
	void MoveUp(const int distance) const;
	void MoveDown(const int distance) const;
	void RotateLeft(const int degree) const;
	void RotateRight(const int degree) const;
	void SetSpeed(const int value) const;

	void OpenStream() const;
	void CloseStream() const;

	inline int get_vgx() const;
	inline int get_vgy() const;
	inline int get_vgz() const;
	inline int get_agx() const;
	inline int get_agy() const;
	inline int get_agz() const;
	inline int get_battery() const;
	inline int get_height() const;
	inline int get_pitch() const;
	inline int get_roll() const;
	inline int get_yaw() const;

private:
	// 限制编译器自动生成的拷贝构造函数和赋值构造函数
	DISALLOW_COPY_AND_ASSIGN(Drone);

	// 控制、状态、视频流收发的UDP Socket
	QUdpSocket* socket_control_;
	QUdpSocket* socket_status_;
	QUdpSocket* socket_stream_;

	// 返回值缓存区
	char* buf_control_;
	char* buf_status_;
	char* buf_stream_;

	// 无人机IP地址以及控制、状态、视频流的端口地址
	QString ip_drone_ = "192.168.10.1";
	int port_control_ = 8889;
	int port_status_ = 8890;
	int port_stream_ = 11111;

	// 无人机状态参数
	int vgx_;		// X轴速度
	int vgy_;		// Y轴速度
	int vgz_;		// Z轴速度
	int agx_;		// X轴加速度
	int agy_;		// Y轴加速度
	int agz_;		// Z轴加速度
	int battery_;	// 电池百分比
	int height_;	// 高度
	int pitch_;		// 俯仰角度
	int roll_;		// 横滚角度
	int yaw_;		// 偏航角度
};