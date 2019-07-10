/********************************************************************************
** Form generated from reading UI file 'uranus.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_URANUS_H
#define UI_URANUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UranusClass
{
public:
    QWidget *centralWidget;
    QLabel *frame_label;
    QLabel *buffer_label;
    QPushButton *connect_btn;
    QSlider *rc_factor_slider;
    QSlider *speed_slider;
    QLabel *rc_factorlabel;
    QLabel *speed_factor;
    QProgressBar *battery_bar;
    QLabel *speed_label;
    QLabel *height_label;

    void setupUi(QMainWindow *UranusClass)
    {
        if (UranusClass->objectName().isEmpty())
            UranusClass->setObjectName(QString::fromUtf8("UranusClass"));
        UranusClass->resize(1200, 675);
        centralWidget = new QWidget(UranusClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame_label = new QLabel(centralWidget);
        frame_label->setObjectName(QString::fromUtf8("frame_label"));
        frame_label->setGeometry(QRect(30, 20, 960, 540));
        buffer_label = new QLabel(centralWidget);
        buffer_label->setObjectName(QString::fromUtf8("buffer_label"));
        buffer_label->setGeometry(QRect(30, 610, 521, 41));
        connect_btn = new QPushButton(centralWidget);
        connect_btn->setObjectName(QString::fromUtf8("connect_btn"));
        connect_btn->setGeometry(QRect(1020, 40, 158, 23));
        rc_factor_slider = new QSlider(centralWidget);
        rc_factor_slider->setObjectName(QString::fromUtf8("rc_factor_slider"));
        rc_factor_slider->setGeometry(QRect(1050, 150, 22, 160));
        rc_factor_slider->setMaximum(100);
        rc_factor_slider->setValue(50);
        rc_factor_slider->setOrientation(Qt::Vertical);
        rc_factor_slider->setTickPosition(QSlider::NoTicks);
        speed_slider = new QSlider(centralWidget);
        speed_slider->setObjectName(QString::fromUtf8("speed_slider"));
        speed_slider->setGeometry(QRect(1110, 150, 22, 160));
        speed_slider->setMinimum(10);
        speed_slider->setMaximum(100);
        speed_slider->setValue(55);
        speed_slider->setOrientation(Qt::Vertical);
        rc_factorlabel = new QLabel(centralWidget);
        rc_factorlabel->setObjectName(QString::fromUtf8("rc_factorlabel"));
        rc_factorlabel->setGeometry(QRect(1050, 320, 31, 16));
        speed_factor = new QLabel(centralWidget);
        speed_factor->setObjectName(QString::fromUtf8("speed_factor"));
        speed_factor->setGeometry(QRect(1110, 320, 31, 16));
        battery_bar = new QProgressBar(centralWidget);
        battery_bar->setObjectName(QString::fromUtf8("battery_bar"));
        battery_bar->setGeometry(QRect(210, 30, 118, 23));
        battery_bar->setValue(24);
        speed_label = new QLabel(centralWidget);
        speed_label->setObjectName(QString::fromUtf8("speed_label"));
        speed_label->setGeometry(QRect(350, 30, 121, 16));
        height_label = new QLabel(centralWidget);
        height_label->setObjectName(QString::fromUtf8("height_label"));
        height_label->setGeometry(QRect(480, 30, 111, 16));
        UranusClass->setCentralWidget(centralWidget);

        retranslateUi(UranusClass);
        QObject::connect(connect_btn, SIGNAL(clicked()), UranusClass, SLOT(on_connect_btn_clicked()));
        QObject::connect(rc_factor_slider, SIGNAL(valueChanged(int)), UranusClass, SLOT(on_stick_slider_value_changed(int)));
        QObject::connect(speed_slider, SIGNAL(valueChanged(int)), UranusClass, SLOT(on_speed_slider_value_changed(int)));

        QMetaObject::connectSlotsByName(UranusClass);
    } // setupUi

    void retranslateUi(QMainWindow *UranusClass)
    {
        UranusClass->setWindowTitle(QApplication::translate("UranusClass", "Uranus", nullptr));
        frame_label->setText(QApplication::translate("UranusClass", "TextLabel", nullptr));
        buffer_label->setText(QApplication::translate("UranusClass", "TextLabel", nullptr));
        connect_btn->setText(QApplication::translate("UranusClass", "Connect to Tello", nullptr));
        rc_factorlabel->setText(QApplication::translate("UranusClass", "Stick", nullptr));
        speed_factor->setText(QApplication::translate("UranusClass", "Speed", nullptr));
        speed_label->setText(QApplication::translate("UranusClass", "Speed: 0.0m/s", nullptr));
        height_label->setText(QApplication::translate("UranusClass", "Height: 0.0m", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UranusClass: public Ui_UranusClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_URANUS_H
