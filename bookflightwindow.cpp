// #include "bookflightwindow.h"
// #include "ui_bookflightwindow.h"
// #include "mainscreen.h"
// #include "bill.h"
// #include <QDebug>
// #include <QMessageBox>
// #include <QDir>
// #include <QPushButton>

// bookflightwindow::bookflightwindow(QWidget *parent)
//     : QWidget(parent)
//     , ui(new Ui::bookflightwindow)
//     , billWindow(nullptr)
//     , currentTicketId("")
// {
//     ui->setupUi(this);
//     this->resize(1100, 600);

//     // Initialize the database
//     if (!initializeDatabase()) {
//         QMessageBox::critical(this, "Database Error", "Failed to initialize booking database.");
//     }

//     // Setup checkbox connections instead of radio buttons
//     setupCheckboxConnections();

//     // Set default selections for seat class radio buttons (these remain as radio buttons)
//     ui->Economy->setChecked(true);  // Default to Economy class
// }

// bookflightwindow::~bookflightwindow()
// {
//     // Close the database connection if open
//     if (db.isOpen()) {
//         db.close();
//         QSqlDatabase::removeDatabase("bookings_connection");
//     }

//     delete ui;
// }

// bool bookflightwindow::initializeDatabase()
// {
//     // Setup the SQLite database with a unique connection name
//     db = QSqlDatabase::addDatabase("QSQLITE", "bookings_connection");

//     // Set the database file path
//     QString dbPath = QDir::currentPath() + "/airline_bookings.db";
//     qDebug() << "Bookings database path:" << dbPath;
//     db.setDatabaseName(dbPath);

//     // Open the database
//     if (!db.open()) {
//         qDebug() << "Failed to open bookings database:" << db.lastError().text();
//         QMessageBox::critical(this, "Database Error",
//                               "Failed to open bookings database: " + db.lastError().text());
//         return false;
//     }

//     qDebug() << "Bookings database opened successfully";
//     // Create necessary tables if they don't exist
//     return createTables();
// }

// bool bookflightwindow::createTables()
// {
//     QSqlQuery query(db);

//     // Create bookings table if it doesn't exist
//     QString createTableQuery =
//         "CREATE TABLE IF NOT EXISTS bookings ("
//         "ticket_id TEXT PRIMARY KEY, "
//         "first_name TEXT NOT NULL, "
//         "last_name TEXT NOT NULL, "
//         "phone_number TEXT NOT NULL, "
//         "flight_available TEXT NOT NULL, "
//         "departure_date TEXT NOT NULL, "
//         "flying_from TEXT NOT NULL, "
//         "flying_to TEXT NOT NULL, "
//         "seat_number TEXT NOT NULL, "
//         "seat_class TEXT NOT NULL, "
//         "total_cost REAL NOT NULL, "
//         "meal_type TEXT NOT NULL, "
//         "wifi_access BOOLEAN NOT NULL, "
//         "payment_method TEXT NOT NULL, "
//         "booking_timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP)";

//     if (!query.exec(createTableQuery)) {
//         qDebug() << "Failed to create bookings table:" << query.lastError().text();
//         QMessageBox::critical(this, "Database Error",
//                               "Failed to create bookings table: " + query.lastError().text());
//         return false;
//     }

//     qDebug() << "Bookings table created successfully";
//     return true;
// }

// QString bookflightwindow::generateUniqueTicketId()
// {
//     // Define valid alphabets (uppercase only for clarity)
//     static const QString alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

//     // Generate two random uppercase letters
//     QChar letter1 = alphabets.at(QRandomGenerator::global()->bounded(alphabets.length()));
//     QChar letter2 = alphabets.at(QRandomGenerator::global()->bounded(alphabets.length()));

//     // Generate a random 3-digit number (100-999)
//     int randomNumber = QRandomGenerator::global()->bounded(100, 1000);

//     // Combine to create a ticket ID format: XX-NNN
//     QString ticketId = QString("%1%2-%3")
//                            .arg(letter1)
//                            .arg(letter2)
//                            .arg(randomNumber, 3, 10, QChar('0')); // Ensures 3 digits with leading zeros

//     // Check if this ID already exists, if so, generate a new one
//     while (!isTicketIdUnique(ticketId)) {
//         letter1 = alphabets.at(QRandomGenerator::global()->bounded(alphabets.length()));
//         letter2 = alphabets.at(QRandomGenerator::global()->bounded(alphabets.length()));
//         randomNumber = QRandomGenerator::global()->bounded(100, 1000);
//         ticketId = QString("%1%2-%3")
//                        .arg(letter1)
//                        .arg(letter2)
//                        .arg(randomNumber, 3, 10, QChar('0'));
//     }

//     return ticketId;
// }

// bool bookflightwindow::isTicketIdUnique(const QString& ticketId)
// {
//     QSqlQuery query(db);
//     query.prepare("SELECT ticket_id FROM bookings WHERE ticket_id = :ticket_id");
//     query.bindValue(":ticket_id", ticketId);

