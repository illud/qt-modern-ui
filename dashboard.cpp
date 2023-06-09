#include "dashboard.h"
#include "ui_dashboard.h"
#include <QVector>

Dashboard::Dashboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Dashboard)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(0);

    loadData();
}

Dashboard::~Dashboard()
{
    delete ui;
}

//Person struct
struct Person{
    QString name;
    int id;
    QString createdAt;
};

void Dashboard::loadData(){
    //Vector of persons
    QVector<Person> person;

    //Push data to vector of persons
    person.push_back(Person{"Illud", 123456, "1980"});
    person.push_back(Person{"Kirya", 344, "2021"});
    person.push_back(Person{"Luna", 566, "2018"});
    person.push_back(Person{"Illud", 123456, "1980"});
    person.push_back(Person{"Kirya", 344, "2021"});
    person.push_back(Person{"Luna", 566, "2018"});
    person.push_back(Person{"Illud", 123456, "1980"});
    person.push_back(Person{"Kirya", 344, "2021"});
    person.push_back(Person{"Luna", 566, "2018"});
    person.push_back(Person{"Illud", 123456, "1980"});
    person.push_back(Person{"Kirya", 344, "2021"});
    person.push_back(Person{"Luna", 566, "2018"});
    person.push_back(Person{"Illud", 123456, "1980"});
    person.push_back(Person{"Kirya", 344, "2021"});
    person.push_back(Person{"Luna", 566, "2018"});
    person.push_back(Person{"Illud", 123456, "1980"});
    person.push_back(Person{"Kirya", 344, "2021"});
    person.push_back(Person{"Luna", 566, "2018"});
    person.push_back(Person{"Illud", 123456, "1980"});
    person.push_back(Person{"Kirya", 344, "2021"});
    person.push_back(Person{"Luna", 566, "2018"});
    person.push_back(Person{"Illud", 123456, "1980"});
    person.push_back(Person{"Kirya", 344, "2021"});
    person.push_back(Person{"Luna", 566, "2018"});


    //int currentRow = ui->tableWidget->rowCount();
    //Row index start
    int currentRow = 0;
    //Sets tableWidget row count
    ui->tableWidget->setRowCount(person.count());

    //Loop's trow vector of persons
    for(int i = 0; i < person.count(); i++){
        //Sets data in the current row
        ui->tableWidget->setItem(currentRow, 0, new QTableWidgetItem(person[i].name));
        ui->tableWidget->setItem(currentRow, 1, new QTableWidgetItem(QString::number( person[i].id)));
        ui->tableWidget->setItem(currentRow, 2, new QTableWidgetItem(person[i].createdAt));
        //Creates a empty widget item for button
        ui->tableWidget->setItem(currentRow, 3, new QTableWidgetItem());

        // CELL BUTTON
        QPushButton* button = new QPushButton();
        button->setText("EDIT");
        button->setStyleSheet("QPushButton {    background-color: rgb(41, 98, 255);	font: 900 9pt 'Arial Black';	color: rgb(255, 255, 255);    border: 0px;	border-radius: 20px;	border-style: outset;}QPushButton::hover{     background-color: rgb(33, 78, 203);	font: 900 9pt 'Arial Black';	color: rgb(255, 255, 255);    border: 0px;}QPushButton::focus:pressed{ 	background-color: rgb(38, 72, 184);	font: 900 9pt 'Arial Black';	color: rgb(255, 255, 255);    border: 0px;}");
        //Sets button property to identify button
        button->setProperty("btnEditId", i);
        //Adds button to current index row
        ui->tableWidget->setCellWidget(currentRow, 3,  button);
        //emit connect(button,SIGNAL(clicked()),this,SLOT(on_btnEdit_clicked(i)));
       // emit on_btnEdit_clicked(i);

        //c++ 11 Lambda to call  on_btnEdit_clicked() function with index parameter to identify tableWidget row
        connect(button, &QPushButton::clicked, [this, button](){
            on_btnEdit_clicked(button->property("btnEditId").toInt());
        });

        //Increases currentRow
        currentRow = currentRow + 1;
    }
}

void Dashboard::on_compBtn_clicked()
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

