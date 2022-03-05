#pragma once
#include <QObject>
#include <opencv2/opencv.hpp>
#include "src/Utils/kcftracker.hpp"

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName&);             \
    TypeName& operator=(const TypeName&)

class TargetTracker : public QObject {
	Q_OBJECT

public:

	static TargetTracker* GetInstance();

	// x, y 为矩形框左上角
	void SelectTarget(const cv::Mat frame, const cv::Rect2d roi);

	void TrackTarget(const cv::Mat frame);

	void ClearTarget();

private:

	// 限制编译器自动生成的拷贝构造函数和赋值构造函数
	DISALLOW_COPY_AND_ASSIGN(TargetTracker);

	// 构造函数
	TargetTracker();

	// 单例
	static TargetTracker* target_tracker_;

	cv::Rect2d roi_;
	KCFTracker tracker_;

	bool is_selected_;

signals:

	void update_roi_signal(cv::Rect2d roi);

};
