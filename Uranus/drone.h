#pragma once
#include <qobject.h>
#include <qudpsocket.h>

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName&);             \
    TypeName& operator=(const TypeName&)

class Drone : public QObject {

	Q_OBJECT

public:
	static Drone* GetInstance();

	// 连接
	bool Connect();

	// 起飞、降落
	bool Takeoff();
	bool Land();

	// 向一个方向直线移动一定距离，distance范围20-500（cm）
	void MoveForward(const int distance) const;
	void MoveBackward(const int distance) const;
	void MoveLeft(const int distance) const;
	void MoveRight(int distance) const;
	void MoveUp(const int distance) const;
	void MoveDown(const int distance) const;

	// 旋转方向，degree范围1-3600（度）
	void RotateLeft(const int degree) const;
	void RotateRight(const int degree) const;

	// 翻滚，参数为字符，'l' - left，'r' - right，'f' - forward，'b' - back，
	void Flip(const char direction) const;

	// 设置杆量，参数分别为横滚、俯仰、油门、偏航，范围均为（-100，100）
	void SetRC(const int roll, const int pitch, const int throttle, const int yaw) const;

	// 设置飞行速度，value范围10-100（cm/s）
	bool SetSpeed(const int value) const;

	// 打开、关闭视频流
	bool OpenStream();
	bool CloseStream();

	int get_pitch() const;
	int get_roll() const;
	int get_yaw() const;
	int get_vgx() const;
	int get_vgy() const;
	int get_vgz() const;
	int get_templ() const;
	int get_temph() const;
	int get_tof() const;
	int get_height() const;
	int get_battery() const;
	int get_baro() const;
	int get_time() const;
	int get_agx() const;
	int get_agy() const;
	int get_agz() const;

	bool get_is_connected() const;
	bool get_is_takeoff() const;
	bool get_is_streaming() const;

private slots:
	void receive_and_update_status();

private:
	Drone();

	// 单例
	static Drone* drone_;

	// 限制编译器自动生成的拷贝构造函数和赋值构造函数
	DISALLOW_COPY_AND_ASSIGN(Drone);

	// 控制、状态、视频流收发的UDP Socket
	QUdpSocket* socket_control_;
	QUdpSocket* socket_status_;
	QUdpSocket* socket_stream_;

	// 返回值缓存区
	char* buf_control_;
	char* buf_status_;

	// 无人机IP地址以及控制、状态、视频流的端口地址
	char* ip_drone_ = "192.168.10.1";
	int remote_port_control_ = 8889;
	int local_port_status_ = 8890;
	int local_port_stream_ = 11111;

	// 无人机状态参数数组
	// 0 - 俯仰角度，度数
	// 1 - 横滚角度，度数
	// 2 - 偏航角度，度数
	// 3 - X轴速度，厘米每秒
	// 4 - Y轴速度，厘米每秒
	// 5 - Z轴速度，厘米每秒
	// 6 - 主板最低温度，摄氏度
	// 7 - 主板最高温度，摄氏度
	// 8 - ToF测距距离，厘米
	// 9 - 相对高度，米
	// 10 - 电量，%
	// 11 - 气压计高度，米
	// 12 - 电机运转时间，秒
	// 13 - X轴加速度，厘米每二次方秒
	// 14 - Y轴加速度，厘米每二次方秒
	// 15 - Z轴加速度，厘米每二次方秒
	int params_[16] = { 0 };

	// 状态布尔值
	bool is_connected_;
	bool is_takeoff_;
	bool is_streaming_;
};