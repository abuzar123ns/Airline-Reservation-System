// #ifndef VIEWCOMPLAINTSWINDOW_H
// #define VIEWCOMPLAINTSWINDOW_H

// #include <QWidget>
// #include <QCloseEvent>
// #include <QMessageBox>
// #include <QInputDialog>
// #include <QTableWidgetItem>
// #include <QSqlDatabase>
// #include <QSqlQuery>
// #include <QSqlError>
// #include <QDebug>

// namespace Ui {
// class viewcomplaintswindow;
// }

// class viewcomplaintswindow : public QWidget
// {
//     Q_OBJECT

// public:
//     static viewcomplaintswindow* getInstance() {
//         if (!instance)
//             instance = new viewcomplaintswindow();
//         return instance;
//     }

//     ~viewcomplaintswindow();
// explicit viewcomplaintswindow(QWidget *parent = nullptr);
// protected:
//     void closeEvent(QCloseEvent *event) override;

// private slots:
//     void on_refreshButton_clicked();
//     void on_statusFilterComboBox_currentIndexChanged(int index);
//     void on_viewDetailButton_clicked();
//     void on_updateStatusButton_clicked();

// private:

//     Ui::viewcomplaintswindow *ui;
//     static viewcomplaintswindow* instance;

//     // Database functions
//     bool ensureComplaintsTableExists();
//     bool initializeDatabase();
//     void loadComplaints();
// };

// #endif // VIEWCOMPLAINTSWINDOW_H
#ifndef VIEWCOMPLAINTSWINDOW_H
#define VIEWCOMPLAINTSWINDOW_H

#include <QWidget>
#include <QCloseEvent>

namespace Ui {
class viewcomplaintswindow;
}

class viewcomplaintswindow : public QWidget
{
    Q_OBJECT

public:
    explicit viewcomplaintswindow(QWidget *parent = nullptr);
    ~viewcomplaintswindow();

    // Static method to get the instance (Singleton pattern)
    static viewcomplaintswindow* getInstance();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_refreshButton_clicked();
    void on_statusFilterComboBox_currentIndexChanged(int index);
    void on_viewDetailButton_clicked();
    void on_updateStatusButton_clicked();
    void on_addTestDataButton_clicked(); // New slot for test data button

private:
    Ui::viewcomplaintswindow *ui;
    static viewcomplaintswindow* instance;

    // Setup methods
    void setupTableWidget();
    void setupFilterComboBox();
    void checkUIComponents();

    // Database methods
    bool initializeDatabase();
    bool ensureComplaintsTableExists();
    void loadComplaints();
    void verifyTableStructure();
    void insertTestData();
};

#endif // VIEWCOMPLAINTSWINDOW_H
