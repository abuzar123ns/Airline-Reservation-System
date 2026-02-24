/********************************************************************************
** Form generated from reading UI file 'bill.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BILL_H
#define UI_BILL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_bill
{
public:
    QLabel *label;
    QLabel *labelName;
    QLabel *labelPhoneNo;
    QLabel *labelDateOfDepart;
    QLabel *labelFlightAvailable;
    QLabel *labelSeatClass;
    QLabel *labelFlyingFrom;
    QLabel *labelFlyingTo;
    QLabel *ticketIdLabel;
    QLabel *labelseatNumber;
    QLabel *labelbill;

    void setupUi(QWidget *bill)
    {
        if (bill->objectName().isEmpty())
            bill->setObjectName("bill");
        bill->resize(1100, 600);
        label = new QLabel(bill);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1100, 600));
        label->setPixmap(QPixmap(QString::fromUtf8(":/resources/ticketconfirmed.png")));
        labelName = new QLabel(bill);
        labelName->setObjectName("labelName");
        labelName->setGeometry(QRect(90, 220, 251, 31));
        QFont font;
        font.setBold(true);
        labelName->setFont(font);
        labelName->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    font-size: 16px;        \n"
"    font-weight: bold;       \n"
"	color: rgb(85, 255, 255);\n"
" \n"
"	\n"
"    border: 2px solid #555555;  /* Border styling */\n"
"    border-radius: 5px;      /* Rounded corners */\n"
"    padding: 5px;            /* Inner spacing */\n"
"}"));
        labelPhoneNo = new QLabel(bill);
        labelPhoneNo->setObjectName("labelPhoneNo");
        labelPhoneNo->setGeometry(QRect(130, 280, 131, 31));
        labelPhoneNo->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    font-size: 16px;        \n"
"    font-weight: bold;       \n"
"	\n"
"	color: rgb(85, 255, 255);\n"
" \n"
"	\n"
"	\n"
"    border: 2px solid #555555;  /* Border styling */\n"
"    border-radius: 5px;      /* Rounded corners */\n"
"    padding: 5px;            /* Inner spacing */\n"
"}"));
        labelDateOfDepart = new QLabel(bill);
        labelDateOfDepart->setObjectName("labelDateOfDepart");
        labelDateOfDepart->setGeometry(QRect(140, 320, 171, 31));
        labelDateOfDepart->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    font-size: 16px;        \n"
"    font-weight: bold;       \n"
"	color: rgb(85, 255, 255);\n"
" \n"
"	\n"
"	\n"
"    border: 2px solid #555555;  /* Border styling */\n"
"    border-radius: 5px;      /* Rounded corners */\n"
"    padding: 5px;            /* Inner spacing */\n"
"}"));
        labelFlightAvailable = new QLabel(bill);
        labelFlightAvailable->setObjectName("labelFlightAvailable");
        labelFlightAvailable->setGeometry(QRect(70, 470, 171, 31));
        labelFlightAvailable->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    font-size: 16px;        \n"
"    font-weight: bold;       \n"
"	color: rgb(85, 255, 255);\n"
" \n"
"	\n"
"	\n"
"    border: 2px solid #555555;  /* Border styling */\n"
"    border-radius: 5px;      /* Rounded corners */\n"
"    padding: 5px;            /* Inner spacing */\n"
"}\n"
""));
        labelSeatClass = new QLabel(bill);
        labelSeatClass->setObjectName("labelSeatClass");
        labelSeatClass->setGeometry(QRect(100, 420, 131, 31));
        labelSeatClass->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    font-size: 16px;        \n"
"    font-weight: bold;       \n"
"	color: rgb(85, 255, 255);\n"
" \n"
"	\n"
"	\n"
"    border: 2px solid #555555;  /* Border styling */\n"
"    border-radius: 5px;      /* Rounded corners */\n"
"    padding: 5px;            /* Inner spacing */\n"
"}\n"
""));
        labelFlyingFrom = new QLabel(bill);
        labelFlyingFrom->setObjectName("labelFlyingFrom");
        labelFlyingFrom->setGeometry(QRect(660, 30, 141, 31));
        labelFlyingFrom->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    font-size: 16px;        \n"