//     if (!query.exec()) {
//         qDebug() << "Error checking ticket ID uniqueness:" << query.lastError().text();
//         return false;
//     }

//     // If no records returned, the ticket ID is unique
//     return !query.next();
// }

// bool bookflightwindow::saveBookingToDatabase(
//     const QString& ticketId,
//     const QString& firstName,
//     const QString& lastName,
//     const QString& phoneNumber,
//     const QString& flightAvailable,
//     const QString& departureDate,
//     const QString& flyingFrom,
//     const QString& flyingTo,
//     const QString& seatNumber,
//     const QString& seatClass,
//     double totalCost,
//     const QString& mealType,
//     bool wifiAccess,
//     const QString& paymentMethod)
// {
//     QSqlQuery query(db);
//     query.prepare(
//         "INSERT INTO bookings (ticket_id, first_name, last_name, phone_number, flight_available, "
//         "departure_date, flying_from, flying_to, seat_number, seat_class, total_cost, "
//         "meal_type, wifi_access, payment_method) "
//         "VALUES (:ticket_id, :first_name, :last_name, :phone_number, :flight_available, "
//         ":departure_date, :flying_from, :flying_to, :seat_number, :seat_class, :total_cost, "
//         ":meal_type, :wifi_access, :payment_method)"
//         );

//     query.bindValue(":ticket_id", ticketId);
//     query.bindValue(":first_name", firstName);
//     query.bindValue(":last_name", lastName);
//     query.bindValue(":phone_number", phoneNumber);
//     query.bindValue(":flight_available", flightAvailable);
//     query.bindValue(":departure_date", departureDate);
//     query.bindValue(":flying_from", flyingFrom);
//     query.bindValue(":flying_to", flyingTo);
//     query.bindValue(":seat_number", seatNumber);
//     query.bindValue(":seat_class", seatClass);
//     query.bindValue(":total_cost", totalCost);
//     query.bindValue(":meal_type", mealType);
//     query.bindValue(":wifi_access", wifiAccess);
//     query.bindValue(":payment_method", paymentMethod);

//     if (!query.exec()) {
//         qDebug() << "Failed to save booking:" << query.lastError().text();
//         return false;
//     }

//     qDebug() << "Booking saved successfully with Ticket ID:" << ticketId;
//     return true;
// }

// void bookflightwindow::setupCheckboxConnections()
// {
//     // Connect checkboxes for meal type to ensure only one is selected at a time
//     connect(ui->Veg, &QCheckBox::toggled, this, &bookflightwindow::onCheckboxToggled);
//     connect(ui->Nonveg, &QCheckBox::toggled, this, &bookflightwindow::onCheckboxToggled);

//     // Connect checkboxes for WiFi access to ensure only one is selected at a time
//     connect(ui->WifiYes, &QCheckBox::toggled, this, &bookflightwindow::onCheckboxToggled);
//     connect(ui->WifiNo, &QCheckBox::toggled, this, &bookflightwindow::onCheckboxToggled);

//     // Connect checkboxes for payment method to ensure only one is selected at a time
//     connect(ui->Master, &QCheckBox::toggled, this, &bookflightwindow::onCheckboxToggled);
//     connect(ui->Paypal, &QCheckBox::toggled, this, &bookflightwindow::onCheckboxToggled);

//     // Seat Class Radio Buttons (these stay as radio buttons)
//     QObject::connect(ui->Buisness, &QRadioButton::clicked, [this]() {
//         if(ui->Buisness->isChecked()) {
//             ui->Economy->setChecked(false);
//             qDebug() << "Business class selected";
//         }
//     });
//     QObject::connect(ui->Economy, &QRadioButton::clicked, [this]() {
//         if(ui->Economy->isChecked()) {
//             ui->Buisness->setChecked(false);
//             qDebug() << "Economy class selected";
//         }
//     });

//     // Set default selections
//     ui->Veg->setChecked(true);
//     ui->WifiNo->setChecked(true);
//     ui->Master->setChecked(true);
// }

// void bookflightwindow::onCheckboxToggled(bool checked)
// {
//     // Get the sender checkbox
//     QCheckBox* senderCheckBox = qobject_cast<QCheckBox*>(sender());
//     if (!senderCheckBox || !checked) return;

//     // Handle meal type checkboxes
//     if (senderCheckBox == ui->Veg) {
//         ui->Nonveg->setChecked(false);
//     } else if (senderCheckBox == ui->Nonveg) {
//         ui->Veg->setChecked(false);
//     }

//     // Handle WiFi checkboxes
//     else if (senderCheckBox == ui->WifiYes) {
//         ui->WifiNo->setChecked(false);
//     } else if (senderCheckBox == ui->WifiNo) {
//         ui->WifiYes->setChecked(false);
//     }

