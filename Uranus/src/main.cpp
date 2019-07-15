#include "uranus.hpp"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	qRegisterMetaType<QByteArray>("QByteArray&");
	qRegisterMetaType<cv::Rect2d>("cv::Rect2d");
	QApplication a(argc, argv);
	Uranus w;
	w.show();
	return a.exec();
}
