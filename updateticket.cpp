#include "updateticket.h"
#include "ui_updateticket.h"
#include "mainscreen.h"
#include "bookflightwindow.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDir>
#include <QMessageBox>
#include <QDebug>

updateticket::updateticket(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::updateticket),
    editBookingWindow(nullptr)
{
    ui->setupUi(this);
    this->setWindowTitle("Update Ticket Details");
    this->resize(600, 300);
    if (!initializeDatabase()) {
        QMessageBox::critical(this, "Database Error", "Failed to connect to database for updating bookings.");
    }
}

updateticket::~updateticket()
{
    if (db.isOpen()) {
        db.close();
        QSqlDatabase::removeDatabase("update_ticket_connection");
    }
    if (editBookingWindow) {
        delete editBookingWindow;
        editBookingWindow = nullptr;
    }
    delete ui;
}

bool updateticket::initializeDatabase()
{
    db = QSqlDatabase::addDatabase("QSQLITE", "update_ticket_connection");
    QString dbPath = QDir::currentPath() + "/airline_bookings.db";
    qDebug() << "Update bookings database path:" << dbPath;
    db.setDatabaseName(dbPath);
    if (!db.open()) {
        qDebug() << "Failed to open bookings database for updates:" << db.lastError().text();
        return false;
    }
    qDebug() << "Bookings database opened successfully for updates";
    return true;
}

bool updateticket::checkTicketExists(const QString& ticketId)
{
    if (ticketId.isEmpty()) {
        return false;
    }
    QSqlQuery query(db);
    query.prepare("SELECT ticket_id FROM bookings WHERE ticket_id = :ticket_id");
    query.bindValue(":ticket_id", ticketId);
    if (!query.exec()) {
        qDebug() << "Error checking ticket ID:" << query.lastError().text();
        return false;
    }
    return query.next();
}

void updateticket::on_changeButton_clicked()
{
    QString ticketId = ui->ticketIdInput->text().trimmed();
    if (ticketId.isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid Ticket ID.");
        return;
    }
    if (!checkTicketExists(ticketId)) {
        QMessageBox::warning(this, "Ticket Not Found", "No booking found with Ticket ID: " + ticketId);
        return;
    }
    QMessageBox::StandardButton confirmResult = QMessageBox::question(this,
                                                                      "Confirm Update",
                                                                      "Are you sure you want to update the details for Ticket ID: " + ticketId + "?",
                                                                      QMessageBox::Yes | QMessageBox::No);
    if (confirmResult == QMessageBox::No) {
        return;
    }
    if (!editBookingWindow) {
        editBookingWindow = new bookflightwindow(nullptr, true); // true = edit mode
    }
    editBookingWindow->loadBookingForEdit(ticketId);
    editBookingWindow->show();
    this->hide();
}

void updateticket::closeEvent(QCloseEvent *event)
{
    if (mainscreen::getInstance() != nullptr) {
        mainscreen::getInstance()->show();
    }
    QWidget::closeEvent(event);
}
