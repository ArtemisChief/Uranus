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
	// ���Ʊ������Զ����ɵĿ������캯���͸�ֵ���캯��
	DISALLOW_COPY_AND_ASSIGN(Drone);

	// ���ơ�״̬����Ƶ���շ���UDP Socket
	QUdpSocket* socket_control_;
	QUdpSocket* socket_status_;
	QUdpSocket* socket_stream_;

	// ����ֵ������
	char* buf_control_;
	char* buf_status_;
	char* buf_stream_;

	// ���˻�IP��ַ�Լ����ơ�״̬����Ƶ���Ķ˿ڵ�ַ
	QString ip_drone_ = "192.168.10.1";
	int port_control_ = 8889;
	int port_status_ = 8890;
	int port_stream_ = 11111;

	// ���˻�״̬����
	int vgx_;		// X���ٶ�
	int vgy_;		// Y���ٶ�
	int vgz_;		// Z���ٶ�
	int agx_;		// X����ٶ�
	int agy_;		// Y����ٶ�
	int agz_;		// Z����ٶ�
	int battery_;	// ��ذٷֱ�
	int height_;	// �߶�
	int pitch_;		// �����Ƕ�
	int roll_;		// ����Ƕ�
	int yaw_;		// ƫ���Ƕ�
};