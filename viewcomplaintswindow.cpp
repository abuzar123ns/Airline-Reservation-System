// #include "viewcomplaintswindow.h"
// #include "ui_viewcomplaintswindow.h"
// #include "mainscreen.h"

// // Initialize static instance pointer
// viewcomplaintswindow* viewcomplaintswindow::instance = nullptr;

// viewcomplaintswindow::viewcomplaintswindow(QWidget *parent)
//     : QWidget(parent)
//     , ui(new Ui::viewcomplaintswindow)
// {
//     ui->setupUi(this);
//     this->resize(1100, 600);

//     // Make sure the complaints table exists
//     ensureComplaintsTableExists();

//     // Load complaints initially
//     loadComplaints();
// }

// viewcomplaintswindow::~viewcomplaintswindow()
// {
//     delete ui;
//     instance = nullptr;
// }

// void viewcomplaintswindow::closeEvent(QCloseEvent *event)
// {
//     // Show the main screen when this window is closed
//     if (mainscreen::getInstance() != nullptr) {
//         mainscreen::getInstance()->show();
//     }
//     // Call the base class implementation
//     QWidget::closeEvent(event);
// }

// bool viewcomplaintswindow::initializeDatabase()
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

// bool viewcomplaintswindow::ensureComplaintsTableExists()
// {
//     if (!initializeDatabase()) {
//         return false;
//     }

//     QSqlDatabase db = QSqlDatabase::database();

//     // Check if table exists, if not create it
//     if (!db.tables().contains("complaints")) {
//         QSqlQuery query;
//         bool success = query.exec("CREATE TABLE IF NOT EXISTS complaints ("
//                                   "id INTEGER PRIMARY KEY AUTOINCREMENT, "
//                                   "ticket_id TEXT NOT NULL, "
//                                   "message TEXT NOT NULL, "
//                                   "submission_date TEXT NOT NULL, "
//                                   "status TEXT DEFAULT 'Pending')");

//         if (!success) {
//             qDebug() << "Error creating table:" << query.lastError().text();
//             return false;
//         }
//     }

//     return true;
// }

// void viewcomplaintswindow::loadComplaints()
// {
//     if (!initializeDatabase()) {
//         QMessageBox::critical(this, "Database Error", "Could not connect to the database.");
//         return;
//     }

//     // Clear existing table data
//     ui->complaintsTableWidget->setRowCount(0);

//     QSqlQuery query;
//     QString filter = ui->statusFilterComboBox->currentText();

//     if (filter == "All") {
//         if (!query.exec("SELECT id, ticket_id, message, submission_date, status FROM complaints ORDER BY submission_date DESC")) {
//             qDebug() << "Query error:" << query.lastError().text();
//             return;
//         }
//     } else {
//         query.prepare("SELECT id, ticket_id, message, submission_date, status FROM complaints WHERE status = :status ORDER BY submission_date DESC");
//         query.bindValue(":status", filter);
//         if (!query.exec()) {
//             qDebug() << "Query error:" << query.lastError().text();
//             return;
//         }
//     }

//     int row = 0;
//     while (query.next()) {
//         ui->complaintsTableWidget->insertRow(row);

//         // Limit the message length for display in table
//         QString fullMessage = query.value(2).toString();
//         QString displayMessage = fullMessage.length() > 100 ?
//                                      fullMessage.left(100) + "..." : fullMessage;

//         ui->complaintsTableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
//         ui->complaintsTableWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
//         ui->complaintsTableWidget->setItem(row, 2, new QTableWidgetItem(displayMessage));
//         ui->complaintsTableWidget->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
//         ui->complaintsTableWidget->setItem(row, 4, new QTableWidgetItem(query.value(4).toString()));

//         row++;
//     }
// }

// void viewcomplaintswindow::on_refreshButton_clicked()
// {
//     loadComplaints();
// }

// void viewcomplaintswindow::on_statusFilterComboBox_currentIndexChanged(int index)
// {
//     loadComplaints(); // Reload with current filter
// }

// void viewcomplaintswindow::on_viewDetailButton_clicked()
// {
//     if (!initializeDatabase()) {
//         QMessageBox::critical(this, "Database Error", "Could not connect to the database.");
//         return;
//     }

//     int row = ui->complaintsTableWidget->currentRow();
//     if (row < 0) {
//         QMessageBox::information(this, "Selection Required", "Please select a complaint to view.");
//         return;
//     }

//     QString complaintId = ui->complaintsTableWidget->item(row, 0)->text();

//     QSqlQuery query;
//     query.prepare("SELECT ticket_id, message, submission_date, status FROM complaints WHERE id = :id");
//     query.bindValue(":id", complaintId);

//     if (query.exec() && query.next()) {
//         QString detailText = QString(
//                                  "Complaint ID: %1\n"
//                                  "Ticket ID: %2\n"
//                                  "Submitted: %3\n"
//                                  "Status: %4\n\n"
//                                  "Message:\n%5"
//                                  ).arg(complaintId)
//                                  .arg(query.value(0).toString())
//                                  .arg(query.value(2).toString())
//                                  .arg(query.value(3).toString())
//                                  .arg(query.value(1).toString());

//         QMessageBox detailBox;
//         detailBox.setWindowTitle("Complaint Details");
//         detailBox.setText(detailText);
//         detailBox.setStandardButtons(QMessageBox::Ok);
//         detailBox.exec();
//     } else {
//         QMessageBox::critical(this, "Error", "Failed to retrieve complaint details: " + query.lastError().text());
//     }
// }

// void viewcomplaintswindow::on_updateStatusButton_clicked()
// {
//     if (!initializeDatabase()) {
//         QMessageBox::critical(this, "Database Error", "Could not connect to the database.");
//         return;
//     }

//     int row = ui->complaintsTableWidget->currentRow();
//     if (row < 0) {
//         QMessageBox::information(this, "Selection Required", "Please select a complaint to update.");
//         return;
//     }

//     QString complaintId = ui->complaintsTableWidget->item(row, 0)->text();

//     // Simple dialog for status update
//     QStringList statuses = {"Pending", "In Progress", "Resolved"};
//     QString currentStatus = ui->complaintsTableWidget->item(row, 4)->text();

//     bool ok;
//     QString newStatus = QInputDialog::getItem(this, "Update Status",
//                                               "Select new status:", statuses,
//                                               statuses.indexOf(currentStatus), false, &ok);
//     if (!ok || newStatus == currentStatus) {
//         return;
//     }

//     QSqlQuery query;
//     query.prepare("UPDATE complaints SET status = :status WHERE id = :id");
//     query.bindValue(":status", newStatus);
//     query.bindValue(":id", complaintId);

//     if (query.exec()) {
//         QMessageBox::information(this, "Success", "Complaint status updated successfully.");
//         loadComplaints();  // Refresh the table
//     } else {
//         QMessageBox::critical(this, "Error", "Failed to update status: " + query.lastError().text());
//     }
// }
// #include "viewcomplaintswindow.h"
// #include "ui_viewcomplaintswindow.h"
// #include "mainscreen.h"
// #include <QDir>
// #include <QDebug>
// #include <QMessageBox>
// #include <QSqlError>
// #include <QSqlQuery>
// #include <QInputDialog>

// // Initialize static instance pointer
// viewcomplaintswindow* viewcomplaintswindow::instance = nullptr;

// viewcomplaintswindow::viewcomplaintswindow(QWidget *parent)
//     : QWidget(parent)
//     , ui(new Ui::viewcomplaintswindow)
// {
//     ui->setupUi(this);
//     this->resize(1100, 600);

//     // Make sure the complaints table exists
//     ensureComplaintsTableExists();

//     // Load complaints initially
//     loadComplaints();
// }

// viewcomplaintswindow::~viewcomplaintswindow()
// {
//     delete ui;
//     instance = nullptr;
// }

// void viewcomplaintswindow::closeEvent(QCloseEvent *event)
// {
//     // Show the main screen when this window is closed
//     if (mainscreen::getInstance() != nullptr) {
//         mainscreen::getInstance()->show();
//     }
//     // Call the base class implementation
//     QWidget::closeEvent(event);
// }

// bool viewcomplaintswindow::initializeDatabase()
// {
//     // Use a unique connection name for the complaints database
//     QSqlDatabase complaintsDb;

//     if(QSqlDatabase::contains("view_complaints_connection")) {
//         complaintsDb = QSqlDatabase::database("view_complaints_connection");
//     } else {
//         complaintsDb = QSqlDatabase::addDatabase("QSQLITE", "view_complaints_connection");
//         complaintsDb.setDatabaseName(QDir::currentPath() + "/complaints_database.db");
//     }

