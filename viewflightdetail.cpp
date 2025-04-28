// #include "viewflightdetail.h"
// #include "ui_viewflightdetail.h"
// #include "mainscreen.h"
// #include <QMessageBox>
// #include <QDebug>
// #include <QCloseEvent>
// #include <QSqlQuery>
// #include <QSqlError>
// #include <QSqlDatabase>
// #include <QHeaderView>

// // Initialize static instance pointer
// ViewFlightDetail* ViewFlightDetail::instance = nullptr;

// ViewFlightDetail::ViewFlightDetail(QWidget *parent) :
//     QMainWindow(parent),
//     ui(new Ui::ViewFlightDetail)
// {
//     ui->setupUi(this);
//     this->resize(1100, 600);

//     // Set up table column headers
//     ui->tableWidget->setColumnCount(7);
//     QStringList headers;
//     headers << "Ticket ID" << "Name" << "From" << "To" << "Seat Class" << "Number of Seats" << "Bill";
//     ui->tableWidget->setHorizontalHeaderLabels(headers);

//     // Initialize database and load booking details
//     if (initializeDatabase()) {
//         loadBookingDetails();
//     }

//     // Make columns stretch to fill the table width
//     ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
// }

// ViewFlightDetail::~ViewFlightDetail()
// {
//     delete ui;
//     instance = nullptr;
// }

// void ViewFlightDetail::closeEvent(QCloseEvent *event)
// {
//     // Show the main screen when this window is closed
//     if (mainscreen::getInstance() != nullptr) {
//         mainscreen::getInstance()->show();
//     }
//     // Call the base class implementation
//     QMainWindow::closeEvent(event);
// }

// bool ViewFlightDetail::initializeDatabase()
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
//         QMessageBox::critical(this, "Database Connection Failed",
//                               "Could not connect to the database: " + db.lastError().text());
//         return false;
//     }

//     return true;
// }

// void ViewFlightDetail::loadBookingDetails()
// {
//     QSqlQuery query;
//     if (!query.exec("SELECT ticket_id, passenger_name, departure, destination, seat_class, num_seats, total_fare "
//                     "FROM airline_bookings ORDER BY ticket_id DESC")) {
//         QMessageBox::critical(this, "Error",
//                               "Failed to load booking details: " + query.lastError().text());
//         qDebug() << "Query error:" << query.lastError().text();
//         return;
//     }

//     // Clear existing table data
//     ui->tableWidget->setRowCount(0);

//     int row = 0;
//     while (query.next()) {
//         ui->tableWidget->insertRow(row);

//         // Add data to each column
//         ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString())); // Ticket ID
//         ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString())); // Name
//         ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value(2).toString())); // From
//         ui->tableWidget->setItem(row, 3, new QTableWidgetItem(query.value(3).toString())); // To
//         ui->tableWidget->setItem(row, 4, new QTableWidgetItem(query.value(4).toString())); // Seat Class
//         ui->tableWidget->setItem(row, 5, new QTableWidgetItem(query.value(5).toString())); // Number of Seats
//         ui->tableWidget->setItem(row, 6, new QTableWidgetItem("$" + query.value(6).toString())); // Bill

//         row++;
//     }

//     // Auto-resize rows to contents
//     ui->tableWidget->resizeRowsToContents();
// }
// #include "viewflightdetail.h"
// #include "ui_viewflightdetail.h"  // Must be included first to ensure UI class is complete
// #include "mainscreen.h"

// #include <QMessageBox>
// #include <QDebug>
// #include <QCloseEvent>
// #include <QSqlQuery>
// #include <QSqlError>
// #include <QSqlDatabase>
// #include <QHeaderView>

// // Initialize static instance pointer
// viewflightdetail* viewflightdetail::instance = nullptr;

// viewflightdetail::viewflightdetail(QWidget *parent) :
//     QMainWindow(parent),
//     ui(new Ui::viewflightdetail)
// {
//     ui->setupUi(this);
//     this->resize(1100, 600);

//     // Set up table column headers
//     ui->tableWidget->setColumnCount(7);
//     QStringList headers;
//     headers << "Ticket ID" << "Name" << "From" << "To" << "Seat Class" << "Number of Seats" << "Bill";
//     ui->tableWidget->setHorizontalHeaderLabels(headers);

//     // Initialize database and load booking details
//     if (initializeDatabase()) {
//         loadBookingDetails();
//     }

//     // Make columns stretch to fill the table width
//     ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
// }

// viewflightdetail::~viewflightdetail()
// {
//     delete ui;
//     instance = nullptr;
// }

// void viewflightdetail::closeEvent(QCloseEvent *event)
// {
//     // Show the main screen when this window is closed
//     if (mainscreen::getInstance() != nullptr) {
//         mainscreen::getInstance()->show();
//     }

//     // Call the base class implementation
//     QMainWindow::closeEvent(event);
// }

// bool viewflightdetail::initializeDatabase()
// {
//     QSqlDatabase db;
//     if (QSqlDatabase::contains("qt_sql_default_connection")) {
//         db = QSqlDatabase::database("qt_sql_default_connection");
//     } else {
//         db = QSqlDatabase::addDatabase("QSQLITE");
//         db.setDatabaseName("airline_database.db");
//     }

