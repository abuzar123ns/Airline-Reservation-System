/********************************************************************************
** Form generated from reading UI file 'bookflightwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKFLIGHTWINDOW_H
#define UI_BOOKFLIGHTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_bookflightwindow
{
public:
    QLabel *label;
    QLineEdit *Firstname;
    QLineEdit *Phoneno;
    QLineEdit *Address;
    QRadioButton *Buisness;
    QRadioButton *Economy;
    QLineEdit *seatNumber;
    QPushButton *pushButton;
    QLineEdit *Lastname;
    QComboBox *comboBox;
    QDateEdit *dateEdit;
    QLineEdit *FlyingFrom;
    QLineEdit *FlyingTo;
    QLineEdit *Cardno;
    QLineEdit *Cvv;
    QCheckBox *Paypal;
    QCheckBox *Visa;
    QCheckBox *Master;
    QCheckBox *Veg;
    QCheckBox *Nonveg;
    QCheckBox *WifiYes;
    QCheckBox *WifiNo;

    void setupUi(QWidget *bookflightwindow)
    {
        if (bookflightwindow->objectName().isEmpty())
            bookflightwindow->setObjectName("bookflightwindow");
        bookflightwindow->resize(1100, 600);
        bookflightwindow->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(bookflightwindow);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1100, 600));
        label->setPixmap(QPixmap(QString::fromUtf8(":/resources/bookfightwindow5.png")));
        Firstname = new QLineEdit(bookflightwindow);
        Firstname->setObjectName("Firstname");
        Firstname->setGeometry(QRect(180, 130, 113, 26));
        Phoneno = new QLineEdit(bookflightwindow);
        Phoneno->setObjectName("Phoneno");
        Phoneno->setGeometry(QRect(180, 170, 113, 26));
        Address = new QLineEdit(bookflightwindow);
        Address->setObjectName("Address");
        Address->setGeometry(QRect(250, 200, 113, 26));
        Buisness = new QRadioButton(bookflightwindow);
        Buisness->setObjectName("Buisness");
        Buisness->setGeometry(QRect(760, 164, 110, 20));
        Economy = new QRadioButton(bookflightwindow);
        Economy->setObjectName("Economy");
        Economy->setGeometry(QRect(910, 161, 110, 31));
        seatNumber = new QLineEdit(bookflightwindow);
        seatNumber->setObjectName("seatNumber");
        seatNumber->setGeometry(QRect(870, 200, 113, 26));
        pushButton = new QPushButton(bookflightwindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(830, 520, 141, 29));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    font-size: 16px;        \n"
"    font-weight: bold;       \n"
"	color: rgb(255, 255, 255);\n"
" \n"
"	background-color: rgb(0, 0, 0);\n"
"    border: 2px solid #555555;  /* Border styling */\n"
"    border-radius: 5px;      /* Rounded corners */\n"
"    padding: 5px;            /* Inner spacing */\n"
"}"));
        Lastname = new QLineEdit(bookflightwindow);
        Lastname->setObjectName("Lastname");
        Lastname->setGeometry(QRect(460, 130, 113, 26));
        comboBox = new QComboBox(bookflightwindow);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(210, 230, 76, 26));
        dateEdit = new QDateEdit(bookflightwindow);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(290, 270, 110, 26));
        FlyingFrom = new QLineEdit(bookflightwindow);
        FlyingFrom->setObjectName("FlyingFrom");
        FlyingFrom->setGeometry(QRect(180, 310, 113, 26));
        FlyingTo = new QLineEdit(bookflightwindow);
        FlyingTo->setObjectName("FlyingTo");
        FlyingTo->setGeometry(QRect(450, 310, 113, 26));
        Cardno = new QLineEdit(bookflightwindow);
        Cardno->setObjectName("Cardno");
        Cardno->setGeometry(QRect(360, 470, 91, 21));
        Cvv = new QLineEdit(bookflightwindow);
        Cvv->setObjectName("Cvv");
        Cvv->setGeometry(QRect(340, 490, 91, 21));
        Paypal = new QCheckBox(bookflightwindow);
        Paypal->setObjectName("Paypal");
        Paypal->setGeometry(QRect(90, 500, 91, 24));
        Visa = new QCheckBox(bookflightwindow);
        Visa->setObjectName("Visa");
        Visa->setGeometry(QRect(90, 520, 91, 24));
        Master = new QCheckBox(bookflightwindow);
        Master->setObjectName("Master");
        Master->setGeometry(QRect(90, 540, 91, 24));
        Veg = new QCheckBox(bookflightwindow);
        Veg->setObjectName("Veg");
        Veg->setGeometry(QRect(750, 270, 91, 24));
        Nonveg = new QCheckBox(bookflightwindow);
        Nonveg->setObjectName("Nonveg");
        Nonveg->setGeometry(QRect(880, 270, 91, 24));
        WifiYes = new QCheckBox(bookflightwindow);
        WifiYes->setObjectName("WifiYes");
        WifiYes->setGeometry(QRect(760, 340, 91, 24));
        WifiNo = new QCheckBox(bookflightwindow);
        WifiNo->setObjectName("WifiNo");
        WifiNo->setGeometry(QRect(890, 340, 91, 24));
        label->raise();
        Firstname->raise();
        Lastname->raise();
        Phoneno->raise();
        Address->raise();
        seatNumber->raise();
        pushButton->raise();
        Buisness->raise();
        Economy->raise();
        comboBox->raise();
        dateEdit->raise();
        FlyingFrom->raise();
        FlyingTo->raise();
        Cardno->raise();
        Cvv->raise();
        Paypal->raise();
        Visa->raise();
        Master->raise();
        Veg->raise();
        Nonveg->raise();
        WifiYes->raise();
        WifiNo->raise();

        retranslateUi(bookflightwindow);

        QMetaObject::connectSlotsByName(bookflightwindow);
    } // setupUi

    void retranslateUi(QWidget *bookflightwindow)
    {
        bookflightwindow->setWindowTitle(QCoreApplication::translate("bookflightwindow", "Form", nullptr));
        label->setText(QString());
        Buisness->setText(QString());
        Economy->setText(QString());
        pushButton->setText(QCoreApplication::translate("bookflightwindow", "CONFIRM", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("bookflightwindow", "BA2490 ", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("bookflightwindow", "EK603 ", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("bookflightwindow", "QR640", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("bookflightwindow", "PK302", nullptr));

        Paypal->setText(QString());
        Visa->setText(QString());
        Master->setText(QString());
        Veg->setText(QString());
        Nonveg->setText(QString());
        WifiYes->setText(QString());
        WifiNo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class bookflightwindow: public Ui_bookflightwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKFLIGHTWINDOW_H
