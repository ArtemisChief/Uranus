#pragma once
#include <qobject.h>
#include <QImage>
#include <qudpsocket.h>

#define LOCAL_PORT_STREAM 11111

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName&);             \
    TypeName& operator=(const TypeName&)

class DroneStream : public QObject {

	Q_OBJECT

public:

	static DroneStream* GetInstance();

private:

	// ���Ʊ������Զ����ɵĿ������캯���͸�ֵ���캯��
	DISALLOW_COPY_AND_ASSIGN(DroneStream);

	// ��������������
	DroneStream();
	~DroneStream();

	// ����
	static DroneStream* drone_stream_;

	// �շ���Ƶ����UDP Socket
	QUdpSocket* socket_;

	// ���ڴ洢һ�����Ļ���
	QByteArray datagram_buffer_;

	// ���ڻ���һ֡�Ļ�����
	QByteArray frame_buffer_;

private slots:

	void ReceiveDatagram();

signals:

	void construct_frame_signal(QByteArray& bytes);

};