//     if (!complaintsDb.open()) {
//         qDebug() << "Error opening complaints database:" << complaintsDb.lastError().text();
//         return false;
//     }

//     return true;
// }

// bool viewcomplaintswindow::ensureComplaintsTableExists()
// {
//     if (!initializeDatabase()) {
//         return false;
//     }

//     QSqlDatabase complaintsDb = QSqlDatabase::database("view_complaints_connection");

//     // Check if table exists, if not create it
//     if (!complaintsDb.tables().contains("complaints")) {
//         QSqlQuery query(complaintsDb);
//         bool success = query.exec("CREATE TABLE IF NOT EXISTS complaints ("
//                                   "id INTEGER PRIMARY KEY AUTOINCREMENT, "
//                                   "ticket_id TEXT NOT NULL, "
//                                   "message TEXT NOT NULL, "
//                                   "submission_date TEXT NOT NULL, "
//                                   "status TEXT DEFAULT 'Pending')");

//         if (!success) {
//             qDebug() << "Error creating table:" << query.lastError().text();
//             return false;
//         }
//     }

//     return true;
// }

// void viewcomplaintswindow::loadComplaints()
// {
//     if (!initializeDatabase()) {
//         QMessageBox::critical(this, "Database Error", "Could not connect to the complaints database.");
//         return;
//     }

//     // Clear existing table data
//     ui->complaintsTableWidget->setRowCount(0);

//     QSqlQuery query(QSqlDatabase::database("view_complaints_connection"));
//     QString filter = ui->statusFilterComboBox->currentText();

//     if (filter == "All") {
//         if (!query.exec("SELECT id, ticket_id, message, submission_date, status FROM complaints ORDER BY submission_date DESC")) {
//             qDebug() << "Query error:" << query.lastError().text();
//             return;
//         }
//     } else {
//         query.prepare("SELECT id, ticket_id, message, submission_date, status FROM complaints WHERE status = :status ORDER BY submission_date DESC");
//         query.bindValue(":status", filter);
//         if (!query.exec()) {
//             qDebug() << "Query error:" << query.lastError().text();
//             return;
//         }
//     }

//     int row = 0;
//     while (query.next()) {
//         ui->complaintsTableWidget->insertRow(row);

//         // Limit the message length for display in table
//         QString fullMessage = query.value(2).toString();
//         QString displayMessage = fullMessage.length() > 100 ?
//                                      fullMessage.left(100) + "..." : fullMessage;

//         ui->complaintsTableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
//         ui->complaintsTableWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
//         ui->complaintsTableWidget->setItem(row, 2, new QTableWidgetItem(displayMessage));
//         ui->complaintsTableWidget->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
//         ui->complaintsTableWidget->setItem(row, 4, new QTableWidgetItem(query.value(4).toString()));

//         row++;
//     }

//     qDebug() << "Loaded" << row << "complaints from database";
// }

// void viewcomplaintswindow::on_refreshButton_clicked()
// {
//     loadComplaints();
// }

// void viewcomplaintswindow::on_statusFilterComboBox_currentIndexChanged(int index)
// {
//     loadComplaints(); // Reload with current filter
// }

// void viewcomplaintswindow::on_viewDetailButton_clicked()
// {
//     if (!initializeDatabase()) {
//         QMessageBox::critical(this, "Database Error", "Could not connect to the complaints database.");
//         return;
//     }

//     int row = ui->complaintsTableWidget->currentRow();
//     if (row < 0) {
//         QMessageBox::information(this, "Selection Required", "Please select a complaint to view.");
//         return;
//     }

//     QString complaintId = ui->complaintsTableWidget->item(row, 0)->text();

//     QSqlQuery query(QSqlDatabase::database("view_complaints_connection"));
//     query.prepare("SELECT ticket_id, message, submission_date, status FROM complaints WHERE id = :id");
//     query.bindValue(":id", complaintId);

