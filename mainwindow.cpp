
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>

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


void MainWindow::on_closeBtn_clicked()
{
    this->close();
}


void MainWindow::on_minimizeBtn_clicked()
{
    this->showMinimized();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    startPos = event->pos();
    QWidget::mousePressEvent(event);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QPoint delta = event->pos() - startPos;
    QWidget * w = window();
    if(w)
        w->move(w->pos() + delta);
    QWidget::mouseMoveEvent(event);
}