//     // Handle payment method checkboxes
//     else if (senderCheckBox == ui->Master) {
//         ui->Paypal->setChecked(false);
//     } else if (senderCheckBox == ui->Paypal) {
//         ui->Master->setChecked(false);
//     }
// }

// double bookflightwindow::calculateBill(const QString& seatClass, const QString& seatNumber)
// {
//     // Calculate cost based on seat class in Pakistani Rupees
//     double costPerSeat = (seatClass == "Business") ? 400000.0 : 100000.0;

//     // Get number of seats (default to 1 if not a valid number)
//     bool ok;
//     int numberOfSeats = seatNumber.toInt(&ok);
//     if (!ok || numberOfSeats < 1) {
//         numberOfSeats = 1;
//     }

//     // Add WiFi cost if selected (e.g., 5000 PKR)
//     double wifiCost = ui->WifiYes->isChecked() ? 5000.0 : 0.0;

//     return (costPerSeat * numberOfSeats) + wifiCost;
// }

// void bookflightwindow::showBillWindow()
// {
//     // Create bill window if it doesn't exist
//     if (!billWindow) {
//         billWindow = new bill();
//         billWindow->setWindowTitle("Bill Window");
//     }

//     // Get seat class selection
//     QString seatClass = ui->Buisness->isChecked() ? "Business" : "Economy";

//     // Calculate the bill
//     double totalCost = calculateBill(seatClass, ui->seatNumber->text());

//     // Connect the signal to the bill window's slot
//     disconnect(this, &bookflightwindow::sendBookingDetails, nullptr, nullptr);
//     connect(this, &bookflightwindow::sendBookingDetails,
//             billWindow, &bill::updateBillDetails);

//     // Emit signal with booking details including ticket ID
//     emit sendBookingDetails(
//         ui->Firstname->text(),
//         ui->Lastname->text(),
//         ui->Phoneno->text(),
//         ui->comboBox->currentText(),
//         ui->dateEdit->date().toString("dd/MM/yyyy"),
//         ui->FlyingFrom->text(),
//         ui->FlyingTo->text(),
//         ui->seatNumber->text(),
//         seatClass,
//         totalCost,
//         currentTicketId  // Use the stored ticket ID
//         );

//     // Show the bill window
//     billWindow->show();
// }

// void bookflightwindow::on_pushButton_clicked() {
//     // Basic validation
//     if (ui->Firstname->text().isEmpty() || ui->Lastname->text().isEmpty() ||
//         ui->Phoneno->text().isEmpty() || ui->FlyingFrom->text().isEmpty() ||
//         ui->FlyingTo->text().isEmpty() || ui->seatNumber->text().isEmpty()) {
//         QMessageBox::warning(this, "Incomplete Information", "Please fill in all required fields.");
//         return;
//     }

//     // Check if seat class is selected
//     if (!ui->Buisness->isChecked() && !ui->Economy->isChecked()) {
//         QMessageBox::warning(this, "Seat Class Required", "Please select a seat class (Business or Economy).");
//         return;
//     }

//     // Check if meal type is selected
//     if (!ui->Veg->isChecked() && !ui->Nonveg->isChecked()) {
//         QMessageBox::warning(this, "Meal Type Required", "Please select a meal type (Vegetarian or Non-vegetarian).");
//         return;
//     }

//     // Check if WiFi option is selected
//     if (!ui->WifiYes->isChecked() && !ui->WifiNo->isChecked()) {
//         QMessageBox::warning(this, "WiFi Selection Required", "Please indicate if you want WiFi access.");
//         return;
//     }

//     // Check if payment method is selected
//     if (!ui->Master->isChecked() && !ui->Paypal->isChecked()) {
//         QMessageBox::warning(this, "Payment Method Required", "Please select a payment method (MasterCard or PayPal).");
//         return;
//     }

//     // Get seat class selection
//     QString seatClass = ui->Buisness->isChecked() ? "Business" : "Economy";

//     // Get meal type selection
//     QString mealType = ui->Veg->isChecked() ? "Vegetarian" : "Non-Vegetarian";

//     // Get WiFi access selection
//     bool wifiAccess = ui->WifiYes->isChecked();

//     // Get payment method
//     QString paymentMethod = ui->Master->isChecked() ? "MasterCard" : "PayPal";

//     // Calculate the bill
//     double totalCost = calculateBill(seatClass, ui->seatNumber->text());

//     // Generate a unique ticket ID
//     currentTicketId = generateUniqueTicketId();