//     if (query.exec() && query.next()) {
//         QString detailText = QString(
//                                  "Complaint ID: %1\n"
//                                  "Ticket ID: %2\n"
//                                  "Submitted: %3\n"
//                                  "Status: %4\n\n"
//                                  "Message:\n%5"
//                                  ).arg(complaintId)
//                                  .arg(query.value(0).toString())
//                                  .arg(query.value(2).toString())
//                                  .arg(query.value(3).toString())
//                                  .arg(query.value(1).toString());

//         QMessageBox detailBox;
//         detailBox.setWindowTitle("Complaint Details");
//         detailBox.setText(detailText);
//         detailBox.setStandardButtons(QMessageBox::Ok);
//         detailBox.exec();
//     } else {
//         QMessageBox::critical(this, "Error", "Failed to retrieve complaint details: " + query.lastError().text());
//     }
// }

// void viewcomplaintswindow::on_updateStatusButton_clicked()
// {
//     if (!initializeDatabase()) {
//         QMessageBox::critical(this, "Database Error", "Could not connect to the complaints database.");
//         return;
//     }

//     int row = ui->complaintsTableWidget->currentRow();
//     if (row < 0) {
//         QMessageBox::information(this, "Selection Required", "Please select a complaint to update.");
//         return;
//     }

//     QString complaintId = ui->complaintsTableWidget->item(row, 0)->text();

//     // Simple dialog for status update
//     QStringList statuses = {"Pending", "In Progress", "Resolved"};
//     QString currentStatus = ui->complaintsTableWidget->item(row, 4)->text();

//     bool ok;
//     QString newStatus = QInputDialog::getItem(this, "Update Status",
//                                               "Select new status:", statuses,
//                                               statuses.indexOf(currentStatus), false, &ok);
//     if (!ok || newStatus == currentStatus) {
//         return;
//     }

//     QSqlQuery query(QSqlDatabase::database("view_complaints_connection"));
//     query.prepare("UPDATE complaints SET status = :status WHERE id = :id");
//     query.bindValue(":status", newStatus);
//     query.bindValue(":id", complaintId);

//     if (query.exec()) {
//         QMessageBox::information(this, "Success", "Complaint status updated successfully.");
//         loadComplaints();  // Refresh the table
//     } else {
//         QMessageBox::critical(this, "Error", "Failed to update status: " + query.lastError().text());
//     }
// }
#include "viewcomplaintswindow.h"
#include "ui_viewcomplaintswindow.h"
#include "mainscreen.h"
#include <QDir>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QInputDialog>
#include <QFile>
#include <QDateTime>
#include <QHeaderView>
#include <QCloseEvent>

// Initialize static instance pointer
viewcomplaintswindow* viewcomplaintswindow::instance = nullptr;

viewcomplaintswindow::viewcomplaintswindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::viewcomplaintswindow)
{
    ui->setupUi(this);
    this->resize(1100, 600);
    this->setWindowTitle("View Complaint Window");

    // Log available database drivers
    qDebug() << "Available database drivers:" << QSqlDatabase::drivers();

    // Setup the table widget UI
    setupTableWidget();

    // Setup filter dropdown
    setupFilterComboBox();

    // Check UI components
    checkUIComponents();

    // Make sure the complaints table exists
    if (ensureComplaintsTableExists()) {
        verifyTableStructure();

        // Uncomment to insert a test record for debugging
        // insertTestData();
    }

    // Load complaints initially
    loadComplaints();
}

viewcomplaintswindow::~viewcomplaintswindow()
{
    // Close the database connection
    if (QSqlDatabase::contains("view_complaints_connection")) {
        QSqlDatabase db = QSqlDatabase::database("view_complaints_connection");
        db.close();
    }

    delete ui;
    instance = nullptr;
}

void viewcomplaintswindow::closeEvent(QCloseEvent *event)
{
    // Show the main screen when this window is closed
    if (mainscreen::getInstance() != nullptr) {
        mainscreen::getInstance()->show();
    }
    // Call the base class implementation
    QWidget::closeEvent(event);
}

