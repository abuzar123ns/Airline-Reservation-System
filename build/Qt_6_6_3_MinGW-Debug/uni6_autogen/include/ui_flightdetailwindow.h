/********************************************************************************
** Form generated from reading UI file 'flightdetailwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLIGHTDETAILWINDOW_H
#define UI_FLIGHTDETAILWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_flightdetailwindow
{
public:
    QLabel *BACKGROUNDIMAGE;
    QLabel *nameLabel;
    QLabel *phoneLabel;
    QLineEdit *ticketIdInput;
    QLabel *toLabel;
    QLabel *fromLabel;
    QLabel *wifiLabel;
    QLabel *seatNumberLabel;
    QLabel *seatClassLabel;
    QLabel *mealLabel;
    QLabel *flightLabel;
    QLabel *dateLabel;
    QLabel *paymentLabel;
    QLabel *costLabel;
    QPushButton *searchButton;
    QLabel *ticketIdLabel;

    void setupUi(QWidget *flightdetailwindow)
    {
        if (flightdetailwindow->objectName().isEmpty())
            flightdetailwindow->setObjectName("flightdetailwindow");
        flightdetailwindow->resize(1100, 600);
        BACKGROUNDIMAGE = new QLabel(flightdetailwindow);
        BACKGROUNDIMAGE->setObjectName("BACKGROUNDIMAGE");
        BACKGROUNDIMAGE->setGeometry(QRect(0, 0, 1100, 600));
        BACKGROUNDIMAGE->setPixmap(QPixmap(QString::fromUtf8(":/resources/flightdetail2.png")));
        nameLabel = new QLabel(flightdetailwindow);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setGeometry(QRect(140, 199, 191, 31));
        nameLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    font-size: 16px;        \n"
"    font-weight: bold;       \n"
"	color: rgb(85, 255, 255);\n"
" \n"
"	\n"
"    border: 2px solid #555555;  /* Border styling */\n"
"    border-radius: 5px;      /* Rounded corners */\n"
"    padding: 5px;            /* Inner spacing */\n"
"}\n"
""));
        phoneLabel = new QLabel(flightdetailwindow);
        phoneLabel->setObjectName("phoneLabel");
        phoneLabel->setGeometry(QRect(170, 249, 231, 31));
        phoneLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    font-size: 16px;        \n"
"    font-weight: bold;       \n"
"	color: rgb(85, 255, 255);\n"
" \n"
"	\n"
"    border: 2px solid #555555;  /* Border styling */\n"
"    border-radius: 5px;      /* Rounded corners */\n"
"    padding: 5px;            /* Inner spacing */\n"
"}\n"
""));
        ticketIdInput = new QLineEdit(flightdetailwindow);
        ticketIdInput->setObjectName("ticketIdInput");
        ticketIdInput->setGeometry(QRect(160, 120, 191, 26));
        ticketIdInput->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"    font-size: 16px;        \n"
"    font-weight: bold;       \n"
"	color: rgb(85, 255, 255);\n"
" \n"
"	background-color: rgb(139, 185, 255);\n"
"	\n"
"    border: 2px solid #555555;  /* Border styling */\n"
"    border-radius: 5px;      /* Rounded corners */\n"
"    padding: 5px;            /* Inner spacing */\n"
"}\n"
""));
        toLabel = new QLabel(flightdetailwindow);
        toLabel->setObjectName("toLabel");
        toLabel->setGeometry(QRect(480, 380, 121, 31));
        toLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    font-size: 16px;        \n"
"    font-weight: bold;       \n"
"	color: rgb(85, 255, 255);\n"
" \n"
"	\n"
"    border: 2px solid #555555;  /* Border styling */\n"
"    border-radius: 5px;      /* Rounded corners */\n"
"    padding: 5px;            /* Inner spacing */\n"
"}\n"
""));
        fromLabel = new QLabel(flightdetailwindow);
        fromLabel->setObjectName("fromLabel");
        fromLabel->setGeometry(QRect(130, 380, 161, 31));
        fromLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    font-size: 16px;        \n"
"    font-weight: bold;       \n"
"	color: rgb(85, 255, 255);\n"
" \n"
"	\n"
"    border: 2px solid #555555;  /* Border styling */\n"
"    border-radius: 5px;      /* Rounded corners */\n"
"    padding: 5px;            /* Inner spacing */\n"
"}\n"
""));
        wifiLabel = new QLabel(flightdetailwindow);
        wifiLabel->setObjectName("wifiLabel");
        wifiLabel->setGeometry(QRect(190, 300, 231, 31));
        wifiLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    font-size: 16px;        \n"
"    font-weight: bold;       \n"
"	color: rgb(85, 255, 255);\n"
" \n"
"	\n"
"    border: 2px solid #555555;  /* Border styling */\n"
"    border-radius: 5px;      /* Rounded corners */\n"
"    padding: 5px;            /* Inner spacing */\n"
"}\n"
""));
        seatNumberLabel = new QLabel(flightdetailwindow);
        seatNumberLabel->setObjectName("seatNumberLabel");
        seatNumberLabel->setGeometry(QRect(750, 50, 231, 31));
        seatNumberLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    font-size: 16px;        \n"