//     // Debug output to check values
//     qDebug() << "Booking details:";
//     qDebug() << "Name:" << ui->Firstname->text() << ui->Lastname->text();
//     qDebug() << "Phone:" << ui->Phoneno->text();
//     qDebug() << "Flight:" << ui->comboBox->currentText();
//     qDebug() << "Date:" << ui->dateEdit->date().toString("dd/MM/yyyy");
//     qDebug() << "Route:" << ui->FlyingFrom->text() << "to" << ui->FlyingTo->text();
//     qDebug() << "Seat number:" << ui->seatNumber->text();
//     qDebug() << "Seat class:" << seatClass;
//     qDebug() << "Meal type:" << mealType;
//     qDebug() << "WiFi access:" << (wifiAccess ? "Yes" : "No");
//     qDebug() << "Payment method:" << paymentMethod;
//     qDebug() << "Total cost:" << totalCost;
//     qDebug() << "Ticket ID:" << currentTicketId;

//     // Save booking to database
//     bool saved = saveBookingToDatabase(
//         currentTicketId,
//         ui->Firstname->text(),
//         ui->Lastname->text(),
//         ui->Phoneno->text(),
//         ui->comboBox->currentText(),
//         ui->dateEdit->date().toString("dd/MM/yyyy"),
//         ui->FlyingFrom->text(),
//         ui->FlyingTo->text(),
//         ui->seatNumber->text(),
//         seatClass,
//         totalCost,
//         mealType,
//         wifiAccess,
//         paymentMethod
//         );

//     if (!saved) {
//         QMessageBox::critical(this, "Booking Error", "Failed to save your booking. Please try again.");
//         return;
//     }

//     // Create custom message box with OK button
//     QMessageBox *msgBox = new QMessageBox(this);
//     msgBox->setWindowTitle("Booking Successful");
//     msgBox->setText("Your flight has been booked successfully!\n\n"
//                     "Ticket ID: " + currentTicketId + "\n\n"
//                                         "Click OK to view your bill.");
//     msgBox->setStandardButtons(QMessageBox::Ok);
//     msgBox->setDefaultButton(QMessageBox::Ok);

//     // Connect OK button click to show bill window
//     connect(msgBox, &QMessageBox::finished, this, [this, msgBox](int result) {
//         if (result == QMessageBox::Ok) {
//             showBillWindow();
//         }
//         msgBox->deleteLater();
//     });

//     // Show message box
//     msgBox->exec();
// }

// void bookflightwindow::closeEvent(QCloseEvent *event)
// {
//     // Close the bill window if it exists
//     if (billWindow) {
//         billWindow->close();
//         delete billWindow;
//         billWindow = nullptr;
//     }

//     // Show the main screen
//     if (mainscreen::getInstance() != nullptr) {
//         mainscreen::getInstance()->show();
//     }

//     QWidget::closeEvent(event);
// }
#include "bookflightwindow.h"
#include "ui_bookflightwindow.h"
#include "mainscreen.h"
#include "bill.h"
#include <QDebug>
#include <QMessageBox>
#include <QDir>
#include <QPushButton>

bookflightwindow::bookflightwindow(QWidget *parent, bool editMode)
    : QWidget(parent)
    , ui(new Ui::bookflightwindow)
    , billWindow(nullptr)
    , currentTicketId("")
    , isEditMode(editMode)  // Initialize edit mode flag
{
    ui->setupUi(this);
    this->resize(1100, 600);

    // Set window title based on mode
    if (isEditMode) {
        this->setWindowTitle("Edit Flight Booking");
        // Change button text to "Update Booking" in edit mode
        ui->pushButton->setText("Update Booking");
    } else {
        this->setWindowTitle("Book New Flight");
    }

    // Initialize the database
    if (!initializeDatabase()) {
        QMessageBox::critical(this, "Database Error", "Failed to initialize booking database.");
    }

    // Setup checkbox connections instead of radio buttons
    setupCheckboxConnections();

    // Set default selections for seat class radio buttons (these remain as radio buttons)
    ui->Economy->setChecked(true);  // Default to Economy class
}

bookflightwindow::~bookflightwindow()
{
    // Close the database connection if open
    if (db.isOpen()) {
        db.close();
        QSqlDatabase::removeDatabase("bookings_connection");
    }

    delete ui;
}

bool bookflightwindow::initializeDatabase()
{
    // Setup the SQLite database with a unique connection name
    db = QSqlDatabase::addDatabase("QSQLITE", "bookings_connection");

    // Set the database file path
    QString dbPath = QDir::currentPath() + "/airline_bookings.db";
    qDebug() << "Bookings database path:" << dbPath;
    db.setDatabaseName(dbPath);

    // Open the database
    if (!db.open()) {
        qDebug() << "Failed to open bookings database:" << db.lastError().text();
        QMessageBox::critical(this, "Database Error",
                              "Failed to open bookings database: " + db.lastError().text());
        return false;
    }

    qDebug() << "Bookings database opened successfully";
    // Create necessary tables if they don't exist
    return createTables();
}

