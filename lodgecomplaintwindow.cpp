// #include "lodgecomplaintwindow.h"
// #include "ui_lodgecomplaintwindow.h"
// #include "mainscreen.h"
// #include <QDir>

// // Initialize static instance pointer
// lodgecomplaintwindow* lodgecomplaintwindow::instance = nullptr;

// lodgecomplaintwindow::lodgecomplaintwindow(QWidget *parent)
//     : QWidget(parent)
//     , ui(new Ui::lodgecomplaintwindow)
// {
//     ui->setupUi(this);
//     this->resize(1100, 600);

//     // Create database tables if they don't exist
//     createComplaintsTable();

//     // Connect the lodge complaint button to its slot
//     connect(ui->lodgeComplaintButton, &QPushButton::clicked,
//             this, &lodgecomplaintwindow::on_lodgeComplaintButton_clicked);
// }

// void lodgecomplaintwindow::closeEvent(QCloseEvent *event)
// {
//     // Show the main screen when this window is closed
//     if (mainscreen::getInstance() != nullptr) {
//         mainscreen::getInstance()->show();
//     }
//     // Call the base class implementation
//     QWidget::closeEvent(event);
// }

// lodgecomplaintwindow::~lodgecomplaintwindow()
// {
//     delete ui;
//     instance = nullptr;
// }

// bool lodgecomplaintwindow::createComplaintsTable()
// {
//     QSqlDatabase db;
//     if(QSqlDatabase::contains("qt_sql_default_connection")) {
//         db = QSqlDatabase::database("qt_sql_default_connection");
//     } else {
//         db = QSqlDatabase::addDatabase("QSQLITE");
//         db.setDatabaseName("airline_database.db");
//     }

//     if (!db.open()) {
//         qDebug() << "Error opening database:" << db.lastError().text();
//         return false;
//     }

//     QSqlQuery query;
//     bool success = query.exec(
//         "CREATE TABLE IF NOT EXISTS complaints ("
//         "id INTEGER PRIMARY KEY AUTOINCREMENT, "
//         "ticket_id TEXT NOT NULL, "
//         "message TEXT NOT NULL, "
//         "submission_date TEXT NOT NULL, "
//         "status TEXT NOT NULL)"
//         );

//     if (!success) {
//         qDebug() << "Error creating complaints table:" << query.lastError().text();
//         return false;
//     }

//     return true;
// }

// bool lodgecomplaintwindow::initializeDatabase()
// {
//     QSqlDatabase db;
//     if(QSqlDatabase::contains("qt_sql_default_connection")) {
//         db = QSqlDatabase::database("qt_sql_default_connection");
//     } else {
//         db = QSqlDatabase::addDatabase("QSQLITE");
//         db.setDatabaseName("airline_database.db");
//     }

//     if (!db.open()) {
//         qDebug() << "Error opening database:" << db.lastError().text();
//         return false;
//     }

//     return true;
// }

// bool lodgecomplaintwindow::verifyTicketExists(const QString &ticketId)
// {
//     // Use the same database as booking system
//     QSqlDatabase bookingsDb = QSqlDatabase::addDatabase("QSQLITE", "verify_ticket_connection");
//     bookingsDb.setDatabaseName(QDir::currentPath() + "/airline_bookings.db");

//     if (!bookingsDb.open()) {
//         qDebug() << "Error opening bookings database:" << bookingsDb.lastError().text();
//         return false;
//     }

//     QSqlQuery query(bookingsDb);
//     // Use the correct table name - "bookings" instead of "airline_bookings"
//     query.prepare("SELECT COUNT(*) FROM bookings WHERE ticket_id = :ticket_id");
//     query.bindValue(":ticket_id", ticketId);

//     if (!query.exec()) {
//         qDebug() << "Error verifying ticket ID:" << query.lastError().text();
//         bookingsDb.close();
//         return false;
//     }

//     // Move to the first (and only) row
//     query.next();
//     int count = query.value(0).toInt();

//     bookingsDb.close();
//     QSqlDatabase::removeDatabase("verify_ticket_connection");

