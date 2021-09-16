#ifndef SELECTEDCLIENT_H
#define SELECTEDCLIENT_H

#include <QChartView>
#include <QDialog>
#include "mainwindow.h"
#include "resources.h"
#include "runningprocesses.h"
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>

namespace Ui {
class SelectedClient;
}

class SelectedClient : public QDialog
{
    Q_OBJECT

public:
    explicit SelectedClient(QWidget *parent = nullptr);
    SelectedClient(MainWindow* mainWindow, Resources* r);
    ~SelectedClient();

private slots:
    void on_pushButtonProcesses_clicked();

private:
    Ui::SelectedClient *ui;
    Resources* resources;
    QLineSeries *lineSeries[3] = {new QLineSeries, new QLineSeries, new QLineSeries};
    QChart *charts[3] = {new QChart(), new QChart(), new QChart()};
    void refreshView();
    void refreshFloatChart(QChartView* chartView,QLineSeries* lineSeries, QChart* chart, std::list<float> dataList);
    void refreshMemoryChart(QChartView* chartView, QLineSeries *lineSeries, QChart *chart, std::list<unsigned long long> dataList);
    void refreshChart(QChartView *chartView, QChart *chart, QLineSeries *lineSeries);
};

#endif // SELECTEDCLIENT_H
