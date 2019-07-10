#include "uranus.hpp"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Uranus w;
	w.show();
	return a.exec();
}
