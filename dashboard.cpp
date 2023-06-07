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
    person.push_back(Person{"1", 1, "1"});
    person.push_back(Person{"2", 2, "2"});

    //int currentRow = ui->tableWidget->rowCount();
    int currentRow = 0;
    ui->tableWidget->setRowCount(person.count());

    for(int i = 0; i < person.count(); i++){
        qDebug() << person[i].name;
        ui->tableWidget->setItem(currentRow, 0, new QTableWidgetItem(person[i].name));
        ui->tableWidget->setItem(currentRow, 1, new QTableWidgetItem(QString::number( person[i].id)));
        ui->tableWidget->setItem(currentRow, 2, new QTableWidgetItem(person[i].createdAt));
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

