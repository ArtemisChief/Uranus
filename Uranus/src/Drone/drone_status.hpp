#pragma once
#include <qobject.h>
#include <qudpsocket.h>

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

	DroneStatus();

	// ����
	static DroneStatus* drone_status_;

	// ���Ʊ������Զ����ɵĿ������캯���͸�ֵ���캯��
	DISALLOW_COPY_AND_ASSIGN(DroneStatus);

	// �շ�״ֵ̬��UDP Socket
	QUdpSocket* socket_;

	// ����ֵ������
	char* buffer_;

	// ���˻�״ֵ̬���ؽ��ն˿ڵ�ַ
	int local_port_status_ = 8890;



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

private slots:
	//�����˻���ȡ״̬��Ϣ������params_[]��������update_status�ź�
	void ReceiveStatus();
signals:
	void update_states(int* params);
	void show_buffer(QString qs);
		
};