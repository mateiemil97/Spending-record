#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "iostream"
#include <fstream>
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool fileExists(const std::string& filename);
    int countLines(char);
private slots:
    void on_get_clicked();

    void on_calendar_activated(const QDate &date);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    double totalSpent=0;
    QString amount;
    double avg = 0.0;

};

#endif // MAINWINDOW_H
