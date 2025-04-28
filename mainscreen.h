#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QWidget>

namespace Ui {
class mainscreen;
}

class mainscreen : public QWidget
{
    Q_OBJECT

public:
    explicit mainscreen(QWidget *parent = nullptr);
    ~mainscreen();
    void showNewWindow();

    // Add this static method
    static mainscreen* getInstance();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();

private:
    Ui::mainscreen *ui;
};

#endif // MAINSCREEN_H
