
#include "welcomewindow.h"
#include "bookflightwindow.h"  // Ensure correct filename
#include "bill.h"        // Ensure correct filename
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    welcomewindow w;
    w.show();

    // Create bill window
    bill *billWindow = new bill();
    billWindow->setWindowTitle("Bill Window");

    // Create book flight window
    bookflightwindow *bookFlight = new bookflightwindow();

    // Connect the signal and slot
    QObject::connect(bookFlight, &bookflightwindow::sendBookingDetails,
                     billWindow, &bill::updateBillDetails);

    // // Show windows
    // bookFlight->show();

    return a.exec();
}