"    font-weight: bold;       \n"
"	color: rgb(85, 255, 255);\n"
" \n"
"	\n"
"    border: 2px solid #555555;  /* Border styling */\n"
"    border-radius: 5px;      /* Rounded corners */\n"
"    padding: 5px;            /* Inner spacing */\n"
"}\n"
""));
        seatClassLabel = new QLabel(flightdetailwindow);
        seatClassLabel->setObjectName("seatClassLabel");
        seatClassLabel->setGeometry(QRect(740, 110, 231, 31));
        seatClassLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    font-size: 16px;        \n"
"    font-weight: bold;       \n"
"	color: rgb(85, 255, 255);\n"
" \n"
"	\n"
"    border: 2px solid #555555;  /* Border styling */\n"
"    border-radius: 5px;      /* Rounded corners */\n"
"    padding: 5px;            /* Inner spacing */\n"
"}\n"
""));
        mealLabel = new QLabel(flightdetailwindow);
        mealLabel->setObjectName("mealLabel");
        mealLabel->setGeometry(QRect(740, 160, 231, 31));
        mealLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    font-size: 16px;        \n"
"    font-weight: bold;       \n"
"	color: rgb(85, 255, 255);\n"
" \n"
"	\n"
"    border: 2px solid #555555;  /* Border styling */\n"
"    border-radius: 5px;      /* Rounded corners */\n"
"    padding: 5px;            /* Inner spacing */\n"
"}\n"
""));
        flightLabel = new QLabel(flightdetailwindow);
        flightLabel->setObjectName("flightLabel");
        flightLabel->setGeometry(QRect(720, 210, 231, 31));
        flightLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    font-size: 16px;        \n"
"    font-weight: bold;       \n"
"	color: rgb(85, 255, 255);\n"
" \n"
"	\n"
"    border: 2px solid #555555;  /* Border styling */\n"
"    border-radius: 5px;      /* Rounded corners */\n"
"    padding: 5px;            /* Inner spacing */\n"
"}\n"
""));
        dateLabel = new QLabel(flightdetailwindow);
        dateLabel->setObjectName("dateLabel");
        dateLabel->setGeometry(QRect(760, 260, 231, 31));
        dateLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    font-size: 16px;        \n"
"    font-weight: bold;       \n"
"	color: rgb(85, 255, 255);\n"
" \n"
"	\n"
"    border: 2px solid #555555;  /* Border styling */\n"
"    border-radius: 5px;      /* Rounded corners */\n"
"    padding: 5px;            /* Inner spacing */\n"
"}\n"
""));
        paymentLabel = new QLabel(flightdetailwindow);
        paymentLabel->setObjectName("paymentLabel");
        paymentLabel->setGeometry(QRect(760, 320, 231, 31));
        paymentLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    font-size: 16px;        \n"
"    font-weight: bold;       \n"
"	color: rgb(85, 255, 255);\n"
" \n"
"	\n"
"    border: 2px solid #555555;  /* Border styling */\n"
"    border-radius: 5px;      /* Rounded corners */\n"
"    padding: 5px;            /* Inner spacing */\n"
"}\n"
""));
        costLabel = new QLabel(flightdetailwindow);
        costLabel->setObjectName("costLabel");
        costLabel->setGeometry(QRect(730, 470, 231, 31));
        costLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    font-size: 16px;        \n"
"    font-weight: bold;       \n"
"	color: rgb(85, 255, 255);\n"
" \n"
"	\n"
"    border: 2px solid #555555;  /* Border styling */\n"
"    border-radius: 5px;      /* Rounded corners */\n"
"    padding: 5px;            /* Inner spacing */\n"
"}\n"
""));
        searchButton = new QPushButton(flightdetailwindow);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(360, 120, 81, 29));
        searchButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(139, 185, 255);\n"
"    font-size: 16px;        \n"
"    font-weight: bold;       \n"
"	\n"
"	color: rgb(0, 0, 0);\n"
" \n"
"	\n"
"    border: 2px solid #555555;  /* Border styling */\n"
"    border-radius: 5px;      /* Rounded corners */\n"
"    padding: 5px;            /* Inner spacing */\n"
"}\n"
""));
        ticketIdLabel = new QLabel(flightdetailwindow);
        ticketIdLabel->setObjectName("ticketIdLabel");
        ticketIdLabel->setGeometry(QRect(80, 470, 63, 20));

        retranslateUi(flightdetailwindow);

        QMetaObject::connectSlotsByName(flightdetailwindow);
    } // setupUi

    void retranslateUi(QWidget *flightdetailwindow)
    {
        flightdetailwindow->setWindowTitle(QCoreApplication::translate("flightdetailwindow", "Form", nullptr));
        BACKGROUNDIMAGE->setText(QString());
        nameLabel->setText(QString());
        phoneLabel->setText(QString());
        toLabel->setText(QString());
        fromLabel->setText(QString());
        wifiLabel->setText(QString());
        seatNumberLabel->setText(QString());
        seatClassLabel->setText(QString());
        mealLabel->setText(QString());
        flightLabel->setText(QString());
        dateLabel->setText(QString());
        paymentLabel->setText(QString());
        costLabel->setText(QString());
        searchButton->setText(QCoreApplication::translate("flightdetailwindow", "SEARCH", nullptr));
        ticketIdLabel->setText(QCoreApplication::translate("flightdetailwindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class flightdetailwindow: public Ui_flightdetailwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLIGHTDETAILWINDOW_H
