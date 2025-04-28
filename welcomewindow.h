
#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QMainWindow>

class loginwindow;

QT_BEGIN_NAMESPACE
namespace Ui { class welcomewindow; }
QT_END_NAMESPACE

class welcomewindow : public QMainWindow
{
    Q_OBJECT

public:
    welcomewindow(QWidget *parent = nullptr);
    ~welcomewindow();
    static welcomewindow* getInstance() { return instance; }

private slots:


    void on_pushButton_2_clicked();

private:
    Ui::welcomewindow *ui;
    static welcomewindow* instance;
};
#endif // WELCOMEWINDOW_H
