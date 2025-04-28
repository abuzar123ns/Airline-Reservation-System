#ifndef UPDATETICKET_H
#define UPDATETICKET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QCloseEvent>

// Correct forward declaration inside Ui namespace
namespace Ui {
class updateticket;  // Note: all lowercase to match your working example
}

class bookflightwindow;

class updateticket : public QWidget  // Class name all lowercase
{
    Q_OBJECT

public:
    explicit updateticket(QWidget *parent = nullptr);
    ~updateticket();

private slots:
    void on_changeButton_clicked();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::updateticket *ui;  // Note: all lowercase
    QSqlDatabase db;
    bookflightwindow *editBookingWindow;

    bool initializeDatabase();
    bool checkTicketExists(const QString& ticketId);
};

#endif // UPDATETICKET_H