//     if (!db.open()) {
//         qDebug() << "Error opening database:" << db.lastError().text();
//         QMessageBox::critical(this, "Database Connection Failed",
//                               "Could not connect to the database: " + db.lastError().text());
//         return false;
//     }

//     return true;
// }

// void viewflightdetail::loadBookingDetails()
// {
//     QSqlQuery query;
//     if (!query.exec("SELECT ticket_id, passenger_name, departure, destination, seat_class, num_seats, total_fare "
//                     "FROM airline_bookings ORDER BY ticket_id DESC")) {
//         QMessageBox::critical(this, "Error",
//                               "Failed to load booking details: " + query.lastError().text());
//         qDebug() << "Query error:" << query.lastError().text();
//         return;
//     }

//     // Clear existing table data
//     ui->tableWidget->setRowCount(0);

//     int row = 0;
//     while (query.next()) {
//         ui->tableWidget->insertRow(row);
//         ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString())); // Ticket ID
//         ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString())); // Name
//         ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value(2).toString())); // From
//         ui->tableWidget->setItem(row, 3, new QTableWidgetItem(query.value(3).toString())); // To
//         ui->tableWidget->setItem(row, 4, new QTableWidgetItem(query.value(4).toString())); // Seat Class
//         ui->tableWidget->setItem(row, 5, new QTableWidgetItem(query.value(5).toString())); // Number of Seats
//         ui->tableWidget->setItem(row, 6, new QTableWidgetItem("$" + query.value(6).toString())); // Bill
//         row++;
//     }

//     // Auto-resize rows to contents
//     ui->tableWidget->resizeRowsToContents();
// }

// viewflightdetail* viewflightdetail::getInstance()
// {
//     if (instance == nullptr) {
//         instance = new viewflightdetail();
//     }
//     return instance;
// }
#include "viewflightdetail.h"
#include "ui_viewflightdetail.h"  // Must be included first to ensure UI class is complete
#include "mainscreen.h"
#include <QMessageBox>
#include <QDebug>
#include <QCloseEvent>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QHeaderView>
#include <QDir>

// Initialize static instance pointer
viewflightdetail* viewflightdetail::instance = nullptr;

viewflightdetail::viewflightdetail(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::viewflightdetail)
{
    ui->setupUi(this);
    this->resize(1100, 600);

    // Set up table column headers - only show the requested fields
    ui->tableWidget->setColumnCount(6);
    QStringList headers;
    headers << "Ticket ID" << "Name" << "From" << "To" << "Seat Class" << "No. of Seats";
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    // Initialize database and load booking details
    if (initializeDatabase()) {
        loadBookingDetails();
    }

    // Make columns stretch to fill the table width
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

viewflightdetail::~viewflightdetail()
{
    // Close the database connection if open
    if (db.isOpen()) {
        db.close();
        QSqlDatabase::removeDatabase("view_bookings_connection");
    }

    delete ui;
    instance = nullptr;
}

void viewflightdetail::closeEvent(QCloseEvent *event)
{
    // Show the main screen when this window is closed
    if (mainscreen::getInstance() != nullptr) {
        mainscreen::getInstance()->show();
    }
    // Call the base class implementation
    QMainWindow::closeEvent(event);
}

bool viewflightdetail::initializeDatabase()
{
    // Setup the SQLite database with a unique connection name
    db = QSqlDatabase::addDatabase("QSQLITE", "view_bookings_connection");

    // Set the database file path - use the same DB as bookflightwindow
    QString dbPath = QDir::currentPath() + "/airline_bookings.db";
    qDebug() << "Viewing bookings database path:" << dbPath;
    db.setDatabaseName(dbPath);

    // Open the database
    if (!db.open()) {
        qDebug() << "Failed to open bookings database:" << db.lastError().text();
        QMessageBox::critical(this, "Database Error",
                              "Failed to open bookings database: " + db.lastError().text());
        return false;
    }

    qDebug() << "Bookings database opened successfully for viewing";
    return true;
}

void viewflightdetail::loadBookingDetails()
{
    QSqlQuery query(db);

    // Use the correct table name and fields from bookflightwindow
    if (!query.exec("SELECT ticket_id, first_name, last_name, flying_from, flying_to, "
                    "seat_class, seat_number FROM bookings ORDER BY booking_timestamp DESC")) {
        QMessageBox::critical(this, "Error",
                              "Failed to load booking details: " + query.lastError().text());
        qDebug() << "Query error:" << query.lastError().text();
        return;
    }

    // Clear existing table data
    ui->tableWidget->setRowCount(0);

    int row = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(row);

        // Ticket ID
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));

        // Full Name (combining first_name and last_name)
        QString fullName = query.value(1).toString() + " " + query.value(2).toString();
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(fullName));

        // From
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value(3).toString()));

        // To
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(query.value(4).toString()));

        // Seat Class
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(query.value(5).toString()));

        // Number of Seats (in the original database this is actually seat_number)
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(query.value(6).toString()));

        row++;
    }

    // Auto-resize rows to contents
    ui->tableWidget->resizeRowsToContents();

    qDebug() << "Loaded" << row << "booking records";
}

viewflightdetail* viewflightdetail::getInstance()
{
    if (instance == nullptr) {
        instance = new viewflightdetail();
    }
    return instance;
}

// Add a public slot to refresh the data
void viewflightdetail::refreshBookings()
{
    loadBookingDetails();
}
