#include "object_tracker.hpp"

ObjectTracker* ObjectTracker::object_tracker_ = nullptr;

ObjectTracker* ObjectTracker::GetInstance() {
	if (object_tracker_ == nullptr)
		object_tracker_ = new ObjectTracker();
	return object_tracker_;
}

ObjectTracker::ObjectTracker() {

}


ObjectTracker::~ObjectTracker() {

}