void viewcomplaintswindow::setupTableWidget()
{
    // Make sure table has 5 columns
    ui->complaintsTableWidget->setColumnCount(5);

    // Set column headers
    QStringList headers;
    headers << "ID" << "Ticket ID" << "Message" << "Date" << "Status";
    ui->complaintsTableWidget->setHorizontalHeaderLabels(headers);

    // Set column widths
    ui->complaintsTableWidget->setColumnWidth(0, 50);  // ID
    ui->complaintsTableWidget->setColumnWidth(1, 150); // Ticket ID
    ui->complaintsTableWidget->setColumnWidth(2, 400); // Message
    ui->complaintsTableWidget->setColumnWidth(3, 150); // Date
    ui->complaintsTableWidget->setColumnWidth(4, 100); // Status

    // Make table stretch to fill available space
    ui->complaintsTableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->complaintsTableWidget->verticalHeader()->setVisible(false);

    // Enable selection of entire rows
    ui->complaintsTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->complaintsTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    // Enable alternating row colors for better readability
    ui->complaintsTableWidget->setAlternatingRowColors(true);

    qDebug() << "Table widget setup complete";
}

void viewcomplaintswindow::setupFilterComboBox()
{
    // Clear and add status options
    ui->statusFilterComboBox->clear();
    ui->statusFilterComboBox->addItem("All");
    ui->statusFilterComboBox->addItem("Pending");
    ui->statusFilterComboBox->addItem("In Progress");
    ui->statusFilterComboBox->addItem("Resolved");

    qDebug() << "Filter combo box setup complete";
}

void viewcomplaintswindow::checkUIComponents()
{
    // Check if UI components exist
    if (!ui->complaintsTableWidget)
        qDebug() << "ERROR: complaintsTableWidget is null!";

    if (!ui->statusFilterComboBox)
        qDebug() << "ERROR: statusFilterComboBox is null!";

    if (!ui->refreshButton)
        qDebug() << "ERROR: refreshButton is null!";

    if (!ui->viewDetailButton)
        qDebug() << "ERROR: viewDetailButton is null!";

    if (!ui->updateStatusButton)
        qDebug() << "ERROR: updateStatusButton is null!";

    qDebug() << "UI component check complete";
}

bool viewcomplaintswindow::initializeDatabase()
{
    // Close any existing connections first
    if (QSqlDatabase::contains("view_complaints_connection")) {
        {
            QSqlDatabase db = QSqlDatabase::database("view_complaints_connection");
            db.close();
        }
        QSqlDatabase::removeDatabase("view_complaints_connection");
        qDebug() << "Removed existing database connection";
    }

    // Create a fresh connection
    QSqlDatabase complaintsDb = QSqlDatabase::addDatabase("QSQLITE", "view_complaints_connection");

    // First try the current directory
    QString dbPath = QDir::currentPath() + "/complaints_database.db";

    // Check if file exists
    QFile dbFile(dbPath);
    if (!dbFile.exists()) {
        qDebug() << "Database file not found at: " << dbPath;

        // Try a parent directory as fallback
        dbPath = QDir::currentPath() + "/../complaints_database.db";
        dbFile.setFileName(dbPath);

        if (!dbFile.exists()) {
            qDebug() << "Database file not found at fallback location: " << dbPath;
        } else {
            qDebug() << "Database file found at fallback location: " << dbPath;
        }
    } else {
        qDebug() << "Database file found at: " << dbPath;
    }

    complaintsDb.setDatabaseName(dbPath);

    if (!complaintsDb.open()) {
        qDebug() << "ERROR: Failed to open database:" << complaintsDb.lastError().text();
        return false;
    }

    qDebug() << "Database opened successfully";
    return true;
}

bool viewcomplaintswindow::ensureComplaintsTableExists()
{
    if (!initializeDatabase()) {
        qDebug() << "Failed to initialize database for table creation";
        return false;
    }

    QSqlDatabase complaintsDb = QSqlDatabase::database("view_complaints_connection");

    qDebug() << "Database tables:" << complaintsDb.tables();

    // Check if table exists, if not create it
    if (!complaintsDb.tables().contains("complaints")) {
        qDebug() << "Creating complaints table...";
        QSqlQuery query(complaintsDb);
        bool success = query.exec("CREATE TABLE IF NOT EXISTS complaints ("
                                  "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                  "ticket_id TEXT NOT NULL, "
                                  "message TEXT NOT NULL, "
                                  "submission_date TEXT NOT NULL, "
                                  "status TEXT DEFAULT 'Pending')");

        if (!success) {
            qDebug() << "ERROR: Failed to create table:" << query.lastError().text();
            return false;
        }
        qDebug() << "Table created successfully";
    } else {
        qDebug() << "Complaints table already exists";
    }

    return true;
}

