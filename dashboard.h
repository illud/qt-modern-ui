#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QMainWindow>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>

namespace Ui {
class Dashboard;
}

class Dashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = nullptr);
    ~Dashboard();

private slots:
    void on_usersBtn_clicked();

    void on_btnEdit_clicked(int index);

    void loadData();

    void on_compBtn_clicked();

    void on_closeBtn_clicked();

    void on_minimizeBtn_clicked();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    Ui::Dashboard *ui;
    QPoint startPos;
};

#endif // DASHBOARD_H
