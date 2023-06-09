
#include "mainwindow.h"
#include "ui_mainwindow.h"


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

void MainWindow::on_loginBtn_clicked()
{
    //Opens dashboard widget
    Dashboard *dashb = new Dashboard;
    dashb->show();

    //Closes current window(MainWindow)
    this->close();
}


void MainWindow::on_registerBtn_clicked()
{
    //Opens registerWindow widget
    RegisterWindow *registerW = new RegisterWindow;
    registerW->show();
}

