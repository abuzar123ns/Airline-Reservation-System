/********************************************************************************
** Form generated from reading UI file 'adminlogin.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINLOGIN_H
#define UI_ADMINLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminlogin
{
public:
    QLabel *label;
    QLineEdit *username;
    QLineEdit *password;
    QPushButton *loginButton;
    QPushButton *BackButton;

    void setupUi(QWidget *adminlogin)
    {
        if (adminlogin->objectName().isEmpty())
            adminlogin->setObjectName("adminlogin");
        adminlogin->resize(1100, 600);
        label = new QLabel(adminlogin);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1100, 600));
        label->setPixmap(QPixmap(QString::fromUtf8(":/resources/Admin_Loginwindow copy.png")));
        username = new QLineEdit(adminlogin);
        username->setObjectName("username");
        username->setGeometry(QRect(712, 250, 271, 31));
        password = new QLineEdit(adminlogin);
        password->setObjectName("password");
        password->setGeometry(QRect(710, 350, 281, 26));
        password->setEchoMode(QLineEdit::EchoMode::PasswordEchoOnEdit);
        loginButton = new QPushButton(adminlogin);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(760, 480, 201, 29));
        BackButton = new QPushButton(adminlogin);
        BackButton->setObjectName("BackButton");
        BackButton->setGeometry(QRect(10, 560, 93, 29));

        retranslateUi(adminlogin);

        QMetaObject::connectSlotsByName(adminlogin);
    } // setupUi

    void retranslateUi(QWidget *adminlogin)
    {
        adminlogin->setWindowTitle(QCoreApplication::translate("adminlogin", "Form", nullptr));
        label->setText(QString());
        loginButton->setText(QCoreApplication::translate("adminlogin", "LOGIN", nullptr));
        BackButton->setText(QCoreApplication::translate("adminlogin", "BACK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminlogin: public Ui_adminlogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINLOGIN_H
