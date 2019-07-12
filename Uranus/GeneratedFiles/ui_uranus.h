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
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UranusClass
{
public:
    QWidget *centralWidget;
    QLabel *frame_label;
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
    QLabel *speed_slider_label;
    QSlider *rc_factor_slider;
    QSlider *speed_slider;
    QLabel *rc_factor_slider_label;

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
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(1169, 250, 110, 150));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 235, 255, 30%);\n"
"border-radius:6px;"));
        agz_label = new QLabel(groupBox);
        agz_label->setObjectName(QString::fromUtf8("agz_label"));
        agz_label->setGeometry(QRect(10, 120, 111, 16));
        agz_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);\n"
"color: rgb(255, 255, 255);\n"
"font: 9pt \"Microsoft YaHei UI\";"));
        vgz_label = new QLabel(groupBox);
        vgz_label->setObjectName(QString::fromUtf8("vgz_label"));
        vgz_label->setGeometry(QRect(10, 50, 111, 16));
        vgz_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);\n"
"color: rgb(255, 255, 255);\n"
"font: 9pt \"Microsoft YaHei UI\";"));
        vgy_label = new QLabel(groupBox);
        vgy_label->setObjectName(QString::fromUtf8("vgy_label"));
        vgy_label->setGeometry(QRect(10, 30, 111, 16));
        vgy_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);\n"
"color: rgb(255, 255, 255);\n"
"font: 9pt \"Microsoft YaHei UI\";"));
        vgx_label = new QLabel(groupBox);
        vgx_label->setObjectName(QString::fromUtf8("vgx_label"));
        vgx_label->setGeometry(QRect(10, 10, 111, 16));
        vgx_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);\n"
"font: 9pt \"Microsoft YaHei UI\";\n"
"color: rgb(255, 255, 255);"));
        agx_label = new QLabel(groupBox);
        agx_label->setObjectName(QString::fromUtf8("agx_label"));
        agx_label->setGeometry(QRect(10, 80, 111, 16));
        agx_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);\n"
"color: rgb(255, 255, 255);\n"
"font: 9pt \"Microsoft YaHei UI\";"));
        agy_label = new QLabel(groupBox);
        agy_label->setObjectName(QString::fromUtf8("agy_label"));
        agy_label->setGeometry(QRect(10, 100, 111, 16));
        agy_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);\n"
"color: rgb(255, 255, 255);\n"
"font: 9pt \"Microsoft YaHei UI\";"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(-10, 220, 140, 240));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 235, 255, 30%);\n"
"border-radius:6px;"));
        baro_label = new QLabel(groupBox_2);
        baro_label->setObjectName(QString::fromUtf8("baro_label"));
        baro_label->setGeometry(QRect(20, 130, 111, 16));
        baro_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);\n"
"color: rgb(255, 255, 255);\n"
"font: 9pt \"Microsoft YaHei UI\";"));
        time_label = new QLabel(groupBox_2);
        time_label->setObjectName(QString::fromUtf8("time_label"));
        time_label->setGeometry(QRect(20, 200, 111, 16));
        time_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);\n"
"color: rgb(255, 255, 255);\n"
"font: 9pt \"Microsoft YaHei UI\";"));
        templ_label = new QLabel(groupBox_2);
        templ_label->setObjectName(QString::fromUtf8("templ_label"));
        templ_label->setGeometry(QRect(20, 180, 111, 16));
        templ_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);\n"
"color: rgb(255, 255, 255);\n"
"font: 9pt \"Microsoft YaHei UI\";"));
        temph_label = new QLabel(groupBox_2);
        temph_label->setObjectName(QString::fromUtf8("temph_label"));
        temph_label->setGeometry(QRect(20, 160, 111, 16));
        temph_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);\n"
"color: rgb(255, 255, 255);\n"
"font: 9pt \"Microsoft YaHei UI\";"));
        h_label = new QLabel(groupBox_2);
        h_label->setObjectName(QString::fromUtf8("h_label"));
        h_label->setGeometry(QRect(20, 90, 111, 16));
        h_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);\n"
"color: rgb(255, 255, 255);\n"
"font: 9pt \"Microsoft YaHei UI\";"));
        tof_label = new QLabel(groupBox_2);
        tof_label->setObjectName(QString::fromUtf8("tof_label"));
        tof_label->setGeometry(QRect(20, 110, 111, 16));
        tof_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);\n"
