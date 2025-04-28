#ifndef ADMINPORTAL_H
#define ADMINPORTAL_H

#include <QWidget>

namespace Ui {
class adminportal;
}

class adminportal : public QWidget
{
    Q_OBJECT

public:
    explicit adminportal(QWidget *parent = nullptr);
    ~adminportal();

private slots:
    void on_pushButton_clicked();

    void on_viewflightdetail_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::adminportal *ui;
};

#endif // ADMINPORTAL_H
