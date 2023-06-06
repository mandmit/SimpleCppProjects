#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_runButton_clicked()
{
    QTime time = ui->timeEdit->time();
    QTime now = QTime::currentTime();
    const int secondsDay = 86400;
    QString msg = "Computer will turn off after ";
    int seconds = now.secsTo(time);
    if(seconds < 0){
        seconds = secondsDay + seconds;
    }
    QString command("shutdown -s -f -t ");
    command.append(QString::number(seconds));
    msg.append(QString::number(seconds));
    msg.append(" seconds\n");
    QMessageBox::about(this, "Info", msg);
    system(command.toStdString().c_str());
}


void MainWindow::on_cancelButton_clicked()
{
    QString command("shutdown -a");
    system(command.toStdString().c_str());
}


void MainWindow::on_exitButton_clicked()
{
    this->close();
}

