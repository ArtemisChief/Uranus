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
	//tracker_ = cv::TrackerKCF::create();
	
	// �ٶ���죬���Ȳ���
	tracker_ = cv::TrackerMOSSE::create();
	is_selected_ = false;
}

void TargetTracker::SelectTarget(const cv::Mat frame, const double x, const double y, const double width, const double height) {
	roi_ = cv::Rect2d(x, y, width, height);
	tracker_->init(frame, roi_);
	is_selected_ = true;
}

void TargetTracker::TrackTarget(const cv::Mat frame) {
	tracker_->update(frame, roi_);
	rectangle(frame, roi_, cv::Scalar(0, 255, 0), 2, 1);
}

void TargetTracker::ClearTarget() {
	tracker_.release();
	tracker_ = cv::TrackerMOSSE::create();
	is_selected_ = false;
}
