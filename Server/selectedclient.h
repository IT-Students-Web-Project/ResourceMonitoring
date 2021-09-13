#ifndef SELECTEDCLIENT_H
#define SELECTEDCLIENT_H

#include <QDialog>
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
    SelectedClient(Resources* r);
    ~SelectedClient();

private slots:
    void on_pushButtonProcesses_clicked();

private:
    Ui::SelectedClient *ui;
    Resources* resources;
    QLineSeries *lineSeries[3] = {new QLineSeries, new QLineSeries, new QLineSeries};
    QChart *charts[3] = {new QChart(), new QChart(), new QChart()};
};

#endif // SELECTEDCLIENT_H
