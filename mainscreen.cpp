// #include "mainscreen.h"
// #include "ui_mainscreen.h"
// #include "bookflightwindow.h"
// #include "flightdetailwindow.h"
// #include "lodgecomplaintwindow.h"

// mainscreen::mainscreen(QWidget *parent)
//     : QWidget(parent)
//     , ui(new Ui::mainscreen)
// {
//     ui->setupUi(this);
//     this->setWindowTitle("Main Screen");
// }

// void mainscreen::on_pushButton_4_clicked()
// {
//     flightdetailwindow *Flightdetailwindow = new flightdetailwindow();  // Remove parent
//     Flightdetailwindow->show();
//     this->hide();
// }

// void mainscreen::on_pushButton_5_clicked()
// {
//     lodgecomplaintwindow *Lodgecomplaintwindow = new lodgecomplaintwindow();  // Remove parent
//     Lodgecomplaintwindow->show();
//     this->hide();
// }

// void mainscreen::on_pushButton_clicked()
// {
//     bookflightwindow *Bookflightwindow = new bookflightwindow();  // Remove parent
//     Bookflightwindow->show();
//     this->hide();
// }

// void mainscreen::showNewWindow()
// {
//     bookflightwindow *Bookflightwindow = new bookflightwindow();  // Remove parent
//     Bookflightwindow->show();
//     this->hide();
// }

// mainscreen::~mainscreen()
// {
//     delete ui;
// }
#include "mainscreen.h"
#include "ui_mainscreen.h"
#include "bookflightwindow.h"
#include "flightdetailwindow.h"
#include "lodgecomplaintwindow.h"

// Add a static pointer to store the instance
static mainscreen* mainScreenInstance = nullptr;

mainscreen::mainscreen(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mainscreen)
{
    ui->setupUi(this);
    this->resize(1100, 600);
    this->setWindowTitle("Main Screen");

    // Store the instance
    mainScreenInstance = this;
}

void mainscreen::on_pushButton_4_clicked()
{
    flightdetailwindow *Flightdetailwindow = new flightdetailwindow();
    Flightdetailwindow->show();
    this->hide();
}

void mainscreen::on_pushButton_5_clicked()
{
    lodgecomplaintwindow* Lodgecomplaintwindow = lodgecomplaintwindow::getInstance();
    Lodgecomplaintwindow->show();
    this->hide();
}

void mainscreen::on_pushButton_clicked()
{
    bookflightwindow *Bookflightwindow = new bookflightwindow();
    Bookflightwindow->show();
    this->hide();
}

void mainscreen::showNewWindow()
{
    bookflightwindow *Bookflightwindow = new bookflightwindow();
    Bookflightwindow->show();
    this->hide();
}

// Add this public static method
mainscreen* mainscreen::getInstance()
{
    return mainScreenInstance;
}

mainscreen::~mainscreen()
{
    mainScreenInstance = nullptr;
    delete ui;
}
