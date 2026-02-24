/********************************************************************************
** Form generated from reading UI file 'mainscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCREEN_H
#define UI_MAINSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainscreen
{
public:
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QWidget *mainscreen)
    {
        if (mainscreen->objectName().isEmpty())
            mainscreen->setObjectName("mainscreen");
        mainscreen->resize(1100, 600);
        label_2 = new QLabel(mainscreen);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(300, 530, 31, 20));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/resources/arrow2.png")));
        label_2->setScaledContents(true);
        label_3 = new QLabel(mainscreen);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(660, 530, 31, 20));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/resources/arrow2.png")));
        label_3->setScaledContents(true);
        label_4 = new QLabel(mainscreen);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(1030, 530, 31, 20));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/resources/arrow2.png")));
        label_4->setScaledContents(true);
        pushButton_4 = new QPushButton(mainscreen);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(630, 530, 61, 21));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border:none;\n"
"background-color: rgb(5, 47, 98)\n"
"\n"
"}"));
        pushButton_5 = new QPushButton(mainscreen);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(1010, 530, 51, 21));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border:none;\n"
"	background-color: rgb(195, 236, 254);\n"
"hover:rgb(0, 0, 255)\n"
"}"));
        pushButton = new QPushButton(mainscreen);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(260, 530, 71, 16));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border:none;\n"
"	background-color: rgb(195, 236, 254);\n"
"hover:rgb(0, 0, 255)\n"
"}"));
        label = new QLabel(mainscreen);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 0, 1100, 600));
        label->setPixmap(QPixmap(QString::fromUtf8(":/resources/mainwindow5.png")));
        label->raise();
        pushButton->raise();
        pushButton_4->raise();
        pushButton_5->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();

        retranslateUi(mainscreen);

        QMetaObject::connectSlotsByName(mainscreen);
    } // setupUi

    void retranslateUi(QWidget *mainscreen)
    {
        mainscreen->setWindowTitle(QCoreApplication::translate("mainscreen", "Form", nullptr));
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        pushButton->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class mainscreen: public Ui_mainscreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCREEN_H
