// #ifndef LOGINWINDOW_H
// #define LOGINWINDOW_H

// #include <QWidget>

// namespace Ui {
// class loginwindow;
// }

// class loginwindow : public QWidget
// {
//     Q_OBJECT

// public:
//     explicit loginwindow(QWidget *parent = nullptr);
//     ~loginwindow();
//     void showNewWindow();

//     // Add static method to get the instance
//     static loginwindow* getInstance();

// private slots:
//     void on_pushButton_clicked();

//     void on_pushButton_2_clicked();

// private:
//     Ui::loginwindow *ui;
// };

// #endif // LOGINWINDOW_H
// #ifndef LOGINWINDOW_H
// #define LOGINWINDOW_H

// #include <QWidget>
// #include <QtSql>
// #include <QMessageBox>
// #include <QCryptographicHash>

// namespace Ui {
// class loginwindow;
// }

// class loginwindow : public QWidget
// {
//     Q_OBJECT

// public:
//     explicit loginwindow(QWidget *parent = nullptr);
//     ~loginwindow();
//     void showNewWindow();
//     // Add static method to get the instance
//     static loginwindow* getInstance();
//     // Database initialization
//     bool initializeDatabase();

// private slots:
//     void on_pushButton_clicked();
//     void on_pushButton_2_clicked();
//     // New slots for registration and login
//     void on_registerButton_clicked();
//     void on_loginButton_clicked();

// private:
//     Ui::loginwindow *ui;
//     QSqlDatabase db;
//     // Helper methods for database operations
//     bool createTables();
//     bool authenticateUser(const QString &username, const QString &password);
//     bool registerUser(const QString &username, const QString &password);
//     QString hashPassword(const QString &password);
// };

// #endif // LOGINWINDOW_H
#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QtSql>
#include <QMessageBox>
#include <QCryptographicHash>
#include <QDebug>

namespace Ui {
class loginwindow;
}

class loginwindow : public QWidget
{
    Q_OBJECT

public:
    explicit loginwindow(QWidget *parent = nullptr);
    ~loginwindow();
    void showNewWindow();
    // Add static method to get the instance
    static loginwindow* getInstance();
    // Database initialization
    bool initializeDatabase();

private slots:
    void on_pushButton_clicked();

    // New slots for registration and login
    void handleRegisterButton();
    void handleLoginButton();

    void on_admilogin_clicked();

private:
    Ui::loginwindow *ui;
    QSqlDatabase db;
    // Helper methods for database operations
    bool createTables();
    bool authenticateUser(const QString &username, const QString &password);
    bool registerUser(const QString &username, const QString &password);
    QString hashPassword(const QString &password);
};

#endif // LOGINWINDOW_H
