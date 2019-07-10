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

	// ����
	bool Connect();

	// ��ɡ�����
	bool Takeoff();
	bool Land();

	// ��һ������ֱ���ƶ�һ�����룬distance��Χ20-500��cm��
	void MoveForward(const int distance) const;
	void MoveBackward(const int distance) const;
	void MoveLeft(const int distance) const;
	void MoveRight(int distance) const;
	void MoveUp(const int distance) const;
	void MoveDown(const int distance) const;

	// ��ת����degree��Χ1-3600���ȣ�
	void RotateLeft(const int degree) const;
	void RotateRight(const int degree) const;

	// ����������Ϊ�ַ���'l' - left��'r' - right��'f' - forward��'b' - back��
	void Flip(const char direction) const;

	// ���ø����������ֱ�Ϊ��������������š�ƫ������Χ��Ϊ��-100��100��
	void SetRC(const int roll, const int pitch, const int throttle, const int yaw) const;

	// ���÷����ٶȣ�value��Χ10-100��cm/s��
	bool SetSpeed(const int value) const;

	// �򿪡��ر���Ƶ��
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

	// ����
	static Drone* drone_;

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
	int params_[16] = { 0 };

	// ״̬����ֵ
	bool is_connected_;
	bool is_takeoff_;
	bool is_streaming_;
};