"    font-weight: bold;       \n"
"	\n"
"	color: rgb(0, 0, 255);\n"
"	\n"
"	\n"
"    border: 2px solid #555555;  /* Border styling */\n"
"    border-radius: 5px;      /* Rounded corners */\n"
"    padding: 5px;            /* Inner spacing */\n"
"}\n"
""));
        labelFlyingTo = new QLabel(bill);
        labelFlyingTo->setObjectName("labelFlyingTo");
        labelFlyingTo->setGeometry(QRect(910, 30, 101, 31));
        labelFlyingTo->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    font-size: 16px;        \n"
"    font-weight: bold;       \n"
"	\n"
"	color: rgb(0, 0, 127);\n"
" \n"
"	\n"
"	\n"
"    border: 2px solid #555555;  /* Border styling */\n"
"    border-radius: 5px;      /* Rounded corners */\n"
"    padding: 5px;            /* Inner spacing */\n"
"}"));
        ticketIdLabel = new QLabel(bill);
        ticketIdLabel->setObjectName("ticketIdLabel");
        ticketIdLabel->setGeometry(QRect(110, 170, 231, 31));
        ticketIdLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    font-size: 16px;        \n"
"    font-weight: bold;       \n"
"	color: rgb(85, 255, 255);\n"
" \n"
"	\n"
"    border: 2px solid #555555;  /* Border styling */\n"
"    border-radius: 5px;      /* Rounded corners */\n"
"    padding: 5px;            /* Inner spacing */\n"
"}"));
        labelseatNumber = new QLabel(bill);
        labelseatNumber->setObjectName("labelseatNumber");
        labelseatNumber->setGeometry(QRect(110, 369, 211, 31));
        labelseatNumber->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    font-size: 16px;        \n"
"    font-weight: bold;       \n"
"	color: rgb(85, 255, 255);\n"
" \n"
"	\n"
"	\n"
"    border: 2px solid #555555;  /* Border styling */\n"
"    border-radius: 5px;      /* Rounded corners */\n"
"    padding: 5px;            /* Inner spacing */\n"
"}"));
        labelbill = new QLabel(bill);
        labelbill->setObjectName("labelbill");
        labelbill->setGeometry(QRect(100, 530, 141, 31));
        labelbill->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    font-size: 16px;        \n"
"    font-weight: bold;       \n"
"	color: rgb(85, 255, 255);\n"
" \n"
"	\n"
"	\n"
"    border: 2px solid #555555;  /* Border styling */\n"
"    border-radius: 5px;      /* Rounded corners */\n"
"    padding: 5px;            /* Inner spacing */\n"
"}\n"
""));
        label->raise();
        labelDateOfDepart->raise();
        labelFlightAvailable->raise();
        labelSeatClass->raise();
        labelName->raise();
        labelPhoneNo->raise();
        labelFlyingTo->raise();
        labelFlyingFrom->raise();
        ticketIdLabel->raise();
        labelseatNumber->raise();
        labelbill->raise();

        retranslateUi(bill);

        QMetaObject::connectSlotsByName(bill);
    } // setupUi

    void retranslateUi(QWidget *bill)
    {
        bill->setWindowTitle(QCoreApplication::translate("bill", "Form", nullptr));
        label->setText(QString());
        labelName->setText(QString());
        labelPhoneNo->setText(QString());
        labelDateOfDepart->setText(QString());
        labelFlightAvailable->setText(QString());
        labelSeatClass->setText(QString());
        labelFlyingFrom->setText(QCoreApplication::translate("bill", "TextLabel", nullptr));
        labelFlyingTo->setText(QCoreApplication::translate("bill", "text", nullptr));
        ticketIdLabel->setText(QString());
        labelseatNumber->setText(QString());
        labelbill->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class bill: public Ui_bill {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BILL_H
