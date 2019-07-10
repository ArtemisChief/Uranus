#pragma once
#include <qobject.h>
#include <qudpsocket.h>

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName&);             \
    TypeName& operator=(const TypeName&)

class DroneControl : public QObject {

	Q_OBJECT

public:
	static DroneControl* GetInstance();

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

	bool get_is_connected() const;
	bool get_is_takeoff() const;
	bool get_is_streaming() const;

private:

	DroneControl();

	// ����
	static DroneControl* drone_control_;

	// ���Ʊ������Զ����ɵĿ������캯���͸�ֵ���캯��
	DISALLOW_COPY_AND_ASSIGN(DroneControl);

	// �շ����������UDP Socket
	QUdpSocket* socket_;

	// ����ֵ������
	char* buffer_;

	// ���˻�IP��ַ�Լ���������Զ�̶˿ڵ�ַ
	char* ip_drone_ = "192.168.10.1";
	int remote_port_control_ = 8889;

	// ״̬����ֵ
	bool is_connected_;
	bool is_takeoff_;
	bool is_streaming_;
};