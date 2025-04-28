#include "adminlogin.h"
#include "ui_adminlogin.h"
#include "adminportal.h"
#include <QMessageBox>
#include <QDebug>

// Static pointer for singleton pattern (similar to loginwindow)
static adminlogin* adminLoginInstance = nullptr;

adminlogin::adminlogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminlogin)
{
    ui->setupUi(this);
    this->resize(1100, 600);

    // Store the instance
    adminLoginInstance = this;

    // Connect the login button to the handler function
    connect(ui->loginButton, &QPushButton::clicked, this, &adminlogin::handleAdminLogin);
}

adminlogin::~adminlogin()
{
    adminLoginInstance = nullptr;
    delete ui;
}

void adminlogin::handleAdminLogin()
{
    QString username = ui->username->text();
    QString password = ui->password->text();

    qDebug() << "Admin login attempt for:" << username;

    // Basic validation
    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Login Error", "Username and password cannot be empty.");
        return;
    }

    // Check for authorized admin users
    if ((username == "Hassan" || username == "Arquam" || username == "Abuzar") &&
        password == "admin123") {
        QMessageBox::information(this, "Admin Login Successful",
                                 "Welcome Administrator " + username + "!");
        showAdminPortal();
    } else {
        QMessageBox::warning(this, "Admin Login Failed",
                             "Invalid admin credentials. Access denied.");
    }
}

void adminlogin::showAdminPortal()
{
    // Create and show the admin portal window
    adminportal *Adminportal = new adminportal();
    Adminportal->show();
    this->hide();  // Hide the admin login window
}

// Static method to access the instance
adminlogin* adminlogin::getInstance()
{
    return adminLoginInstance;
}

//*/ Back button to return to main login screen (if needed)
// void adminlogin::on_backButton_clicked()
// {
//     // Assuming you have a way to get back to the login window
//     if (loginwindow::getInstance()) {
//         loginwindow::getInstance()->show();
//         this->hide();
//     } else {
//         // Fallback - create a new login window if instance doesn't exist
//         loginwindow *loginScreen = new loginwindow();
//         loginScreen->show();
//         this->hide();
//     }
// }*/