//     return count > 0;
// }

// void lodgecomplaintwindow::on_lodgeComplaintButton_clicked()
// {
//     // Get ticket ID and complaint message from UI elements
//     QString ticketId = ui->ticketIdLineEdit->text().trimmed();
//     QString message = ui->messageTextEdit->toPlainText().trimmed();

//     // Basic validation
//     if (ticketId.isEmpty()) {
//         QMessageBox::warning(this, "Missing Information", "Please enter your ticket ID.");
//         return;
//     }

//     if (message.isEmpty()) {
//         QMessageBox::warning(this, "Missing Information", "Please enter your complaint message.");
//         return;
//     }

//     // Verify ticket exists
//     if (!verifyTicketExists(ticketId)) {
//         QMessageBox::warning(this, "Invalid Ticket", "Ticket ID not found. Please enter a valid ticket ID.");
//         return;
//     }

//     // Save complaint to database
//     if (saveComplaintToDatabase(ticketId, message)) {
//         QMessageBox::information(this, "Success",
//                                  "Your complaint has been submitted successfully.");
//         // Clear the form fields
//         ui->ticketIdLineEdit->clear();
//         ui->messageTextEdit->clear();
//     } else {
//         QMessageBox::critical(this, "Error",
//                               "Failed to submit your complaint. Please try again later.");
//     }
// }

// bool lodgecomplaintwindow::saveComplaintToDatabase(const QString &ticketId, const QString &message)
// {
//     if (!initializeDatabase()) {
//         return false;
//     }

//     QSqlQuery query;
//     query.prepare("INSERT INTO complaints (ticket_id, message, submission_date, status) "
//                   "VALUES (:ticket_id, :message, :date, :status)");
//     query.bindValue(":ticket_id", ticketId);
//     query.bindValue(":message", message);
//     query.bindValue(":date", QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
//     query.bindValue(":status", "Pending");

//     if (!query.exec()) {
//         qDebug() << "Error saving complaint:" << query.lastError().text();
//         return false;
//     }

//     return true;
// }
#include "lodgecomplaintwindow.h"
#include "ui_lodgecomplaintwindow.h"
#include "mainscreen.h"
#include <QDir>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QDateTime>

// Initialize static instance pointer
lodgecomplaintwindow* lodgecomplaintwindow::instance = nullptr;

lodgecomplaintwindow::lodgecomplaintwindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::lodgecomplaintwindow)
{
    ui->setupUi(this);
    this->resize(1100, 600);

    // Create database tables if they don't exist
    createComplaintsTable();

    // Connect the lodge complaint button to its slot
    connect(ui->lodgeComplaintButton, &QPushButton::clicked,
            this, &lodgecomplaintwindow::on_lodgeComplaintButton_clicked);
}

void lodgecomplaintwindow::closeEvent(QCloseEvent *event)
{
    // Show the main screen when this window is closed
    if (mainscreen::getInstance() != nullptr) {
        mainscreen::getInstance()->show();
    }
    // Call the base class implementation
    QWidget::closeEvent(event);
}

lodgecomplaintwindow::~lodgecomplaintwindow()
{
    delete ui;
    instance = nullptr;
}

bool lodgecomplaintwindow::createComplaintsTable()
{
    // Initialize the complaints database
    QSqlDatabase complaintsDb;

    // Use a unique connection name for the complaints database
    if(QSqlDatabase::contains("complaints_connection")) {
        complaintsDb = QSqlDatabase::database("complaints_connection");
    } else {
        complaintsDb = QSqlDatabase::addDatabase("QSQLITE", "complaints_connection");
        complaintsDb.setDatabaseName(QDir::currentPath() + "/complaints_database.db");
    }

    if (!complaintsDb.open()) {
        qDebug() << "Error opening complaints database:" << complaintsDb.lastError().text();
        return false;
    }

    QSqlQuery query(complaintsDb);
    bool success = query.exec(
        "CREATE TABLE IF NOT EXISTS complaints ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "ticket_id TEXT NOT NULL, "
        "message TEXT NOT NULL, "
        "submission_date TEXT NOT NULL, "
        "status TEXT DEFAULT 'Pending')"
        );

    if (!success) {
        qDebug() << "Error creating complaints table:" << query.lastError().text();
        return false;
    }

    qDebug() << "Complaints table created or verified successfully";
    return true;
}

