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
#include <QtWidgets/QGroupBox>
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
    QPushButton *connect_btn;
    QGroupBox *groupBox;
    QLabel *agz_label;
    QLabel *vgz_label;
    QLabel *vgy_label;
    QLabel *vgx_label;
    QLabel *agx_label;
    QLabel *agy_label;
    QGroupBox *groupBox_2;
    QLabel *baro_label;
    QLabel *time_label;
    QLabel *templ_label;
    QLabel *temph_label;
    QLabel *h_label;
    QLabel *tof_label;
    QLabel *pitch_label;
    QLabel *yaw_label;
    QLabel *roll_label;
    QGroupBox *groupBox_3;
    QProgressBar *battery_bar;
    QLabel *speed_label;
    QGroupBox *groupBox_4;
    QLabel *speed_factor;
    QSlider *rc_factor_slider;
    QSlider *speed_slider;
    QLabel *rc_factorlabel;

    void setupUi(QMainWindow *UranusClass)
    {
        if (UranusClass->objectName().isEmpty())
            UranusClass->setObjectName(QString::fromUtf8("UranusClass"));
        UranusClass->resize(1280, 720);
        UranusClass->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(UranusClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame_label = new QLabel(centralWidget);
        frame_label->setObjectName(QString::fromUtf8("frame_label"));
        frame_label->setGeometry(QRect(0, 0, 1280, 720));
        frame_label->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        connect_btn = new QPushButton(centralWidget);
        connect_btn->setObjectName(QString::fromUtf8("connect_btn"));
        connect_btn->setGeometry(QRect(10, 610, 100, 100));
        connect_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);\n"
"border:10px solid;\n"
"border-color: rgb(85, 255, 127, 50%);\n"
"border-radius:50%;"));
        connect_btn->setCheckable(false);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(1150, 190, 130, 151));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 20%);\n"
"border-radius:10px;"));
        agz_label = new QLabel(groupBox);
        agz_label->setObjectName(QString::fromUtf8("agz_label"));
        agz_label->setGeometry(QRect(10, 120, 111, 16));
        agz_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);"));
        vgz_label = new QLabel(groupBox);
        vgz_label->setObjectName(QString::fromUtf8("vgz_label"));
        vgz_label->setGeometry(QRect(10, 50, 111, 16));
        vgz_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);"));
        vgy_label = new QLabel(groupBox);
        vgy_label->setObjectName(QString::fromUtf8("vgy_label"));
        vgy_label->setGeometry(QRect(10, 30, 111, 16));
        vgy_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);"));
        vgx_label = new QLabel(groupBox);
        vgx_label->setObjectName(QString::fromUtf8("vgx_label"));
        vgx_label->setGeometry(QRect(10, 10, 111, 16));
        vgx_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);"));
        agx_label = new QLabel(groupBox);
        agx_label->setObjectName(QString::fromUtf8("agx_label"));
        agx_label->setGeometry(QRect(10, 80, 111, 16));
        agx_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);"));
        agy_label = new QLabel(groupBox);
        agy_label->setObjectName(QString::fromUtf8("agy_label"));
        agy_label->setGeometry(QRect(10, 100, 111, 16));
        agy_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(-10, 160, 141, 240));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 20%);\n"
"border-radius:10px;"));
        baro_label = new QLabel(groupBox_2);
        baro_label->setObjectName(QString::fromUtf8("baro_label"));
        baro_label->setGeometry(QRect(20, 130, 111, 16));
        baro_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);"));
        time_label = new QLabel(groupBox_2);
        time_label->setObjectName(QString::fromUtf8("time_label"));
        time_label->setGeometry(QRect(20, 200, 111, 16));
        time_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);"));
        templ_label = new QLabel(groupBox_2);
        templ_label->setObjectName(QString::fromUtf8("templ_label"));
        templ_label->setGeometry(QRect(20, 180, 111, 16));
        templ_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);"));
        temph_label = new QLabel(groupBox_2);
        temph_label->setObjectName(QString::fromUtf8("temph_label"));
        temph_label->setGeometry(QRect(20, 160, 111, 16));
        temph_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);"));
        h_label = new QLabel(groupBox_2);
        h_label->setObjectName(QString::fromUtf8("h_label"));
        h_label->setGeometry(QRect(20, 90, 111, 16));
        h_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);"));
        tof_label = new QLabel(groupBox_2);
        tof_label->setObjectName(QString::fromUtf8("tof_label"));
        tof_label->setGeometry(QRect(20, 110, 111, 16));
        tof_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);"));
        pitch_label = new QLabel(groupBox_2);
        pitch_label->setObjectName(QString::fromUtf8("pitch_label"));
        pitch_label->setGeometry(QRect(20, 20, 111, 16));
        pitch_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);"));
        yaw_label = new QLabel(groupBox_2);
        yaw_label->setObjectName(QString::fromUtf8("yaw_label"));
        yaw_label->setGeometry(QRect(20, 60, 111, 16));
        yaw_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);"));
        roll_label = new QLabel(groupBox_2);
        roll_label->setObjectName(QString::fromUtf8("roll_label"));
        roll_label->setGeometry(QRect(20, 40, 111, 16));
        roll_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);"));
        baro_label->raise();
        time_label->raise();
        temph_label->raise();
        h_label->raise();
        tof_label->raise();
        templ_label->raise();
        pitch_label->raise();
        yaw_label->raise();
        roll_label->raise();
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(440, 0, 360, 60));
        groupBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 20%);\n"
