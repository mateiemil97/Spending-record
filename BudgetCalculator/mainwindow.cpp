#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCalendarWidget>
#include "iostream"
#include <fstream>
#include <sys/stat.h>
#include <iomanip>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calendar_activated(const QDate &date)
{
    ui->display->setText("Day selected");

    string s;
    ifstream in;
    in.open("countDay.txt");

    int sTotal=0;
    while(!in.eof()) {
        getline(in, s);
        sTotal++;
    }

    char filenameCount[ ] = "countDay.txt";
         fstream day;

         if(sTotal < 31)
             day.open(filenameCount, std::fstream::in | std::fstream::out | std::fstream::app);
         else
             day.open(filenameCount, std::fstream::in | std::fstream::out | std::fstream::app | fstream::trunc);

         // If file does not exist, Create new file
          if (!day )
          {
            cout << "Cannot open file, file does not exist. Creating new file..";

            day.open(filenameCount,  fstream::in | fstream::out | fstream::trunc);
            day <<date.day()<<endl;
            day.close();

           }
          else
          {    // use existing file
             day <<date.day()<<endl;
             day.close();
        }
}

void MainWindow::on_get_clicked()
{
    char filenameSpent[ ] = "spent.txt";
         fstream money;
         money.open(filenameSpent, std::fstream::in | std::fstream::out | std::fstream::app);

         // If file does not exist, Create new file
          if (!money )
          {
            cout << "Cannot open file, file does not exist. Creating new file..";

            money.open(filenameSpent,  fstream::in | fstream::out | fstream::trunc);

            money <<ui->spinBox->value()<<endl;
            money.close();

           }
          else
          {    // use existing file

              money <<ui->spinBox->value()<<endl;
             money.close();
        }

       ui->display->setText(QString::number(ui->spinBox->value()));
}

void MainWindow::on_pushButton_clicked()
{
        ifstream Input,in;
        string name;
        name="spent.txt";
        int x = 0;
        int sum = 0;
        int count = 0;
        Input.open(name.c_str(), ios::in);
        while (!Input.fail())
            {

                Input >> x;
                if (Input)
                {
                    sum += x;
                    count++;
                }
        }

        Input.close();
        avg =(double)sum /count;
        ui->display->setText("Spent money:" + QString::number(sum));
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->display->setText("Average/Day: " + QString::number(avg));
}

void MainWindow::on_pushButton_3_clicked()
{
    char filenameCount[ ] = "countDay.txt";
    fstream day;
    day.open(filenameCount, std::fstream::in | std::fstream::out | fstream::trunc);
    day.close();

    char filenameSpent[ ] = "spent.txt";
    fstream money;
    money.open(filenameSpent,  fstream::in | fstream::out | fstream::trunc);
    money.close();

    ui->display->setText("All Data Cleared");
}
