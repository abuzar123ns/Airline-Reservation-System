
#include "bill.h"
#include "ui_bill.h"

bill::bill(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bill)
{
    ui->setupUi(this);
    this->resize(1100, 600);
}

bill::~bill()
{
    delete ui;
}

void bill::updateBillDetails(const QString& firstName,
                             const QString& lastName,
                             const QString& PhoneNo,
                             const QString& flightAvailable,
                             const QString& DateOfDepart,
                             const QString& flyingFrom,
                             const QString& flyingTo,
                             const QString& seatNumber,
                             const QString& seatClass,
                             double totalCost,
                             const QString& ticketId)
{
    // Concatenate first and last name
    ui->labelName->setText(firstName + " " + lastName);
    // Show specific details on bill window
    ui->labelPhoneNo->setText(PhoneNo);
    ui->labelFlightAvailable->setText(flightAvailable);
    ui->labelDateOfDepart->setText(DateOfDepart);
    ui->labelFlyingFrom->setText(flyingFrom);
    ui->labelFlyingTo->setText(flyingTo);
    ui->labelseatNumber->setText(seatNumber);
    ui->labelSeatClass->setText(seatClass);


    ui->labelbill->setText("PKR " + QString::number(totalCost, 'f', 0));

    ui->ticketIdLabel->setText(ticketId); // Display ticket ID in UI
}
