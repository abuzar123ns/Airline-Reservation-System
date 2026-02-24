/********************************************************************************
** Form generated from reading UI file 'lodgecomplaintwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LODGECOMPLAINTWINDOW_H
#define UI_LODGECOMPLAINTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lodgecomplaintwindow
{
public:
    QLabel *label;
    QPushButton *lodgeComplaintButton;
    QLineEdit *ticketIdLineEdit;
    QTextEdit *messageTextEdit;

    void setupUi(QWidget *lodgecomplaintwindow)
    {
        if (lodgecomplaintwindow->objectName().isEmpty())
            lodgecomplaintwindow->setObjectName("lodgecomplaintwindow");
        lodgecomplaintwindow->resize(1100, 600);
        label = new QLabel(lodgecomplaintwindow);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1100, 600));
        label->setPixmap(QPixmap(QString::fromUtf8(":/resources/newlodgecoomplaint.png")));
        lodgeComplaintButton = new QPushButton(lodgecomplaintwindow);
        lodgeComplaintButton->setObjectName("lodgeComplaintButton");
        lodgeComplaintButton->setGeometry(QRect(60, 460, 471, 51));
        lodgeComplaintButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    font-size: 16px;        \n"
"    font-weight: bold;       \n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(17, 51, 202);\n"
"\n"
" \n"
"	\n"
"    /* Border styling */\n"
"	border-color: rgb(17, 51, 202);\n"
"    border-radius: 5px;      /* Rounded corners */\n"
"    padding: 5px;            /* Inner spacing */\n"
"}"));
        ticketIdLineEdit = new QLineEdit(lodgecomplaintwindow);
        ticketIdLineEdit->setObjectName("ticketIdLineEdit");
        ticketIdLineEdit->setGeometry(QRect(200, 200, 301, 31));
        messageTextEdit = new QTextEdit(lodgecomplaintwindow);
        messageTextEdit->setObjectName("messageTextEdit");
        messageTextEdit->setGeometry(QRect(80, 310, 451, 141));

        retranslateUi(lodgecomplaintwindow);

        QMetaObject::connectSlotsByName(lodgecomplaintwindow);
    } // setupUi

    void retranslateUi(QWidget *lodgecomplaintwindow)
    {
        lodgecomplaintwindow->setWindowTitle(QCoreApplication::translate("lodgecomplaintwindow", "Form", nullptr));
        label->setText(QString());
        lodgeComplaintButton->setText(QCoreApplication::translate("lodgecomplaintwindow", "LODGE COMPLAINT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lodgecomplaintwindow: public Ui_lodgecomplaintwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LODGECOMPLAINTWINDOW_H
