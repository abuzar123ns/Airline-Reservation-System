/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginwindow
{
public:
    QLabel *label;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *loginButton;
    QPushButton *registerButton;
    QPushButton *admilogin;

    void setupUi(QWidget *loginwindow)
    {
        if (loginwindow->objectName().isEmpty())
            loginwindow->setObjectName("loginwindow");
        loginwindow->resize(1100, 600);
        label = new QLabel(loginwindow);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1100, 600));
        label->setPixmap(QPixmap(QString::fromUtf8(":/resources/Login_window.png")));
        label->setScaledContents(true);
        usernameLineEdit = new QLineEdit(loginwindow);
        usernameLineEdit->setObjectName("usernameLineEdit");
        usernameLineEdit->setGeometry(QRect(810, 140, 241, 31));
        QFont font;
        font.setBold(true);
        font.setItalic(false);
        font.setStrikeOut(false);
        usernameLineEdit->setFont(font);
        usernameLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background-color: rgb(231, 231, 231);\n"
"}"));
        passwordLineEdit = new QLineEdit(loginwindow);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setGeometry(QRect(810, 230, 241, 31));
        QFont font1;
        font1.setBold(true);
        passwordLineEdit->setFont(font1);
        passwordLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background-color: rgb(231, 231, 231);\n"
"}"));
        passwordLineEdit->setEchoMode(QLineEdit::EchoMode::Password);
        loginButton = new QPushButton(loginwindow);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(810, 360, 151, 41));
        loginButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: rgb(0, 171, 197);\n"
"border: 2px solid black;\n"
"}"));
        registerButton = new QPushButton(loginwindow);
        registerButton->setObjectName("registerButton");
        registerButton->setGeometry(QRect(760, 438, 241, 61));
        registerButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: rgb(0, 171, 197);\n"
"border: 2px solid black;\n"
"}"));
        admilogin = new QPushButton(loginwindow);
        admilogin->setObjectName("admilogin");
        admilogin->setGeometry(QRect(800, 530, 151, 29));

        retranslateUi(loginwindow);

        QMetaObject::connectSlotsByName(loginwindow);
    } // setupUi

    void retranslateUi(QWidget *loginwindow)
    {
        loginwindow->setWindowTitle(QCoreApplication::translate("loginwindow", "Form", nullptr));
        label->setText(QString());
        usernameLineEdit->setPlaceholderText(QCoreApplication::translate("loginwindow", "Username", nullptr));
        passwordLineEdit->setPlaceholderText(QCoreApplication::translate("loginwindow", "Password", nullptr));
        loginButton->setText(QCoreApplication::translate("loginwindow", "LOGIN", nullptr));
        registerButton->setText(QCoreApplication::translate("loginwindow", "REGISTER", nullptr));
        admilogin->setText(QCoreApplication::translate("loginwindow", "ADMIN LOGIN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginwindow: public Ui_loginwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
