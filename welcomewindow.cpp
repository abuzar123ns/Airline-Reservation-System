#include "welcomewindow.h"
#include "./ui_welcomewindow.h"
#include "loginwindow.h"
#include "ui_loginwindow.h"
// Initialize static instance
welcomewindow *welcomewindow::instance = nullptr;
welcomewindow::welcomewindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::welcomewindow)
{
    ui->setupUi(this);
    this->resize(1100, 600);
    this->setWindowTitle("Welcome Window");  // Set title for the welcome window
    instance = this;  // Store instance for later reference
}

welcomewindow::~welcomewindow()
{
    delete ui;
}

void welcomewindow::on_pushButton_2_clicked()
{
    // Create login window without parent
    loginwindow *Loginwindow = new loginwindow();
    Loginwindow->setWindowTitle("Login Window");
    Loginwindow->show();
    this->hide();
}

