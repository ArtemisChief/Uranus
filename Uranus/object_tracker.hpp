#pragma once
#include <QObject>
#include <opencv2/core/mat.hpp>

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName&);             \
    TypeName& operator=(const TypeName&)

class ObjectTracker : public QObject
{
	Q_OBJECT

public:

	static ObjectTracker* GetInstance();

private:

	// ���Ʊ������Զ����ɵĿ������캯���͸�ֵ���캯��
	DISALLOW_COPY_AND_ASSIGN(ObjectTracker);

	// ��������������
	ObjectTracker();
	~ObjectTracker();

	// ����
	static ObjectTracker* object_tracker_;

	cv::Rect2d roi;

};
