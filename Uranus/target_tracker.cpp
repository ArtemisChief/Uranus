#include "target_tracker.hpp"

TargetTracker* TargetTracker::target_tracker_ = nullptr;

TargetTracker* TargetTracker::GetInstance() {
	if (target_tracker_ == nullptr)
		target_tracker_ = new TargetTracker();
	return target_tracker_;
}

TargetTracker::TargetTracker() {
	tracker_ = new KCFTracker(true, false, true, false);
	is_selected_ = false;
}

void TargetTracker::SelectTarget(const cv::Mat frame, const cv::Rect2d roi) {
	roi_ = roi;
	tracker_.init(roi_, frame);
	is_selected_ = true;
}

void TargetTracker::TrackTarget(const cv::Mat frame) {
	roi_ = tracker_.update(frame);
	rectangle(frame, roi_, cv::Scalar(0, 255, 0), 2);
	rectangle(frame, cv::Rect2d(roi_.x, roi_.y, 2, 2), cv::Scalar(0, 0, 255), 4);
	emit update_roi_signal(roi_);
}

void TargetTracker::ClearTarget() {
	tracker_ = new KCFTracker(true, false, true, false);
	is_selected_ = false;
}
