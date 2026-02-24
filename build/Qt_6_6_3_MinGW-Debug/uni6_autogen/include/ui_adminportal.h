/********************************************************************************
** Form generated from reading UI file 'adminportal.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINPORTAL_H
#define UI_ADMINPORTAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminportal
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *viewflightdetail;
    QPushButton *pushButton_2;

    void setupUi(QWidget *adminportal)
    {
        if (adminportal->objectName().isEmpty())
            adminportal->setObjectName("adminportal");
        adminportal->resize(1100, 600);
        label = new QLabel(adminportal);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1100, 600));
        label->setPixmap(QPixmap(QString::fromUtf8(":/resources/Adminportalnew copy.png")));
        pushButton = new QPushButton(adminportal);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(782, 250, 111, 191));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    color: white; /* or any other color for the text */\n"
"}"));
        viewflightdetail = new QPushButton(adminportal);
        viewflightdetail->setObjectName("viewflightdetail");
        viewflightdetail->setGeometry(QRect(920, 250, 111, 191));
        viewflightdetail->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    color: white; /* or any other color for the text */\n"
"}"));
        pushButton_2 = new QPushButton(adminportal);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(640, 230, 121, 221));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    color: white; /* or any other color for the text */\n"
"}"));

        retranslateUi(adminportal);

        QMetaObject::connectSlotsByName(adminportal);
    } // setupUi

    void retranslateUi(QWidget *adminportal)
    {
        adminportal->setWindowTitle(QCoreApplication::translate("adminportal", "Form", nullptr));
        label->setText(QString());
        pushButton->setText(QString());
        viewflightdetail->setText(QString());
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class adminportal: public Ui_adminportal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINPORTAL_H