bool lodgecomplaintwindow::verifyTicketExists(const QString &ticketId)
{
    // Create a separate connection for verifying tickets in the bookings database
    QSqlDatabase bookingsDb = QSqlDatabase::addDatabase("QSQLITE", "verify_ticket_connection");
    bookingsDb.setDatabaseName(QDir::currentPath() + "/airline_bookings.db");

    if (!bookingsDb.open()) {
        qDebug() << "Error opening bookings database:" << bookingsDb.lastError().text();
        return false;
    }

    QSqlQuery query(bookingsDb);
    // Use the correct table name from the booking system
    query.prepare("SELECT COUNT(*) FROM bookings WHERE ticket_id = :ticket_id");
    query.bindValue(":ticket_id", ticketId);

    if (!query.exec()) {
        qDebug() << "Error verifying ticket ID:" << query.lastError().text();
        bookingsDb.close();
        QSqlDatabase::removeDatabase("verify_ticket_connection");
        return false;
    }

    // Move to the first (and only) row
    query.next();
    int count = query.value(0).toInt();

    bookingsDb.close();
    QSqlDatabase::removeDatabase("verify_ticket_connection");

    return count > 0;
}

void lodgecomplaintwindow::on_lodgeComplaintButton_clicked()
{
    // Get ticket ID and complaint message from UI elements
    QString ticketId = ui->ticketIdLineEdit->text().trimmed();
    QString message = ui->messageTextEdit->toPlainText().trimmed();

    // Basic validation
    if (ticketId.isEmpty()) {
        QMessageBox::warning(this, "Missing Information", "Please enter your ticket ID.");
        return;
    }

    if (message.isEmpty()) {
        QMessageBox::warning(this, "Missing Information", "Please enter your complaint message.");
        return;
    }

    // Verify ticket exists in bookings database
    if (!verifyTicketExists(ticketId)) {
        QMessageBox::warning(this, "Invalid Ticket", "Ticket ID not found. Please enter a valid ticket ID.");
        return;
    }

    // Save complaint to database
    if (saveComplaintToDatabase(ticketId, message)) {
        QMessageBox::information(this, "Success",
                                 "Your complaint has been submitted successfully.");
        // Clear the form fields
        ui->ticketIdLineEdit->clear();
        ui->messageTextEdit->clear();
    } else {
        QMessageBox::critical(this, "Error",
                              "Failed to submit your complaint. Please try again later.");
    }
}

bool lodgecomplaintwindow::saveComplaintToDatabase(const QString &ticketId, const QString &message)
{
    // Use the complaints database connection
    QSqlDatabase complaintsDb;

    if(QSqlDatabase::contains("complaints_connection")) {
        complaintsDb = QSqlDatabase::database("complaints_connection");
    } else {
        complaintsDb = QSqlDatabase::addDatabase("QSQLITE", "complaints_connection");
        complaintsDb.setDatabaseName(QDir::currentPath() + "/complaints_database.db");
    }

    if (!complaintsDb.open()) {
        qDebug() << "Error opening complaints database:" << complaintsDb.lastError().text();
        return false;
    }

    QSqlQuery query(complaintsDb);
    query.prepare("INSERT INTO complaints (ticket_id, message, submission_date, status) "
                  "VALUES (:ticket_id, :message, :date, :status)");
    query.bindValue(":ticket_id", ticketId);
    query.bindValue(":message", message);
    query.bindValue(":date", QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    query.bindValue(":status", "Pending");

    if (!query.exec()) {
        qDebug() << "Error saving complaint:" << query.lastError().text();
        return false;
    }

    qDebug() << "Complaint saved successfully for ticket:" << ticketId;
    return true;
}
