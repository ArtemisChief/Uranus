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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UranusClass
{
public:
    QWidget *centralWidget;
    QPushButton *takeoffBtn;
    QPushButton *landBtn;
    QPushButton *connect;
    QPushButton *streamonBtn;
    QLabel *videoLabel;
    QLabel *label;

    void setupUi(QMainWindow *UranusClass)
    {
        if (UranusClass->objectName().isEmpty())
            UranusClass->setObjectName(QString::fromUtf8("UranusClass"));
        UranusClass->resize(1440, 900);
        centralWidget = new QWidget(UranusClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        takeoffBtn = new QPushButton(centralWidget);
        takeoffBtn->setObjectName(QString::fromUtf8("takeoffBtn"));
        takeoffBtn->setGeometry(QRect(1340, 90, 81, 23));
        landBtn = new QPushButton(centralWidget);
        landBtn->setObjectName(QString::fromUtf8("landBtn"));
        landBtn->setGeometry(QRect(1340, 120, 81, 23));
        connect = new QPushButton(centralWidget);
        connect->setObjectName(QString::fromUtf8("connect"));
        connect->setGeometry(QRect(1340, 60, 81, 23));
        streamonBtn = new QPushButton(centralWidget);
        streamonBtn->setObjectName(QString::fromUtf8("streamonBtn"));
        streamonBtn->setGeometry(QRect(1340, 150, 81, 28));
        videoLabel = new QLabel(centralWidget);
        videoLabel->setObjectName(QString::fromUtf8("videoLabel"));
        videoLabel->setGeometry(QRect(20, 20, 1280, 720));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 820, 1321, 41));
        UranusClass->setCentralWidget(centralWidget);

        retranslateUi(UranusClass);
        QObject::connect(connect, SIGNAL(clicked()), UranusClass, SLOT(on_connectBtn_clicked()));
        QObject::connect(takeoffBtn, SIGNAL(clicked()), UranusClass, SLOT(on_takeoffBtn_clicked()));
        QObject::connect(landBtn, SIGNAL(clicked()), UranusClass, SLOT(on_landBtn_clicked()));
        QObject::connect(streamonBtn, SIGNAL(clicked()), UranusClass, SLOT(on_streamonBtn_clicked()));

        QMetaObject::connectSlotsByName(UranusClass);
    } // setupUi

    void retranslateUi(QMainWindow *UranusClass)
    {
        UranusClass->setWindowTitle(QApplication::translate("UranusClass", "Uranus", nullptr));
        takeoffBtn->setText(QApplication::translate("UranusClass", "Takeoff", nullptr));
        landBtn->setText(QApplication::translate("UranusClass", "Land", nullptr));
        connect->setText(QApplication::translate("UranusClass", "Connect", nullptr));
        streamonBtn->setText(QApplication::translate("UranusClass", "streamon", nullptr));
        videoLabel->setText(QApplication::translate("UranusClass", "TextLabel", nullptr));
        label->setText(QApplication::translate("UranusClass", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UranusClass: public Ui_UranusClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_URANUS_H
