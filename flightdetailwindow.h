// #ifndef FLIGHTDETAILWINDOW_H
// #define FLIGHTDETAILWINDOW_H

// #include <QWidget>
// #include <QCloseEvent>

// namespace Ui {
// class flightdetailwindow;
// }

// class flightdetailwindow : public QWidget
// {
//     Q_OBJECT

// public:
//     explicit flightdetailwindow(QWidget *parent = nullptr);
//     ~flightdetailwindow();

// protected:
//     void closeEvent(QCloseEvent *event) override;

// private:
//     Ui::flightdetailwindow *ui;
// };

// #endif // FLIGHTDETAILWINDOW_H
#ifndef FLIGHTDETAILWINDOW_H
#define FLIGHTDETAILWINDOW_H

#include <QWidget>
#include <QCloseEvent>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
class flightdetailwindow;
}

class flightdetailwindow : public QWidget
{
    Q_OBJECT

public:
    explicit flightdetailwindow(QWidget *parent = nullptr);
    ~flightdetailwindow();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_searchButton_clicked(); // Search button handler

private:
    Ui::flightdetailwindow *ui;
    QSqlDatabase db; // Database connection

    bool initializeDatabase(); // Initialize database connection
};

#endif // FLIGHTDETAILWINDOW_H
