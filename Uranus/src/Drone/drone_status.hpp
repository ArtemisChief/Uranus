#pragma once
#include <qobject.h>
#include <qudpsocket.h>

#define LOCAL_PORT_STATUS 8890

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName&);             \
    TypeName& operator=(const TypeName&)

class DroneStatus : public QObject {

	Q_OBJECT

public:
	static DroneStatus* GetInstance();

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

private:

	// 限制编译器自动生成的拷贝构造函数和赋值构造函数
	DISALLOW_COPY_AND_ASSIGN(DroneStatus);

	// 构造函数
	DroneStatus();

	// 单例
	static DroneStatus* drone_status_;

	// 收发状态值的UDP Socket
	QUdpSocket* socket_;

	// 返回值缓存区
	char* buffer_;

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

private slots:
	//从无人机获取状态信息，存入params_[]，并发出update_status信号
	void ReceiveStatus();
signals:
	void update_states(int* params);
		
};