bool bookflightwindow::createTables()
{
    QSqlQuery query(db);

    // Create bookings table if it doesn't exist
    QString createTableQuery =
        "CREATE TABLE IF NOT EXISTS bookings ("
        "ticket_id TEXT PRIMARY KEY, "
        "first_name TEXT NOT NULL, "
        "last_name TEXT NOT NULL, "
        "phone_number TEXT NOT NULL, "
        "flight_available TEXT NOT NULL, "
        "departure_date TEXT NOT NULL, "
        "flying_from TEXT NOT NULL, "
        "flying_to TEXT NOT NULL, "
        "seat_number TEXT NOT NULL, "
        "seat_class TEXT NOT NULL, "
        "total_cost REAL NOT NULL, "
        "meal_type TEXT NOT NULL, "
        "wifi_access BOOLEAN NOT NULL, "
        "payment_method TEXT NOT NULL, "
        "booking_timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP)";

    if (!query.exec(createTableQuery)) {
        qDebug() << "Failed to create bookings table:" << query.lastError().text();
        QMessageBox::critical(this, "Database Error",
                              "Failed to create bookings table: " + query.lastError().text());
        return false;
    }

    qDebug() << "Bookings table created successfully";
    return true;
}

QString bookflightwindow::generateUniqueTicketId()
{
    // Define valid alphabets (uppercase only for clarity)
    static const QString alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Generate two random uppercase letters
    QChar letter1 = alphabets.at(QRandomGenerator::global()->bounded(alphabets.length()));
    QChar letter2 = alphabets.at(QRandomGenerator::global()->bounded(alphabets.length()));

    // Generate a random 3-digit number (100-999)
    int randomNumber = QRandomGenerator::global()->bounded(100, 1000);

    // Combine to create a ticket ID format: XX-NNN
    QString ticketId = QString("%1%2-%3")
                           .arg(letter1)
                           .arg(letter2)
                           .arg(randomNumber, 3, 10, QChar('0')); // Ensures 3 digits with leading zeros

    // Check if this ID already exists, if so, generate a new one
    while (!isTicketIdUnique(ticketId)) {
        letter1 = alphabets.at(QRandomGenerator::global()->bounded(alphabets.length()));
        letter2 = alphabets.at(QRandomGenerator::global()->bounded(alphabets.length()));
        randomNumber = QRandomGenerator::global()->bounded(100, 1000);
        ticketId = QString("%1%2-%3")
                       .arg(letter1)
                       .arg(letter2)
                       .arg(randomNumber, 3, 10, QChar('0'));
    }

    return ticketId;
}

bool bookflightwindow::isTicketIdUnique(const QString& ticketId)
{
    QSqlQuery query(db);
    query.prepare("SELECT ticket_id FROM bookings WHERE ticket_id = :ticket_id");
    query.bindValue(":ticket_id", ticketId);

    if (!query.exec()) {
        qDebug() << "Error checking ticket ID uniqueness:" << query.lastError().text();
        return false;
    }

    // If no records returned, the ticket ID is unique
    return !query.next();
}

bool bookflightwindow::saveBookingToDatabase(
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
    const QString& paymentMethod)
{
    QSqlQuery query(db);
    query.prepare(
        "INSERT INTO bookings (ticket_id, first_name, last_name, phone_number, flight_available, "
        "departure_date, flying_from, flying_to, seat_number, seat_class, total_cost, "
        "meal_type, wifi_access, payment_method) "
        "VALUES (:ticket_id, :first_name, :last_name, :phone_number, :flight_available, "
        ":departure_date, :flying_from, :flying_to, :seat_number, :seat_class, :total_cost, "
        ":meal_type, :wifi_access, :payment_method)"
        );

    query.bindValue(":ticket_id", ticketId);
    query.bindValue(":first_name", firstName);
    query.bindValue(":last_name", lastName);
    query.bindValue(":phone_number", phoneNumber);
    query.bindValue(":flight_available", flightAvailable);
    query.bindValue(":departure_date", departureDate);
    query.bindValue(":flying_from", flyingFrom);
    query.bindValue(":flying_to", flyingTo);
    query.bindValue(":seat_number", seatNumber);
    query.bindValue(":seat_class", seatClass);
    query.bindValue(":total_cost", totalCost);
    query.bindValue(":meal_type", mealType);
    query.bindValue(":wifi_access", wifiAccess);
    query.bindValue(":payment_method", paymentMethod);

    if (!query.exec()) {
        qDebug() << "Failed to save booking:" << query.lastError().text();
        return false;
    }

    qDebug() << "Booking saved successfully with Ticket ID:" << ticketId;
    return true;
}

