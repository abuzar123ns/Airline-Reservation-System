
// #ifndef BOOKFLIGHTWINDOW_H
// #define BOOKFLIGHTWINDOW_H

// #include <QWidget>
// #include <QSqlDatabase>
// #include <QSqlQuery>
// #include <QSqlError>
// #include <QRandomGenerator>
// #include <QCheckBox>
// #include <QCloseEvent>

// namespace Ui {
// class bookflightwindow;
// }

// class bill;

// class bookflightwindow : public QWidget
// {
//     Q_OBJECT

// public:
//     // Modified constructor to accept an editMode parameter
//     explicit bookflightwindow(QWidget *parent = nullptr, bool editMode = false);
//     ~bookflightwindow();

//     // New method to load booking data for editing
//     bool loadBookingForEdit(const QString& ticketId);

// signals:
//     void sendBookingDetails(
//         const QString& firstName,
//         const QString& lastName,
//         const QString& phoneNumber,
//         const QString& flightAvailable,
//         const QString& departureDate,
//         const QString& flyingFrom,
//         const QString& flyingTo,
//         const QString& seatNumber,
//         const QString& seatClass,
//         double totalCost,
//         const QString& ticketId
//         );

// protected:
//     void closeEvent(QCloseEvent *event) override;

// private slots:
//     void on_pushButton_clicked();
//     void onCheckboxToggled(bool checked);

// private:
//     Ui::bookflightwindow *ui;
//     bill *billWindow;
//     QSqlDatabase db;
//     QString currentTicketId;
//     bool isEditMode;  // New flag to track if we're editing an existing booking

//     bool initializeDatabase();
//     bool createTables();
//     QString generateUniqueTicketId();
//     bool isTicketIdUnique(const QString& ticketId);
//     bool saveBookingToDatabase(
//         const QString& ticketId,
//         const QString& firstName,
//         const QString& lastName,
//         const QString& phoneNumber,
//         const QString& flightAvailable,
//         const QString& departureDate,
//         const QString& flyingFrom,
//         const QString& flyingTo,
//         const QString& seatNumber,
//         const QString& seatClass,
//         double totalCost,
//         const QString& mealType,
//         bool wifiAccess,
//         const QString& paymentMethod
//         );

//     // New method to update existing booking
//     bool updateBookingInDatabase(
//         const QString& ticketId,
//         const QString& firstName,
//         const QString& lastName,
//         const QString& phoneNumber,
//         const QString& flightAvailable,
//         const QString& departureDate,
//         const QString& flyingFrom,
//         const QString& flyingTo,
//         const QString& seatNumber,
//         const QString& seatClass,
//         double totalCost,
//         const QString& mealType,
//         bool wifiAccess,
//         const QString& paymentMethod
//         );

//     void setupCheckboxConnections();
//     double calculateBill(const QString& seatClass, const QString& seatNumber);
//     void showBillWindow();
// };

// #endif // BOOKFLIGHTWINDOW_H
#ifndef BOOKFLIGHTWINDOW_H
#define BOOKFLIGHTWINDOW_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QRandomGenerator>
#include <QCloseEvent>

namespace Ui {
class bookflightwindow;
}

class bill;

class bookflightwindow : public QWidget
{
    Q_OBJECT

public:
    // Modified constructor to accept editMode parameter with default value of false
    explicit bookflightwindow(QWidget *parent = nullptr, bool editMode = false);
    ~bookflightwindow();

    // New method to load booking data for editing
    bool loadBookingForEdit(const QString& ticketId);

signals:
    // Signal to send booking details to bill window
    void sendBookingDetails(
        const QString& firstName,
        const QString& lastName,
        const QString& phoneNumber,
        const QString& flightAvailable,
        const QString& departureDate,
        const QString& flyingFrom,
        const QString& flyingTo,
        const QString& seatNumber,
        const QString& seatClass,
        double totalCost,
        const QString& ticketId
        );

private slots:
    void on_pushButton_clicked();
    void onCheckboxToggled(bool checked);

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::bookflightwindow *ui;
    bill *billWindow;
    QSqlDatabase db;
    QString currentTicketId;
    bool isEditMode;  // Flag to indicate if we're in edit mode

    bool initializeDatabase();
    bool createTables();
    QString generateUniqueTicketId();
    bool isTicketIdUnique(const QString& ticketId);

    bool saveBookingToDatabase(
        const QString& ticketId,
        const QString& firstName,
        const QString& lastName,
        const QString& phoneNumber,
        const QString& flightAvailable,
        const QString& departureDate,
        const QString& flyingFrom,
        const QString& flyingTo,
        const QString& seatNumber,
        const QString& seatClass,
        double totalCost,
        const QString& mealType,
        bool wifiAccess,
        const QString& paymentMethod
        );

    // New method to update existing booking in database
    bool updateBookingInDatabase(
        const QString& ticketId,
        const QString& firstName,
        const QString& lastName,
        const QString& phoneNumber,
        const QString& flightAvailable,
        const QString& departureDate,
        const QString& flyingFrom,
        const QString& flyingTo,
        const QString& seatNumber,
        const QString& seatClass,
        double totalCost,
        const QString& mealType,
        bool wifiAccess,
        const QString& paymentMethod
        );

    void setupCheckboxConnections();
    double calculateBill(const QString& seatClass, const QString& seatNumber);
    void showBillWindow();
};

#endif // BOOKFLIGHTWINDOW_H
