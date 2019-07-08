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

	bool Connect() const;

	bool Takeoff() const;
	bool Land() const;
	void MoveForward(const int distance) const;
	void MoveBackward(const int distance) const;
	void MoveLeft(const int distance) const;
	void MoveRight(int distance) const;
	void MoveUp(const int distance) const;
	void MoveDown(const int distance) const;
	void RotateLeft(const int degree) const;
	void RotateRight(const int degree) const;
	bool SetSpeed(const int value) const;

	bool OpenStream() const;
	bool CloseStream() const;

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

private slots:
	void receive_and_update_status();

private:
	// ���Ʊ������Զ����ɵĿ������캯���͸�ֵ���캯��
	DISALLOW_COPY_AND_ASSIGN(Drone);

	// ���ơ�״̬����Ƶ���շ���UDP Socket
	QUdpSocket* socket_control_;
	QUdpSocket* socket_status_;
	QUdpSocket* socket_stream_;

	// ����ֵ������
	char* buf_control_;
	char* buf_status_;

	// ���˻�IP��ַ�Լ����ơ�״̬����Ƶ���Ķ˿ڵ�ַ
	char* ip_drone_ = "192.168.10.1";
	int remote_port_control_ = 8889;
	int local_port_status_ = 8890;
	int local_port_stream_ = 11111;

	// ���˻�״̬��������
	// 0 - �����Ƕȣ�����
	// 1 - ����Ƕȣ�����
	// 2 - ƫ���Ƕȣ�����
	// 3 - X���ٶȣ�����ÿ��
	// 4 - Y���ٶȣ�����ÿ��
	// 5 - Z���ٶȣ�����ÿ��
	// 6 - ��������¶ȣ����϶�
	// 7 - ��������¶ȣ����϶�
	// 8 - ToF�����룬����
	// 9 - ��Ը߶ȣ���
	// 10 - ������%
	// 11 - ��ѹ�Ƹ߶ȣ���
	// 12 - �����תʱ�䣬��
	// 13 - X����ٶȣ�����ÿ���η���
	// 14 - Y����ٶȣ�����ÿ���η���
	// 15 - Z����ٶȣ�����ÿ���η���
	int params_[16];

};