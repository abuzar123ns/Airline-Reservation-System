#ifndef LODGECOMPLAINTWINDOW_H
#define LODGECOMPLAINTWINDOW_H

#include <QWidget>
#include <QCloseEvent>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>
#include <QDebug>

namespace Ui {
class lodgecomplaintwindow;
}

class lodgecomplaintwindow : public QWidget
{
    Q_OBJECT

public:
    static lodgecomplaintwindow* getInstance() {
        if (!instance)
            instance = new lodgecomplaintwindow();
        return instance;
    }

    ~lodgecomplaintwindow();

    // Create the complaints table if it doesn't exist
    static bool createComplaintsTable();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_lodgeComplaintButton_clicked();

private:
    explicit lodgecomplaintwindow(QWidget *parent = nullptr);
    Ui::lodgecomplaintwindow *ui;
    static lodgecomplaintwindow* instance;

    // Database functions
    bool saveComplaintToDatabase(const QString &ticketId, const QString &message);
    bool verifyTicketExists(const QString &ticketId);
    bool initializeDatabase();
};

#endif // LODGECOMPLAINTWINDOW_H
