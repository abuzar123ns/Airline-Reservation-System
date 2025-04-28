// #ifndef VIEWFLIGHTDETAIL_H
// #define VIEWFLIGHTDETAIL_H

// #include <QMainWindow>
// #include <QSqlDatabase>
// #include <QTableWidgetItem>

// namespace Ui {
// class ViewFlightDetail;
// }

// class ViewFlightDetail : public QMainWindow
// {
//     Q_OBJECT

// public:
//     explicit ViewFlightDetail(QWidget *parent = nullptr);
//     ~ViewFlightDetail();

//     // Create singleton instance
//     static ViewFlightDetail* getInstance() {
//         if (!instance)
//             instance = new ViewFlightDetail();
//         return instance;
//     }

// protected:
//     void closeEvent(QCloseEvent *event) override;

// private:
//     Ui::ViewFlightDetail *ui;
//     static ViewFlightDetail* instance;

//     // Database connection
//     bool initializeDatabase();
//     void loadBookingDetails();
// };

// #endif // VIEWFLIGHTDETAIL_H
// #ifndef VIEWFLIGHTDETAIL_H
// #define VIEWFLIGHTDETAIL_H

// #include <QMainWindow>

// // Forward declaration of the UI namespace and class
// namespace Ui {
// class viewflightdetail;
// }

// class viewflightdetail : public QMainWindow
// {
//     Q_OBJECT

// public:
//     explicit viewflightdetail(QWidget *parent = nullptr);
//     ~viewflightdetail();

//     static viewflightdetail* getInstance();

// protected:
//     void closeEvent(QCloseEvent *event) override;

// private:
//     static viewflightdetail* instance;
//     Ui::viewflightdetail *ui;  // Pointer to UI class

//     bool initializeDatabase();
//     void loadBookingDetails();
// };

// #endif // VIEWFLIGHTDETAIL_H
#ifndef VIEWFLIGHTDETAIL_H
#define VIEWFLIGHTDETAIL_H

#include <QMainWindow>
#include <QSqlDatabase>

namespace Ui {
class viewflightdetail;
}

class viewflightdetail : public QMainWindow
{
    Q_OBJECT

public:
    explicit viewflightdetail(QWidget *parent = nullptr);
    ~viewflightdetail();

    // Singleton pattern method
    static viewflightdetail* getInstance();

public slots:
    // Add a method to refresh the bookings data
    void refreshBookings();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::viewflightdetail *ui;
    static viewflightdetail* instance;
    QSqlDatabase db;

    bool initializeDatabase();
    void loadBookingDetails();
};

#endif // VIEWFLIGHTDETAIL_H
