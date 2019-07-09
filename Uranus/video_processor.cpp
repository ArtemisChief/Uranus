#include "video_processor.h"
#include <opencv2/imgproc/types_c.h>

void VideoProcessor::get_frame(char* url) {
	capture_.open(url);
	capture_.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'));
	capture_.set(cv::CAP_PROP_FRAME_WIDTH, 1920);
	capture_.set(cv::CAP_PROP_FRAME_HEIGHT, 1080);

	while (true) {
		if(!capture_.grab())
			continue;
		capture_.retrieve(frame_);

		resize(frame_, frame_, cv::Size(1280, 720));

		cvtColor(frame_, frame_, CV_BGR2RGB);
		image_ = new QImage(static_cast<const uchar *>(frame_.data), frame_.cols, frame_.rows, frame_.step, QImage::Format_RGB888);
		image_->bits();

		emit pass_frame(image_);
	}
}
