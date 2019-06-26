#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_uranus.h"

class Uranus : public QMainWindow
{
	Q_OBJECT

public:
	Uranus(QWidget *parent = Q_NULLPTR);

private:
	Ui::UranusClass ui;
};
