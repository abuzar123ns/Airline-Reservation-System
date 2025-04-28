// #include "flightdetailwindow.h"
// #include "ui_flightdetailwindow.h"
// #include "mainscreen.h"

// flightdetailwindow::flightdetailwindow(QWidget *parent)
//     : QWidget(parent)
//     , ui(new Ui::flightdetailwindow)
// {
//     ui->setupUi(this);
//     this->resize(1100, 600);
// }

// void flightdetailwindow::closeEvent(QCloseEvent *event)
// {
//     // Show the main screen when this window is closed
//     if (mainscreen::getInstance() != nullptr) {
//         mainscreen::getInstance()->show();
//     }

//     // Call the base class implementation
//     QWidget::closeEvent(event);
// }

// flightdetailwindow::~flightdetailwindow()
// {
//     delete ui;
// }
#include "flightdetailwindow.h"
#include "ui_flightdetailwindow.h"
#include "mainscreen.h"
#include <QMessageBox>
#include <QDebug>
#include <QDir>

flightdetailwindow::flightdetailwindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::flightdetailwindow)
{
    ui->setupUi(this);
    this->resize(1100, 600);

    // Initialize the database connection
    if (!initializeDatabase()) {
        QMessageBox::critical(this, "Database Error", "Failed to connect to the booking database.");
    }

    // Connect search button to its handler
    connect(ui->searchButton, &QPushButton::clicked, this, &flightdetailwindow::on_searchButton_clicked);
}

bool flightdetailwindow::initializeDatabase()
{
    // Setup the SQLite database with a unique connection name
    db = QSqlDatabase::addDatabase("QSQLITE", "flight_details_connection");

    // Set the database file path (use the same database as in bookflightwindow)
    QString dbPath = QDir::currentPath() + "/airline_bookings.db";
    qDebug() << "Flight details database path:" << dbPath;
    db.setDatabaseName(dbPath);

    // Open the database
    if (!db.open()) {
        qDebug() << "Failed to open flight details database:" << db.lastError().text();
        return false;
    }

    qDebug() << "Flight details database opened successfully";
    return true;
}

void flightdetailwindow::on_searchButton_clicked()
{
    // Get the ticket ID from the input field
    QString ticketId = ui->ticketIdInput->text().trimmed();

    if (ticketId.isEmpty()) {
        QMessageBox::warning(this, "Missing Information", "Please enter a ticket ID.");
        return;
    }

    // Query the database for the booking details
    QSqlQuery query(db);
    query.prepare("SELECT first_name, last_name, phone_number, flight_available, "
                  "departure_date, flying_from, flying_to, seat_number, seat_class, "
                  "total_cost, meal_type, wifi_access, payment_method "
                  "FROM bookings WHERE ticket_id = :ticket_id");
    query.bindValue(":ticket_id", ticketId);

    if (!query.exec()) {
        qDebug() << "Search query failed:" << query.lastError().text();
        QMessageBox::critical(this, "Database Error",
                              "Failed to search for ticket: " + query.lastError().text());
        return;
    }

    // Check if any records were found
    if (query.next()) {
        // Retrieve data from the query result
        QString firstName = query.value("first_name").toString();
        QString lastName = query.value("last_name").toString();
        QString phoneNumber = query.value("phone_number").toString();
        QString flightAvailable = query.value("flight_available").toString();
        QString departureDate = query.value("departure_date").toString();
        QString flyingFrom = query.value("flying_from").toString();
        QString flyingTo = query.value("flying_to").toString();
        QString seatNumber = query.value("seat_number").toString();
        QString seatClass = query.value("seat_class").toString();
        double totalCost = query.value("total_cost").toDouble();
        QString mealType = query.value("meal_type").toString();
        bool wifiAccess = query.value("wifi_access").toBool();
        QString paymentMethod = query.value("payment_method").toString();

        // Concatenate first name and last name
        QString fullName = firstName + " " + lastName;

        // Update UI with retrieved data
        ui->ticketIdLabel->setText(ticketId);
        ui->nameLabel->setText(fullName);
        ui->phoneLabel->setText(phoneNumber);
        ui->flightLabel->setText(flightAvailable);
        ui->dateLabel->setText(departureDate);
        ui->fromLabel->setText(flyingFrom);
        ui->toLabel->setText(flyingTo);
        ui->seatNumberLabel->setText(seatNumber);
        ui->seatClassLabel->setText(seatClass);
        ui->costLabel->setText(QString::number(totalCost, 'f', 2) + " PKR");
        ui->mealLabel->setText(mealType);
        ui->wifiLabel->setText(wifiAccess ? "Yes" : "No");
        ui->paymentLabel->setText(paymentMethod);

        // Show success message
        QMessageBox::information(this, "Ticket Found",
                                 "Flight details for ticket " + ticketId + " have been loaded.");
    } else {
        // No record found with the given ticket ID
        QMessageBox::warning(this, "Ticket Not Found",
                             "No booking found with ticket ID: " + ticketId);

        // Clear any previous data from the UI
        ui->ticketIdLabel->clear();
        ui->nameLabel->clear();
        ui->phoneLabel->clear();
        ui->flightLabel->clear();
        ui->dateLabel->clear();
        ui->fromLabel->clear();
        ui->toLabel->clear();
        ui->seatNumberLabel->clear();
        ui->seatClassLabel->clear();
        ui->costLabel->clear();
        ui->mealLabel->clear();
        ui->wifiLabel->clear();
        ui->paymentLabel->clear();
    }
}

void flightdetailwindow::closeEvent(QCloseEvent *event)
{
    // Close the database connection if open
    if (db.isOpen()) {
        db.close();
        QSqlDatabase::removeDatabase("flight_details_connection");
    }

    // Show the main screen when this window is closed
    if (mainscreen::getInstance() != nullptr) {
        mainscreen::getInstance()->show();
    }

    // Call the base class implementation
    QWidget::closeEvent(event);
}

flightdetailwindow::~flightdetailwindow()
{
    // Make sure database is closed properly
    if (db.isOpen()) {
        db.close();
        QSqlDatabase::removeDatabase("flight_details_connection");
    }

    delete ui;
}
