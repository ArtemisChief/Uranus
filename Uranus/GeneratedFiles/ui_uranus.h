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
    QLabel *buffer_label;
    QPushButton *connect_btn;
    QSlider *rc_factor_slider;
    QSlider *speed_slider;
    QLabel *rc_factorlabel;
    QLabel *speed_factor;
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
        buffer_label->setGeometry(QRect(30, 610, 1081, 41));
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
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(860, 140, 130, 240));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 20%);\n"
"border: 0px solid;"));
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
        groupBox_2->setGeometry(QRect(30, 140, 130, 240));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 20%);\n"
"border: 0px solid;"));
        baro_label = new QLabel(groupBox_2);
        baro_label->setObjectName(QString::fromUtf8("baro_label"));
        baro_label->setGeometry(QRect(10, 130, 111, 16));
        baro_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);"));
        time_label = new QLabel(groupBox_2);
        time_label->setObjectName(QString::fromUtf8("time_label"));
        time_label->setGeometry(QRect(10, 200, 111, 16));
        time_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);"));
        templ_label = new QLabel(groupBox_2);
        templ_label->setObjectName(QString::fromUtf8("templ_label"));
        templ_label->setGeometry(QRect(10, 180, 111, 16));
        templ_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);"));
        temph_label = new QLabel(groupBox_2);
        temph_label->setObjectName(QString::fromUtf8("temph_label"));
        temph_label->setGeometry(QRect(10, 160, 111, 16));
        temph_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);"));
        h_label = new QLabel(groupBox_2);
        h_label->setObjectName(QString::fromUtf8("h_label"));
        h_label->setGeometry(QRect(10, 90, 111, 16));
        h_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);"));
        tof_label = new QLabel(groupBox_2);
        tof_label->setObjectName(QString::fromUtf8("tof_label"));
        tof_label->setGeometry(QRect(10, 110, 111, 16));
        tof_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);"));
        pitch_label = new QLabel(groupBox_2);
        pitch_label->setObjectName(QString::fromUtf8("pitch_label"));
        pitch_label->setGeometry(QRect(10, 20, 111, 16));
        pitch_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);"));
        yaw_label = new QLabel(groupBox_2);
        yaw_label->setObjectName(QString::fromUtf8("yaw_label"));
        yaw_label->setGeometry(QRect(10, 60, 111, 16));
        yaw_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);"));
        roll_label = new QLabel(groupBox_2);
        roll_label->setObjectName(QString::fromUtf8("roll_label"));
        roll_label->setGeometry(QRect(10, 40, 111, 16));
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
        groupBox_3->setGeometry(QRect(320, 20, 401, 61));
        groupBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 20%);\n"
"border: 0px solid;"));
        battery_bar = new QProgressBar(groupBox_3);
        battery_bar->setObjectName(QString::fromUtf8("battery_bar"));
        battery_bar->setGeometry(QRect(60, 20, 118, 23));
        battery_bar->setStyleSheet(QString::fromUtf8(""));
        battery_bar->setValue(24);
        speed_label = new QLabel(groupBox_3);
        speed_label->setObjectName(QString::fromUtf8("speed_label"));
        speed_label->setGeometry(QRect(200, 20, 141, 16));
        speed_label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 0%);"));
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
        frame_label->setText(QApplication::translate("UranusClass", "                   TextLabel", nullptr));
        buffer_label->setText(QApplication::translate("UranusClass", "TextLabel", nullptr));
        connect_btn->setText(QApplication::translate("UranusClass", "Connect to Tello", nullptr));
        rc_factorlabel->setText(QApplication::translate("UranusClass", "Stick", nullptr));
        speed_factor->setText(QApplication::translate("UranusClass", "Speed", nullptr));
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
    } // retranslateUi

};

namespace Ui {
    class UranusClass: public Ui_UranusClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_URANUS_H
