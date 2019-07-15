#include "target_tracker.hpp"

TargetTracker* TargetTracker::target_tracker_ = nullptr;

TargetTracker* TargetTracker::GetInstance() {
	if (target_tracker_ == nullptr)
		target_tracker_ = new TargetTracker();
	return target_tracker_;
}

TargetTracker::TargetTracker() {
	// ���ȸߣ��ٶȽ���
	//tracker_ = cv::TrackerCSRT::create();

	// �ٶȾ��Ƚ�Ϊ����
	// tracker_ = cv::TrackerKCF::create();
	tracker_ = new KCFTracker(true, false, true, false);
	// �ٶ���죬���Ȳ���
	// tracker_ = cv::TrackerMOSSE::create();
	is_selected_ = false;
}

void TargetTracker::SelectTarget(const cv::Mat frame, const double x, const double y, const double width, const double height) {
	roi_ = cv::Rect2d(x, y, width, height);
	tracker_.init( roi_, frame);
	is_selected_ = true;
}

void TargetTracker::TrackTarget(const cv::Mat frame) {
	roi_=tracker_.update(frame);
	rectangle(frame, roi_, cv::Scalar(0, 255, 0), 2, 1);
}

void TargetTracker::ClearTarget() {
	// tracker_.release();
	tracker_ = new KCFTracker(true, false, true, false);
	is_selected_ = false;
}