void viewcomplaintswindow::verifyTableStructure()
{
    QSqlDatabase db = QSqlDatabase::database("view_complaints_connection");
    QSqlQuery query(db);
    if (query.exec("PRAGMA table_info(complaints)")) {
        qDebug() << "Table structure:";
        while (query.next()) {
            qDebug() << "Column:" << query.value(1).toString()
            << "Type:" << query.value(2).toString();
        }
    } else {
        qDebug() << "Failed to get table structure:" << query.lastError().text();
    }
}

void viewcomplaintswindow::insertTestData()
{
    if (!initializeDatabase()) {
        qDebug() << "Cannot insert test data - database initialization failed";
        return;
    }

    QSqlDatabase db = QSqlDatabase::database("view_complaints_connection");
    QSqlQuery query(db);

    // Generate a unique ticket ID based on timestamp
    QString ticketId = "TST-" + QString::number(QDateTime::currentDateTime().toSecsSinceEpoch());
    QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

    query.prepare("INSERT INTO complaints (ticket_id, message, submission_date, status) VALUES (?, ?, ?, ?)");
    query.addBindValue(ticketId);
    query.addBindValue("This is a test complaint created at " + timestamp);
    query.addBindValue(timestamp);
    query.addBindValue("Pending");

    if (query.exec()) {
        qDebug() << "Test data inserted successfully with ticket ID:" << ticketId;
    } else {
        qDebug() << "Failed to insert test data:" << query.lastError().text();
    }
}

void viewcomplaintswindow::loadComplaints()
{
    qDebug() << "Loading complaints...";

    if (!initializeDatabase()) {
        QMessageBox::critical(this, "Database Error", "Could not connect to the complaints database.");
        return;
    }

    // Clear existing table data
    ui->complaintsTableWidget->setRowCount(0);

    QSqlDatabase db = QSqlDatabase::database("view_complaints_connection");
    QSqlQuery query(db);

    // Get filter selection
    QString filter = ui->statusFilterComboBox->currentText();
    qDebug() << "Using filter:" << filter;

    // Run appropriate query based on filter
    if (filter == "All") {
        if (!query.exec("SELECT id, ticket_id, message, submission_date, status FROM complaints ORDER BY submission_date DESC")) {
            qDebug() << "ERROR: Query failed:" << query.lastError().text();
            QMessageBox::critical(this, "Query Error", "Failed to fetch complaints: " + query.lastError().text());
            return;
        }
    } else {
        query.prepare("SELECT id, ticket_id, message, submission_date, status FROM complaints WHERE status = :status ORDER BY submission_date DESC");
        query.bindValue(":status", filter);
        if (!query.exec()) {
            qDebug() << "ERROR: Query failed:" << query.lastError().text();
            QMessageBox::critical(this, "Query Error", "Failed to fetch complaints: " + query.lastError().text());
            return;
        }
    }

    qDebug() << "Query executed successfully";

    // Count records in database for debugging
    QSqlQuery countQuery(db);
    if (countQuery.exec("SELECT COUNT(*) FROM complaints")) {
        countQuery.next();
        int total = countQuery.value(0).toInt();
        qDebug() << "Total complaints in database:" << total;
    }

    int row = 0;
    while (query.next()) {
        ui->complaintsTableWidget->insertRow(row);

        // Get values with error checking
        int id = query.value(0).toInt();
        QString ticketId = query.value(1).toString();
        QString message = query.value(2).toString();
        QString date = query.value(3).toString();
        QString status = query.value(4).toString();

        qDebug() << "Found complaint:" << id << ticketId << date << status;

        // Limit the message length for display in table
        QString displayMessage = message.length() > 100 ? message.left(100) + "..." : message;

        ui->complaintsTableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(id)));
        ui->complaintsTableWidget->setItem(row, 1, new QTableWidgetItem(ticketId));
        ui->complaintsTableWidget->setItem(row, 2, new QTableWidgetItem(displayMessage));
        ui->complaintsTableWidget->setItem(row, 3, new QTableWidgetItem(date));
        ui->complaintsTableWidget->setItem(row, 4, new QTableWidgetItem(status));

        row++;
    }

    qDebug() << "Loaded" << row << "complaints from database";

    // Debug table widget status
    qDebug() << "Table widget status:";
    qDebug() << "  - Row count:" << ui->complaintsTableWidget->rowCount();
    qDebug() << "  - Column count:" << ui->complaintsTableWidget->columnCount();
    qDebug() << "  - Is visible:" << ui->complaintsTableWidget->isVisible();

    // Update UI with count
    if (row == 0) {
        qDebug() << "No complaints found with current filter";
    }
}

