#include "dashboard.h"
#include "ui_dashboard.h"
#include <QVector>

struct Person{
    QString name;
    int id;
    QString createdAt;
};

Dashboard::Dashboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Dashboard)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(0);

    QVector<Person> person;
    person.push_back(Person{"Illud", 123456, "1980"});
    person.push_back(Person{"Kirya", 344, "2021"});
    person.push_back(Person{"Luna", 566, "2018"});
    person.push_back(Person{"Mercu", 788, "2015"});

    //int currentRow = ui->tableWidget->rowCount();
    int currentRow = 0;
    ui->tableWidget->setRowCount(person.count());



    for(int i = 0; i < person.count(); i++){
        qDebug() << person[i].name;
        ui->tableWidget->setItem(currentRow, 0, new QTableWidgetItem(person[i].name));
        ui->tableWidget->setItem(currentRow, 1, new QTableWidgetItem(QString::number( person[i].id)));
        ui->tableWidget->setItem(currentRow, 2, new QTableWidgetItem(person[i].createdAt));
        ui->tableWidget->setItem(currentRow, 3,   new QTableWidgetItem());

        // CELL BUTTON
        QPushButton* button = new QPushButton();
        button->setText("EDIT");
        button->setStyleSheet("QPushButton {    background-color: rgb(41, 98, 255);	font: 900 9pt 'Arial Black';	color: rgb(255, 255, 255);    border: 0px;	border-radius: 20px;	border-style: outset;}QPushButton::hover{     background-color: rgb(33, 78, 203);	font: 900 9pt 'Arial Black';	color: rgb(255, 255, 255);    border: 0px;}QPushButton::focus:pressed{ 	background-color: rgb(38, 72, 184);	font: 900 9pt 'Arial Black';	color: rgb(255, 255, 255);    border: 0px;}");
        ui->tableWidget->setCellWidget(currentRow, 3,  button);
        connect(button,SIGNAL(clicked()),this,SLOT(on_btnEdit_clicked(i)));

        currentRow = currentRow + 1;
    }

}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::on_statsBtn_clicked()
{
    //Users *users = new Users(this);

    //ui->mainWidget->layout()->addWidget(users);
    ui->stackedWidget->setCurrentIndex(1);
}


void Dashboard::on_usersBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Dashboard::on_btnEdit_clicked (int index){
    qDebug() << index;
}

