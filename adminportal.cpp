#include "adminportal.h"
#include "ui_adminportal.h"
#include "viewcomplaintswindow.h"
#include "viewflightdetail.h"
#include "updateticket.h"
adminportal::adminportal(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::adminportal)
{
    ui->setupUi(this);
}

adminportal::~adminportal()
{
    delete ui;
}

void adminportal::on_pushButton_clicked()
{
    viewcomplaintswindow *Viewcomplaintswindow = new viewcomplaintswindow();
    Viewcomplaintswindow->setWindowTitle("View Complaint Window");
   Viewcomplaintswindow->show();
    this->hide();
}


void adminportal::on_viewflightdetail_clicked()
{
    viewflightdetail *Viewflightdetail = new viewflightdetail();
    Viewflightdetail->setWindowTitle("View flightdetail Window");
    Viewflightdetail->show();
    this->hide();
}


// void adminportal::on_pushButton_2_clicked()
// {
//     updateticket *Updateticket = new updateticket();
//     Updateticket->setWindowTitle("View flightdetail Window");
//     Updateticket->show();
//     this->hide();
// }
void adminportal::on_pushButton_2_clicked()
{
    updateticket * Updateticket = new updateticket();
    Updateticket->setWindowTitle("View flightdetail Window");
    Updateticket->show();
    this->hide();
}