"border-radius:10px;"));
        battery_bar = new QProgressBar(groupBox_3);
        battery_bar->setObjectName(QString::fromUtf8("battery_bar"));
        battery_bar->setGeometry(QRect(60, 20, 118, 23));
        battery_bar->setStyleSheet(QString::fromUtf8(""));
        battery_bar->setValue(24);
        speed_label = new QLabel(groupBox_3);
        speed_label->setObjectName(QString::fromUtf8("speed_label"));
        speed_label->setGeometry(QRect(200, 20, 141, 16));
        speed_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);"));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(350, 660, 530, 60));
        groupBox_4->setStyleSheet(QString::fromUtf8("background-color: rgb(131, 131, 131, 80%);\n"
"border-radius:10%"));
        speed_factor = new QLabel(groupBox_4);
        speed_factor->setObjectName(QString::fromUtf8("speed_factor"));
        speed_factor->setGeometry(QRect(290, 20, 51, 16));
        speed_factor->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);"));
        rc_factor_slider = new QSlider(groupBox_4);
        rc_factor_slider->setObjectName(QString::fromUtf8("rc_factor_slider"));
        rc_factor_slider->setGeometry(QRect(80, 20, 161, 20));
        rc_factor_slider->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);"));
        rc_factor_slider->setMaximum(100);
        rc_factor_slider->setValue(50);
        rc_factor_slider->setOrientation(Qt::Horizontal);
        rc_factor_slider->setTickPosition(QSlider::NoTicks);
        speed_slider = new QSlider(groupBox_4);
        speed_slider->setObjectName(QString::fromUtf8("speed_slider"));
        speed_slider->setGeometry(QRect(350, 20, 161, 20));
        speed_slider->setStyleSheet(QString::fromUtf8("background-color: rgb(131, 131, 131, 0%);"));
        speed_slider->setMinimum(10);
        speed_slider->setMaximum(100);
        speed_slider->setValue(55);
        speed_slider->setOrientation(Qt::Horizontal);
        rc_factorlabel = new QLabel(groupBox_4);
        rc_factorlabel->setObjectName(QString::fromUtf8("rc_factorlabel"));
        rc_factorlabel->setGeometry(QRect(20, 20, 51, 20));
        rc_factorlabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);"));
        UranusClass->setCentralWidget(centralWidget);
        frame_label->raise();
        groupBox->raise();
        groupBox_2->raise();
        groupBox_3->raise();
        connect_btn->raise();
        groupBox_4->raise();

        retranslateUi(UranusClass);
        QObject::connect(rc_factor_slider, SIGNAL(valueChanged(int)), UranusClass, SLOT(on_stick_slider_value_changed(int)));
        QObject::connect(speed_slider, SIGNAL(valueChanged(int)), UranusClass, SLOT(on_speed_slider_value_changed(int)));

        QMetaObject::connectSlotsByName(UranusClass);
    } // setupUi

    void retranslateUi(QMainWindow *UranusClass)
    {
        UranusClass->setWindowTitle(QApplication::translate("UranusClass", "Uranus", nullptr));
        frame_label->setText(QApplication::translate("UranusClass", "                   TextLabel", nullptr));
        connect_btn->setText(QApplication::translate("UranusClass", "Connect", nullptr));
        groupBox->setTitle(QString());
        agz_label->setText(QApplication::translate("UranusClass", "agz: 0g", nullptr));
        vgz_label->setText(QApplication::translate("UranusClass", "vgz: 0cm/s", nullptr));
        vgy_label->setText(QApplication::translate("UranusClass", "vgy: 0cm/s", nullptr));
        vgx_label->setText(QApplication::translate("UranusClass", "vgx: 0cm/s", nullptr));
        agx_label->setText(QApplication::translate("UranusClass", "agx: 0g", nullptr));
        agy_label->setText(QApplication::translate("UranusClass", "agy: 0g", nullptr));
        groupBox_2->setTitle(QString());
        baro_label->setText(QApplication::translate("UranusClass", "baro: 0cm", nullptr));
        time_label->setText(QApplication::translate("UranusClass", "time: 0s", nullptr));
        templ_label->setText(QApplication::translate("UranusClass", "templ: 0\302\260C", nullptr));
        temph_label->setText(QApplication::translate("UranusClass", "temph: 0\302\260C", nullptr));
        h_label->setText(QApplication::translate("UranusClass", "h: 0cm", nullptr));
        tof_label->setText(QApplication::translate("UranusClass", "tof: 0cm", nullptr));
        pitch_label->setText(QApplication::translate("UranusClass", "pitch: 0\302\260", nullptr));
        yaw_label->setText(QApplication::translate("UranusClass", "yaw: 0\302\260", nullptr));
        roll_label->setText(QApplication::translate("UranusClass", "roll: 0\302\260", nullptr));
        groupBox_3->setTitle(QString());
        speed_label->setText(QApplication::translate("UranusClass", "Speed: 0.0m/s", nullptr));
        groupBox_4->setTitle(QString());
        speed_factor->setText(QApplication::translate("UranusClass", "Speed", nullptr));
        rc_factorlabel->setText(QApplication::translate("UranusClass", "Stick", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UranusClass: public Ui_UranusClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_URANUS_H