// New method to update existing booking in database
bool bookflightwindow::updateBookingInDatabase(
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
    const QString& paymentMethod)
{
    QSqlQuery query(db);
    query.prepare(
        "UPDATE bookings SET "
        "first_name = :first_name, "
        "last_name = :last_name, "
        "phone_number = :phone_number, "
        "flight_available = :flight_available, "
        "departure_date = :departure_date, "
        "flying_from = :flying_from, "
        "flying_to = :flying_to, "
        "seat_number = :seat_number, "
        "seat_class = :seat_class, "
        "total_cost = :total_cost, "
        "meal_type = :meal_type, "
        "wifi_access = :wifi_access, "
        "payment_method = :payment_method "
        "WHERE ticket_id = :ticket_id"
        );

    query.bindValue(":first_name", firstName);
    query.bindValue(":last_name", lastName);
    query.bindValue(":phone_number", phoneNumber);
    query.bindValue(":flight_available", flightAvailable);
    query.bindValue(":departure_date", departureDate);
    query.bindValue(":flying_from", flyingFrom);
    query.bindValue(":flying_to", flyingTo);
    query.bindValue(":seat_number", seatNumber);
    query.bindValue(":seat_class", seatClass);
    query.bindValue(":total_cost", totalCost);
    query.bindValue(":meal_type", mealType);
    query.bindValue(":wifi_access", wifiAccess);
    query.bindValue(":payment_method", paymentMethod);
    query.bindValue(":ticket_id", ticketId);

    if (!query.exec()) {
        qDebug() << "Failed to update booking:" << query.lastError().text();
        return false;
    }

    qDebug() << "Booking updated successfully with Ticket ID:" << ticketId;
    return true;
}

// New method to load booking data for editing
bool bookflightwindow::loadBookingForEdit(const QString& ticketId)
{
    if (!db.isOpen()) {
        if (!initializeDatabase()) {
            return false;
        }
    }

    // Set the current ticket ID
    currentTicketId = ticketId;

    // Query the database to get booking details
    QSqlQuery query(db);
    query.prepare("SELECT first_name, last_name, phone_number, flight_available, "
                  "departure_date, flying_from, flying_to, seat_number, seat_class, "
                  "meal_type, wifi_access, payment_method FROM bookings "
                  "WHERE ticket_id = :ticket_id");
    query.bindValue(":ticket_id", ticketId);

    if (!query.exec()) {
        qDebug() << "Error loading booking for edit:" << query.lastError().text();
        return false;
    }

    if (!query.next()) {
        qDebug() << "No booking found with ticket ID:" << ticketId;
        return false;
    }

    // Populate the form with the booking details
    ui->Firstname->setText(query.value(0).toString());
    ui->Lastname->setText(query.value(1).toString());
    ui->Phoneno->setText(query.value(2).toString());

    // Set combobox value for flight_available
    QString flightAvailable = query.value(3).toString();
    int index = ui->comboBox->findText(flightAvailable);
    if (index != -1) {
        ui->comboBox->setCurrentIndex(index);
    }

    // Set date from string (assuming format is dd/MM/yyyy)
    QString dateStr = query.value(4).toString();
    QDate date = QDate::fromString(dateStr, "dd/MM/yyyy");
    ui->dateEdit->setDate(date);

    ui->FlyingFrom->setText(query.value(5).toString());
    ui->FlyingTo->setText(query.value(6).toString());
    ui->seatNumber->setText(query.value(7).toString());

    // Set seat class radio buttons
    QString seatClass = query.value(8).toString();
    if (seatClass == "Business") {
        ui->Buisness->setChecked(true);
        ui->Economy->setChecked(false);
    } else {
        ui->Economy->setChecked(true);
        ui->Buisness->setChecked(false);
    }

    // Set meal type checkboxes
    QString mealType = query.value(9).toString();
    ui->Veg->setChecked(mealType == "Vegetarian");
    ui->Nonveg->setChecked(mealType == "Non-Vegetarian");

    // Set WiFi access checkboxes
    bool wifiAccess = query.value(10).toBool();
    ui->WifiYes->setChecked(wifiAccess);
    ui->WifiNo->setChecked(!wifiAccess);

    // Set payment method checkboxes
    QString paymentMethod = query.value(11).toString();
    ui->Master->setChecked(paymentMethod == "MasterCard");
    ui->Paypal->setChecked(paymentMethod == "PayPal");

    qDebug() << "Loaded booking details for edit with ticket ID:" << ticketId;
    return true;
}

void bookflightwindow::setupCheckboxConnections()
{
    // Connect checkboxes for meal type to ensure only one is selected at a time
    connect(ui->Veg, &QCheckBox::toggled, this, &bookflightwindow::onCheckboxToggled);
    connect(ui->Nonveg, &QCheckBox::toggled, this, &bookflightwindow::onCheckboxToggled);

    // Connect checkboxes for WiFi access to ensure only one is selected at a time
    connect(ui->WifiYes, &QCheckBox::toggled, this, &bookflightwindow::onCheckboxToggled);
    connect(ui->WifiNo, &QCheckBox::toggled, this, &bookflightwindow::onCheckboxToggled);

    // Connect checkboxes for payment method to ensure only one is selected at a time
    connect(ui->Master, &QCheckBox::toggled, this, &bookflightwindow::onCheckboxToggled);
    connect(ui->Paypal, &QCheckBox::toggled, this, &bookflightwindow::onCheckboxToggled);

    // Seat Class Radio Buttons (these stay as radio buttons)
    QObject::connect(ui->Buisness, &QRadioButton::clicked, [this]() {
        if(ui->Buisness->isChecked()) {
            ui->Economy->setChecked(false);
            qDebug() << "Business class selected";
        }
    });
    QObject::connect(ui->Economy, &QRadioButton::clicked, [this]() {
        if(ui->Economy->isChecked()) {
            ui->Buisness->setChecked(false);
            qDebug() << "Economy class selected";
        }
    });

    // Set default selections
    ui->Veg->setChecked(true);
    ui->WifiNo->setChecked(true);
    ui->Master->setChecked(true);
}

void bookflightwindow::onCheckboxToggled(bool checked)
{
    // Get the sender checkbox
    QCheckBox* senderCheckBox = qobject_cast<QCheckBox*>(sender());
    if (!senderCheckBox || !checked) return;

    // Handle meal type checkboxes
    if (senderCheckBox == ui->Veg) {
        ui->Nonveg->setChecked(false);
    } else if (senderCheckBox == ui->Nonveg) {
        ui->Veg->setChecked(false);
    }

    // Handle WiFi checkboxes
    else if (senderCheckBox == ui->WifiYes) {
        ui->WifiNo->setChecked(false);
    } else if (senderCheckBox == ui->WifiNo) {
        ui->WifiYes->setChecked(false);
    }

    // Handle payment method checkboxes
    else if (senderCheckBox == ui->Master) {
        ui->Paypal->setChecked(false);
    } else if (senderCheckBox == ui->Paypal) {
        ui->Master->setChecked(false);
    }
}

double bookflightwindow::calculateBill(const QString& seatClass, const QString& seatNumber)
{
    // Calculate cost based on seat class in Pakistani Rupees
    double costPerSeat = (seatClass == "Business") ? 400000.0 : 100000.0;

    // Get number of seats (default to 1 if not a valid number)
    bool ok;
    int numberOfSeats = seatNumber.toInt(&ok);
    if (!ok || numberOfSeats < 1) {
        numberOfSeats = 1;
    }

    // Add WiFi cost if selected (e.g., 5000 PKR)
    double wifiCost = ui->WifiYes->isChecked() ? 5000.0 : 0.0;

    return (costPerSeat * numberOfSeats) + wifiCost;
}

void bookflightwindow::showBillWindow()
{
    // Create bill window if it doesn't exist
    if (!billWindow) {
        billWindow = new bill();
        billWindow->setWindowTitle("Bill Window");
    }

    // Get seat class selection
    QString seatClass = ui->Buisness->isChecked() ? "Business" : "Economy";

    // Calculate the bill
    double totalCost = calculateBill(seatClass, ui->seatNumber->text());

    // Connect the signal to the bill window's slot
    disconnect(this, &bookflightwindow::sendBookingDetails, nullptr, nullptr);
    connect(this, &bookflightwindow::sendBookingDetails,
            billWindow, &bill::updateBillDetails);

    // Emit signal with booking details including ticket ID
    emit sendBookingDetails(
        ui->Firstname->text(),
        ui->Lastname->text(),
        ui->Phoneno->text(),
        ui->comboBox->currentText(),
        ui->dateEdit->date().toString("dd/MM/yyyy"),
        ui->FlyingFrom->text(),
        ui->FlyingTo->text(),
        ui->seatNumber->text(),
        seatClass,
        totalCost,
        currentTicketId  // Use the stored ticket ID
        );

    // Show the bill window
    billWindow->show();
}