void viewcomplaintswindow::on_refreshButton_clicked()
{
    qDebug() << "Refresh button clicked";
    loadComplaints();
}

void viewcomplaintswindow::on_statusFilterComboBox_currentIndexChanged(int index)
{
    qDebug() << "Filter changed to index:" << index << "text:" << ui->statusFilterComboBox->currentText();
    loadComplaints(); // Reload with current filter
}

void viewcomplaintswindow::on_viewDetailButton_clicked()
{
    qDebug() << "View detail button clicked";

    if (!initializeDatabase()) {
        QMessageBox::critical(this, "Database Error", "Could not connect to the complaints database.");
        return;
    }

    int row = ui->complaintsTableWidget->currentRow();
    if (row < 0) {
        QMessageBox::information(this, "Selection Required", "Please select a complaint to view.");
        return;
    }

    QString complaintId = ui->complaintsTableWidget->item(row, 0)->text();
    qDebug() << "Viewing details for complaint ID:" << complaintId;

    QSqlQuery query(QSqlDatabase::database("view_complaints_connection"));
    query.prepare("SELECT ticket_id, message, submission_date, status FROM complaints WHERE id = :id");
    query.bindValue(":id", complaintId);

    if (query.exec() && query.next()) {
        QString detailText = QString(
                                 "Complaint ID: %1\n"
                                 "Ticket ID: %2\n"
                                 "Submitted: %3\n"
                                 "Status: %4\n\n"
                                 "Message:\n%5"
                                 ).arg(complaintId)
                                 .arg(query.value(0).toString())
                                 .arg(query.value(2).toString())
                                 .arg(query.value(3).toString())
                                 .arg(query.value(1).toString());

        QMessageBox detailBox;
        detailBox.setWindowTitle("Complaint Details");
        detailBox.setText(detailText);
        detailBox.setStandardButtons(QMessageBox::Ok);
        detailBox.exec();
    } else {
        QMessageBox::critical(this, "Error", "Failed to retrieve complaint details: " + query.lastError().text());
    }
}

void viewcomplaintswindow::on_updateStatusButton_clicked()
{
    qDebug() << "Update status button clicked";

    if (!initializeDatabase()) {
        QMessageBox::critical(this, "Database Error", "Could not connect to the complaints database.");
        return;
    }

    int row = ui->complaintsTableWidget->currentRow();
    if (row < 0) {
        QMessageBox::information(this, "Selection Required", "Please select a complaint to update.");
        return;
    }

    QString complaintId = ui->complaintsTableWidget->item(row, 0)->text();
    qDebug() << "Updating status for complaint ID:" << complaintId;

    // Simple dialog for status update
    QStringList statuses = {"Pending", "In Progress", "Resolved"};
    QString currentStatus = ui->complaintsTableWidget->item(row, 4)->text();

    bool ok;
    QString newStatus = QInputDialog::getItem(this, "Update Status",
                                              "Select new status:", statuses,
                                              statuses.indexOf(currentStatus), false, &ok);
    if (!ok || newStatus == currentStatus) {
        return;
    }

    QSqlQuery query(QSqlDatabase::database("view_complaints_connection"));
    query.prepare("UPDATE complaints SET status = :status WHERE id = :id");
    query.bindValue(":status", newStatus);
    query.bindValue(":id", complaintId);

    if (query.exec()) {
        QMessageBox::information(this, "Success", "Complaint status updated successfully.");
        loadComplaints();  // Refresh the table
    } else {
        QMessageBox::critical(this, "Error", "Failed to update status: " + query.lastError().text());
    }
}

void viewcomplaintswindow::on_addTestDataButton_clicked()
{
    qDebug() << "Add test data button clicked";
    insertTestData();
    loadComplaints();
}

// Static method to get instance
viewcomplaintswindow* viewcomplaintswindow::getInstance()
{
    if(!instance) {
        instance = new viewcomplaintswindow();
    }
    return instance;
}
