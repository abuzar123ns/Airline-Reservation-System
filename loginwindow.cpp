#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "welcomewindow.h"
#include "mainscreen.h"
#include <QScopedPointer>
#include "adminlogin.h"
#include <QMessageBox>
#include <QDir>
#include <QCryptographicHash>
#include <QDebug>

// Add a static pointer to store the instance
static loginwindow* loginWindowInstance = nullptr;

loginwindow::loginwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loginwindow)
{
    ui->setupUi(this);
    this->resize(1100, 600);

    // Initialize the database
    if (!initializeDatabase()) {
        QMessageBox::critical(this, "Database Error", "Failed to initialize database.");
    }

    // Store the instance
    loginWindowInstance = this;

    // Connect signals and slots - using new method names to avoid auto-connection conflicts
    connect(ui->loginButton, &QPushButton::clicked, this, &loginwindow::handleLoginButton);
    connect(ui->registerButton, &QPushButton::clicked, this, &loginwindow::handleRegisterButton);
}

loginwindow::~loginwindow()
{
    // Close the database connection if open
    if (db.isOpen()) {
        db.close();
        QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
    }

    loginWindowInstance = nullptr;
    delete ui;
}

bool loginwindow::initializeDatabase()
{
    // Setup the SQLite database
    db = QSqlDatabase::addDatabase("QSQLITE");

    // Set the database file path
    QString dbPath = QDir::currentPath() + "/airline_users.db";
    qDebug() << "Database path:" << dbPath;
    db.setDatabaseName(dbPath);

    // Open the database
    if (!db.open()) {
        qDebug() << "Failed to open database:" << db.lastError().text();
        QMessageBox::critical(this, "Database Error",
                              "Failed to open database: " + db.lastError().text());
        return false;
    }

    qDebug() << "Database opened successfully";
    // Create necessary tables if they don't exist
    return createTables();
}

bool loginwindow::createTables()
{
    QSqlQuery query;

    // Create users table if it doesn't exist
    QString createTableQuery =
        "CREATE TABLE IF NOT EXISTS users ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "username TEXT UNIQUE NOT NULL, "
        "password TEXT NOT NULL, "
        "created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP)";

    if (!query.exec(createTableQuery)) {
        qDebug() << "Failed to create tables:" << query.lastError().text();
        QMessageBox::critical(this, "Database Error",
                              "Failed to create tables: " + query.lastError().text());
        return false;
    }

    qDebug() << "Database tables created successfully";
    return true;
}

QString loginwindow::hashPassword(const QString &password)
{
    // Generate a simple SHA-256 hash of the password
    // In a real app, you should use a salt and better hashing algorithm
    QByteArray passwordData = password.toUtf8();
    QByteArray hashedPassword = QCryptographicHash::hash(passwordData, QCryptographicHash::Sha256);
    return hashedPassword.toHex();
}

bool loginwindow::authenticateUser(const QString &username, const QString &password)
{
    // Prepare the query to check user credentials
    QSqlQuery query;
    query.prepare("SELECT password FROM users WHERE username = :username");
    query.bindValue(":username", username);

    if (!query.exec()) {
        qDebug() << "Authentication query failed:" << query.lastError().text();
        return false;
    }

    // Check if user exists and password matches
    if (query.next()) {
        QString storedPasswordHash = query.value(0).toString();
        QString inputPasswordHash = hashPassword(password);

        return (storedPasswordHash == inputPasswordHash);
    }

    qDebug() << "No user found with username:" << username;
    return false;
}

bool loginwindow::registerUser(const QString &username, const QString &password)
{
    // Debug output
    qDebug() << "Attempting to register user:" << username;

    // Check if username already exists
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT username FROM users WHERE username = :username");
    checkQuery.bindValue(":username", username);

    if (!checkQuery.exec()) {
        qDebug() << "Check query failed:" << checkQuery.lastError().text();
        return false;
    }

    if (checkQuery.next()) {
        qDebug() << "Username already exists";
        return false; // Username already exists
    }

    // Insert new user
    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO users (username, password) VALUES (:username, :password)");
    insertQuery.bindValue(":username", username);
    insertQuery.bindValue(":password", hashPassword(password));

    if (!insertQuery.exec()) {
        qDebug() << "Insert query failed:" << insertQuery.lastError().text();
        return false;
    }

    qDebug() << "User registered successfully";
    return true;
}

void loginwindow::handleLoginButton()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    qDebug() << "Login attempt for user:" << username;

    // Basic validation
    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Login Error", "Username and password cannot be empty.");
        return;
    }

    // Authenticate user
    if (authenticateUser(username, password)) {
        QMessageBox::information(this, "Login Successful", "Welcome, " + username + "!");
        showNewWindow();
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}

void loginwindow::handleRegisterButton()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    qDebug() << "Register button clicked for user:" << username;

    // Basic validation
    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Registration Error", "Username and password cannot be empty.");
        return;
    }

    if (password.length() < 6) {
        QMessageBox::warning(this, "Registration Error", "Password must be at least 6 characters.");
        return;
    }

    // Register the new user
    if (registerUser(username, password)) {
        QMessageBox::information(this, "Registration Successful",
                                 "User registered successfully. You can now log in.");
    } else {
        QMessageBox::warning(this, "Registration Failed",
                             "Username may already exist or there was a database error.");
    }
}

void loginwindow::on_pushButton_clicked()
{
    mainscreen *Mainscreen = new mainscreen();  // Remove parent to prevent automatic deletion
    Mainscreen->show();
    this->hide();  // Hide the login window
}

void loginwindow::showNewWindow()
{
    mainscreen *Mainscreen = new mainscreen();  // Remove parent to prevent automatic deletion
    Mainscreen->show();
    this->hide();  // Hide the login window
}
void loginwindow::on_admilogin_clicked()
{
    adminlogin *Adminlogin = new adminlogin();  // Remove parent to prevent automatic deletion
    Adminlogin->show();
    this->hide();  // Hide the login window
}
// Add this static method to access the instance
loginwindow* loginwindow::getInstance()
{
    return loginWindowInstance;
}