void bookflightwindow::on_pushButton_clicked() {
    // Basic validation
    if (ui->Firstname->text().isEmpty() || ui->Lastname->text().isEmpty() ||
        ui->Phoneno->text().isEmpty() || ui->FlyingFrom->text().isEmpty() ||
        ui->FlyingTo->text().isEmpty() || ui->seatNumber->text().isEmpty()) {
        QMessageBox::warning(this, "Incomplete Information", "Please fill in all required fields.");
        return;
    }

    // Check if seat class is selected
    if (!ui->Buisness->isChecked() && !ui->Economy->isChecked()) {
        QMessageBox::warning(this, "Seat Class Required", "Please select a seat class (Business or Economy).");
        return;
    }

    // Check if meal type is selected
    if (!ui->Veg->isChecked() && !ui->Nonveg->isChecked()) {
        QMessageBox::warning(this, "Meal Type Required", "Please select a meal type (Vegetarian or Non-vegetarian).");
        return;
    }

    // Check if WiFi option is selected
    if (!ui->WifiYes->isChecked() && !ui->WifiNo->isChecked()) {
        QMessageBox::warning(this, "WiFi Selection Required", "Please indicate if you want WiFi access.");
        return;
    }

    // Check if payment method is selected
    if (!ui->Master->isChecked() && !ui->Paypal->isChecked()) {
        QMessageBox::warning(this, "Payment Method Required", "Please select a payment method (MasterCard or PayPal).");
        return;
    }

    // Get seat class selection
    QString seatClass = ui->Buisness->isChecked() ? "Business" : "Economy";

    // Get meal type selection
    QString mealType = ui->Veg->isChecked() ? "Vegetarian" : "Non-Vegetarian";

    // Get WiFi access selection
    bool wifiAccess = ui->WifiYes->isChecked();

    // Get payment method
    QString paymentMethod = ui->Master->isChecked() ? "MasterCard" : "PayPal";

    // Calculate the bill
    double totalCost = calculateBill(seatClass, ui->seatNumber->text());

    bool success = false;

    // Handle differently based on whether we're editing or creating a new booking
    if (isEditMode) {
        // Update existing booking
        success = updateBookingInDatabase(
            currentTicketId,
            ui->Firstname->text(),
            ui->Lastname->text(),
            ui->Phoneno->text(),
            ui->comboBox->currentText(),
            ui->dateEdit->date().toString("dd/MM/yyyy"),
            ui->FlyingFrom->text(),
            ui->FlyingTo->text(),
            ui->seatNumber->text(),
            seatClass,
            totalCost,
            mealType,
            wifiAccess,
            paymentMethod
            );

        if (!success) {
            QMessageBox::critical(this, "Update Error", "Failed to update your booking. Please try again.");
            return;
        }

        QMessageBox *msgBox = new QMessageBox(this);
        msgBox->setWindowTitle("Booking Updated");
        msgBox->setText("Your flight booking has been updated successfully!\n\n"
                        "Ticket ID: " + currentTicketId + "\n\n"
                                            "Click OK to view your updated bill.");
        msgBox->setStandardButtons(QMessageBox::Ok);
        msgBox->setDefaultButton(QMessageBox::Ok);

        // Connect OK button click to show bill window
        connect(msgBox, &QMessageBox::finished, this, [this, msgBox](int result) {
            if (result == QMessageBox::Ok) {
                showBillWindow();
            }
            msgBox->deleteLater();
        });

        // Show message box
        msgBox->exec();
    } else {
        // Generate a unique ticket ID for new bookings only
        currentTicketId = generateUniqueTicketId();

        // Debug output to check values for new booking
        qDebug() << "Booking details:";
        qDebug() << "Name:" << ui->Firstname->text() << ui->Lastname->text();
        qDebug() << "Phone:" << ui->Phoneno->text();
        qDebug() << "Flight:" << ui->comboBox->currentText();
        qDebug() << "Date:" << ui->dateEdit->date().toString("dd/MM/yyyy");
        qDebug() << "Route:" << ui->FlyingFrom->text() << "to" << ui->FlyingTo->text();
        qDebug() << "Seat number:" << ui->seatNumber->text();
        qDebug() << "Seat class:" << seatClass;
        qDebug() << "Meal type:" << mealType;
        qDebug() << "WiFi access:" << (wifiAccess ? "Yes" : "No");
        qDebug() << "Payment method:" << paymentMethod;
        qDebug() << "Total cost:" << totalCost;
        qDebug() << "Ticket ID:" << currentTicketId;

        // Save booking to database
        success = saveBookingToDatabase(
            currentTicketId,
            ui->Firstname->text(),
            ui->Lastname->text(),
            ui->Phoneno->text(),
            ui->comboBox->currentText(),
            ui->dateEdit->date().toString("dd/MM/yyyy"),
            ui->FlyingFrom->text(),
            ui->FlyingTo->text(),
            ui->seatNumber->text(),
            seatClass,
            totalCost,
            mealType,
            wifiAccess,
            paymentMethod
            );

        if (!success) {
            QMessageBox::critical(this, "Booking Error", "Failed to save your booking. Please try again.");
            return;
        }

        QMessageBox *msgBox = new QMessageBox(this);
        msgBox->setWindowTitle("Booking Successful");
        msgBox->setText("Your flight has been booked successfully!\n\n"
                        "Ticket ID: " + currentTicketId + "\n\n"
                                            "Click OK to view your bill.");
        msgBox->setStandardButtons(QMessageBox::Ok);
        msgBox->setDefaultButton(QMessageBox::Ok);

        // Connect OK button click to show bill window
        connect(msgBox, &QMessageBox::finished, this, [this, msgBox](int result) {
            if (result == QMessageBox::Ok) {
                showBillWindow();
            }
            msgBox->deleteLater();
        });

        // Show message box
        msgBox->exec();
    }
}

void bookflightwindow::closeEvent(QCloseEvent *event)
{
    // Close the bill window if it exists
    if (billWindow) {
        billWindow->close();
        delete billWindow;
        billWindow = nullptr;
    }

    // Show the main screen
    if (mainscreen::getInstance() != nullptr) {
        mainscreen::getInstance()->show();
    }

    QWidget::closeEvent(event);
}
