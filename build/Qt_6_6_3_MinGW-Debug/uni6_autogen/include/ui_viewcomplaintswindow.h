/********************************************************************************
** Form generated from reading UI file 'viewcomplaintswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWCOMPLAINTSWINDOW_H
#define UI_VIEWCOMPLAINTSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_viewcomplaintswindow
{
public:
    QLabel *label;
    QTableWidget *complaintsTableWidget;
    QComboBox *statusFilterComboBox;
    QPushButton *refreshButton;
    QPushButton *viewDetailButton;
    QPushButton *updateStatusButton;

    void setupUi(QWidget *viewcomplaintswindow)
    {
        if (viewcomplaintswindow->objectName().isEmpty())
            viewcomplaintswindow->setObjectName("viewcomplaintswindow");
        viewcomplaintswindow->resize(1112, 718);
        label = new QLabel(viewcomplaintswindow);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1100, 600));
        label->setPixmap(QPixmap(QString::fromUtf8(":/resources/newlodgecoomplaint.png")));
        complaintsTableWidget = new QTableWidget(viewcomplaintswindow);
        complaintsTableWidget->setObjectName("complaintsTableWidget");
        complaintsTableWidget->setGeometry(QRect(10, 90, 881, 491));
        statusFilterComboBox = new QComboBox(viewcomplaintswindow);
        statusFilterComboBox->addItem(QString());
        statusFilterComboBox->addItem(QString());
        statusFilterComboBox->addItem(QString());
        statusFilterComboBox->addItem(QString());
        statusFilterComboBox->setObjectName("statusFilterComboBox");
        statusFilterComboBox->setGeometry(QRect(750, 540, 76, 26));
        refreshButton = new QPushButton(viewcomplaintswindow);
        refreshButton->setObjectName("refreshButton");
        refreshButton->setGeometry(QRect(20, 540, 93, 29));
        viewDetailButton = new QPushButton(viewcomplaintswindow);
        viewDetailButton->setObjectName("viewDetailButton");
        viewDetailButton->setGeometry(QRect(220, 540, 111, 29));
        updateStatusButton = new QPushButton(viewcomplaintswindow);
        updateStatusButton->setObjectName("updateStatusButton");
        updateStatusButton->setGeometry(QRect(450, 540, 121, 29));

        retranslateUi(viewcomplaintswindow);

        QMetaObject::connectSlotsByName(viewcomplaintswindow);
    } // setupUi

    void retranslateUi(QWidget *viewcomplaintswindow)
    {
        viewcomplaintswindow->setWindowTitle(QCoreApplication::translate("viewcomplaintswindow", "Form", nullptr));
        label->setText(QString());
        statusFilterComboBox->setItemText(0, QCoreApplication::translate("viewcomplaintswindow", "All\n"
"", nullptr));
        statusFilterComboBox->setItemText(1, QCoreApplication::translate("viewcomplaintswindow", "\n"
"Pending\n"
"", nullptr));
        statusFilterComboBox->setItemText(2, QCoreApplication::translate("viewcomplaintswindow", "In Progress\n"
"", nullptr));
        statusFilterComboBox->setItemText(3, QCoreApplication::translate("viewcomplaintswindow", "Resolved", nullptr));

        refreshButton->setText(QCoreApplication::translate("viewcomplaintswindow", "REFRESH", nullptr));
        viewDetailButton->setText(QCoreApplication::translate("viewcomplaintswindow", "VIEW DETAIL", nullptr));
        updateStatusButton->setText(QCoreApplication::translate("viewcomplaintswindow", "UPDATE STATUS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class viewcomplaintswindow: public Ui_viewcomplaintswindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWCOMPLAINTSWINDOW_H
