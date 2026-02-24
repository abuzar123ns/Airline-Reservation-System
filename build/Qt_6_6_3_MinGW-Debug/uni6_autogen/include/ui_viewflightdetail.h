/********************************************************************************
** Form generated from reading UI file 'viewflightdetail.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWFLIGHTDETAIL_H
#define UI_VIEWFLIGHTDETAIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_viewflightdetail
{
public:
    QTableWidget *tableWidget;
    QPushButton *Refresh;

    void setupUi(QWidget *viewflightdetail)
    {
        if (viewflightdetail->objectName().isEmpty())
            viewflightdetail->setObjectName("viewflightdetail");
        viewflightdetail->resize(808, 452);
        tableWidget = new QTableWidget(viewflightdetail);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(0, 10, 701, 431));
        Refresh = new QPushButton(viewflightdetail);
        Refresh->setObjectName("Refresh");
        Refresh->setGeometry(QRect(700, 230, 93, 29));

        retranslateUi(viewflightdetail);

        QMetaObject::connectSlotsByName(viewflightdetail);
    } // setupUi

    void retranslateUi(QWidget *viewflightdetail)
    {
        viewflightdetail->setWindowTitle(QCoreApplication::translate("viewflightdetail", "Form", nullptr));
        Refresh->setText(QCoreApplication::translate("viewflightdetail", "Refresh", nullptr));
    } // retranslateUi

};

namespace Ui {
    class viewflightdetail: public Ui_viewflightdetail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWFLIGHTDETAIL_H