"color: rgb(255, 255, 255);\n"
"font: 9pt \"Microsoft YaHei UI\";"));
        pitch_label = new QLabel(groupBox_2);
        pitch_label->setObjectName(QString::fromUtf8("pitch_label"));
        pitch_label->setGeometry(QRect(20, 20, 111, 16));
        pitch_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);\n"
"color: rgb(255, 255, 255);\n"
"font: 9pt \"Microsoft YaHei UI\";"));
        yaw_label = new QLabel(groupBox_2);
        yaw_label->setObjectName(QString::fromUtf8("yaw_label"));
        yaw_label->setGeometry(QRect(20, 60, 111, 16));
        yaw_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);\n"
"color: rgb(255, 255, 255);\n"
"font: 9pt \"Microsoft YaHei UI\";"));
        roll_label = new QLabel(groupBox_2);
        roll_label->setObjectName(QString::fromUtf8("roll_label"));
        roll_label->setGeometry(QRect(20, 40, 111, 16));
        roll_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);\n"
"color: rgb(255, 255, 255);\n"
"font: 9pt \"Microsoft YaHei UI\";"));
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
        groupBox_3->setGeometry(QRect(510, 0, 251, 61));
        groupBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 235, 255, 30%);\n"
"border-radius:6px;"));
        battery_bar = new QProgressBar(groupBox_3);
        battery_bar->setObjectName(QString::fromUtf8("battery_bar"));
        battery_bar->setGeometry(QRect(50, 10, 155, 20));
        battery_bar->setStyleSheet(QString::fromUtf8(""));
        battery_bar->setValue(100);
        battery_bar->setTextVisible(false);
        speed_label = new QLabel(groupBox_3);
        speed_label->setObjectName(QString::fromUtf8("speed_label"));
        speed_label->setGeometry(QRect(80, 40, 121, 16));
        speed_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);\n"
"color: rgb(255, 255, 255);\n"
"font: 9pt \"Microsoft YaHei UI\";"));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(390, 680, 501, 41));
        groupBox_4->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 235, 255, 30%);\n"
"border-radius:6px"));
        speed_slider_label = new QLabel(groupBox_4);
        speed_slider_label->setObjectName(QString::fromUtf8("speed_slider_label"));
        speed_slider_label->setGeometry(QRect(270, 10, 51, 15));
        speed_slider_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);\n"
"color: rgb(255, 255, 255);\n"
"font: 9pt \"Microsoft YaHei UI\";"));
        rc_factor_slider = new QSlider(groupBox_4);
        rc_factor_slider->setObjectName(QString::fromUtf8("rc_factor_slider"));
        rc_factor_slider->setGeometry(QRect(60, 10, 160, 15));
        rc_factor_slider->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);"));
        rc_factor_slider->setMaximum(100);
        rc_factor_slider->setValue(50);
        rc_factor_slider->setOrientation(Qt::Horizontal);
        rc_factor_slider->setTickPosition(QSlider::NoTicks);
        speed_slider = new QSlider(groupBox_4);
        speed_slider->setObjectName(QString::fromUtf8("speed_slider"));
        speed_slider->setGeometry(QRect(320, 10, 160, 15));
        speed_slider->setStyleSheet(QString::fromUtf8("background-color: rgb(131, 131, 131, 0%);"));
        speed_slider->setMinimum(10);
        speed_slider->setMaximum(100);
        speed_slider->setValue(55);
        speed_slider->setOrientation(Qt::Horizontal);
        rc_factor_slider_label = new QLabel(groupBox_4);
        rc_factor_slider_label->setObjectName(QString::fromUtf8("rc_factor_slider_label"));
        rc_factor_slider_label->setGeometry(QRect(20, 10, 51, 15));
        rc_factor_slider_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);\n"
"color: rgb(255, 255, 255);\n"
"font: 9pt \"Microsoft YaHei UI\";"));
        UranusClass->setCentralWidget(centralWidget);

        retranslateUi(UranusClass);

        QMetaObject::connectSlotsByName(UranusClass);
    } // setupUi

    void retranslateUi(QMainWindow *UranusClass)
    {
        UranusClass->setWindowTitle(QApplication::translate("UranusClass", "Uranus", nullptr));
        frame_label->setText(QApplication::translate("UranusClass", "                   TextLabel", nullptr));
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
        speed_slider_label->setText(QApplication::translate("UranusClass", "Speed", nullptr));
        rc_factor_slider_label->setText(QApplication::translate("UranusClass", "Stick", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UranusClass: public Ui_UranusClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_URANUS_H
