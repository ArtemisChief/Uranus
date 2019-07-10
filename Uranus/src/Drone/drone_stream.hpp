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

	// ����
	static DroneStream* drone_stream_;

	// ���Ʊ������Զ����ɵĿ������캯���͸�ֵ���캯��
	DISALLOW_COPY_AND_ASSIGN(DroneStream);

	// �շ���Ƶ����UDP Socket
	QUdpSocket* socket_;

	// ����ֵ������
	char* buffer_;

	// ���˻�IP��ַ�Լ���Ƶ�����ؽ��ն˿ڵ�ַ
	char* ip_drone_ = "192.168.10.1";
	int local_port_stream_ = 11111;

};