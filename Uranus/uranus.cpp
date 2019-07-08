#include "uranus.h"

using namespace cv;
using namespace std;

Uranus::Uranus(QWidget *parent) : QMainWindow(parent) {
	ui.setupUi(this);
}

void Uranus::on_connectBtn_clicked() {
	if (drone_ != nullptr)
		drone_ = new Drone();
}


void Uranus::on_takeoffBtn_clicked() {
	drone_->Takeoff();
}

void Uranus::on_landBtn_clicked() {
	drone_->Land();
}
