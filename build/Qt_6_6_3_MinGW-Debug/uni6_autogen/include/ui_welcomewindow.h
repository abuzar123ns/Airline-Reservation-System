/********************************************************************************
** Form generated from reading UI file 'welcomewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMEWINDOW_H
#define UI_WELCOMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_welcomewindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *welcomewindow)
    {
        if (welcomewindow->objectName().isEmpty())
            welcomewindow->setObjectName("welcomewindow");
        welcomewindow->resize(1176, 761);
        centralwidget = new QWidget(welcomewindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1100, 600));
        label->setPixmap(QPixmap(QString::fromUtf8(":/resources/Welcome_window.png")));
        label->setScaledContents(true);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(390, 330, 341, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    font-size: 16px;        \n"
"    font-weight: bold;       \n"
"	color: rgb(255, 255, 255);\n"
" \n"
"	background-color: rgb(0, 0, 0);\n"
"    border: 2px solid #555555;  /* Border styling */\n"
"    border-radius: 5px;      /* Rounded corners */\n"
"    padding: 5px;            /* Inner spacing */\n"
"}"));
        welcomewindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(welcomewindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1176, 26));
        welcomewindow->setMenuBar(menubar);
        statusbar = new QStatusBar(welcomewindow);
        statusbar->setObjectName("statusbar");
        welcomewindow->setStatusBar(statusbar);

        retranslateUi(welcomewindow);

        QMetaObject::connectSlotsByName(welcomewindow);
    } // setupUi

    void retranslateUi(QMainWindow *welcomewindow)
    {
        welcomewindow->setWindowTitle(QCoreApplication::translate("welcomewindow", "welcomewindow", nullptr));
        label->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("welcomewindow", "PRESS HERE TO CONTINUE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class welcomewindow: public Ui_welcomewindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMEWINDOW_H
