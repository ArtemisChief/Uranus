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

	// 限制编译器自动生成的拷贝构造函数和赋值构造函数
	DISALLOW_COPY_AND_ASSIGN(ObjectTracker);

	// 构造与析构函数
	ObjectTracker();
	~ObjectTracker();

	// 单例
	static ObjectTracker* object_tracker_;

	cv::Rect2d roi;

};
