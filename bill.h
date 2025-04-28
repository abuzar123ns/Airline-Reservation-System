

#ifndef BILL_H
#define BILL_H

#include <QWidget>

namespace Ui {
class bill;
}

class bill : public QWidget
{
    Q_OBJECT

public:
    explicit bill(QWidget *parent = nullptr);
    ~bill();

public slots:
    void updateBillDetails(const QString& firstName,
                           const QString& lastName,
                           const QString& phoneNumber,
                           const QString& flightAvailable,
                           const QString& departureDate,
                           const QString& flyingFrom,
                           const QString& flyingTo,
                           const QString& seatNumber,
                           const QString& seatClass,
                           double totalCost,
                           const QString& ticketId);

private:
    Ui::bill *ui;
};

#endif // BILL_H
