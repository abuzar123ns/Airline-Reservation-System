// #ifndef ADMINLOGIN_H
// #define ADMINLOGIN_H

// #include <QWidget>

// namespace Ui {
// class adminlogin;
// }

// class adminlogin : public QWidget
// {
//     Q_OBJECT

// public:
//     explicit adminlogin(QWidget *parent = nullptr);
//     ~adminlogin();

// private:
//     Ui::adminlogin *ui;
// };

// #endif // ADMINLOGIN_H
#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

// Forward declaration of loginwindow class
class loginwindow;

namespace Ui {
class adminlogin;
}

class adminlogin : public QWidget
{
    Q_OBJECT

public:
    explicit adminlogin(QWidget *parent = nullptr);
    ~adminlogin();

    // Static method to get the instance
    static adminlogin* getInstance();

private slots:
    // Custom handler for the login button
    void handleAdminLogin();

    // // Back button handler
    // void on_backButton_clicked();

private:
    Ui::adminlogin *ui;

    // Method to open the admin portal window
    void showAdminPortal();
};

#endif // ADMINLOGIN_H
