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

    void setupUi(QMainWindow *UranusClass)
    {
        if (UranusClass->objectName().isEmpty())
            UranusClass->setObjectName(QString::fromUtf8("UranusClass"));
        UranusClass->resize(600, 400);
        centralWidget = new QWidget(UranusClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        takeoffBtn = new QPushButton(centralWidget);
        takeoffBtn->setObjectName(QString::fromUtf8("takeoffBtn"));
        takeoffBtn->setGeometry(QRect(260, 240, 75, 23));
        landBtn = new QPushButton(centralWidget);
        landBtn->setObjectName(QString::fromUtf8("landBtn"));
        landBtn->setGeometry(QRect(260, 300, 75, 23));
        connect = new QPushButton(centralWidget);
        connect->setObjectName(QString::fromUtf8("connect"));
        connect->setGeometry(QRect(260, 170, 75, 23));
        UranusClass->setCentralWidget(centralWidget);

        retranslateUi(UranusClass);
        QObject::connect(connect, SIGNAL(clicked()), UranusClass, SLOT(on_connectBtn_clicked()));
        QObject::connect(takeoffBtn, SIGNAL(clicked()), UranusClass, SLOT(on_takeoffBtn_clicked()));
        QObject::connect(landBtn, SIGNAL(clicked()), UranusClass, SLOT(on_landBtn_clicked()));

        QMetaObject::connectSlotsByName(UranusClass);
    } // setupUi

    void retranslateUi(QMainWindow *UranusClass)
    {
        UranusClass->setWindowTitle(QApplication::translate("UranusClass", "Uranus", nullptr));
        takeoffBtn->setText(QApplication::translate("UranusClass", "Takeoff", nullptr));
        landBtn->setText(QApplication::translate("UranusClass", "Land", nullptr));
        connect->setText(QApplication::translate("UranusClass", "Connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UranusClass: public Ui_UranusClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_URANUS_H
