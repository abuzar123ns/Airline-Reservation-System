/********************************************************************************
** Form generated from reading UI file 'updateticket.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATETICKET_H
#define UI_UPDATETICKET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_updateticket
{
public:
    QLabel *label;
    QPushButton *changeButton;
    QLineEdit *ticketIdInput;

    void setupUi(QWidget *updateticket)
    {
        if (updateticket->objectName().isEmpty())
            updateticket->setObjectName("updateticket");
        updateticket->resize(867, 698);
        label = new QLabel(updateticket);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 300, 501, 291));
        label->setPixmap(QPixmap(QString::fromUtf8(":/resources/Admin_Loginwindow copy.png")));
        changeButton = new QPushButton(updateticket);
        changeButton->setObjectName("changeButton");
        changeButton->setGeometry(QRect(460, 440, 93, 29));
        ticketIdInput = new QLineEdit(updateticket);
        ticketIdInput->setObjectName("ticketIdInput");
        ticketIdInput->setGeometry(QRect(210, 420, 113, 26));

        retranslateUi(updateticket);

        QMetaObject::connectSlotsByName(updateticket);
    } // setupUi

    void retranslateUi(QWidget *updateticket)
    {
        updateticket->setWindowTitle(QCoreApplication::translate("updateticket", "Form", nullptr));
        label->setText(QString());
        changeButton->setText(QCoreApplication::translate("updateticket", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class updateticket: public Ui_updateticket {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATETICKET_H
