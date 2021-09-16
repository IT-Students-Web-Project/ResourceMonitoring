#include "mainwindow.h"
#include "selectedclient.h"
#include "ui_selectedclient.h"

SelectedClient::SelectedClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectedClient)
{
    ui->setupUi(this);
}

SelectedClient::SelectedClient(MainWindow* mainWindow, Resources* r) : QDialog(nullptr),
    ui(new Ui::SelectedClient)
{
    resources = r;
    ui->setupUi(this);
    charts[0]->setTitle("Cpu load");
    charts[1]->setTitle("Free disk space");
    charts[2]->setTitle("Free memory");

    refreshView();
    QObject::connect(mainWindow, &MainWindow::newMessage, this, &SelectedClient::refreshView);
}

SelectedClient::~SelectedClient()
{
    delete ui;
}

void SelectedClient::refreshView() {

    ui->labelHost->setText(QString::fromStdString(resources->getHostName()));
    ui->labelUser->setText(QString::fromStdString(resources->getUserName()));
    ui->labelCpuLoad->setText(QString::number(resources->getCpuLoad()) + "%");
    ui->labelDisk->setText(QString::number(resources->getDiskFreeSpacePercentage())+ "%");
    ui->labelMemory->setText(QString::number(resources->getTotalMemory()));
    ui->labelUsedMemory->setText(QString::number(100.0*resources->getMemoryLoad()/resources->getTotalMemory()) + "%");

    refreshFloatChart(ui->graphicsView_chart0, lineSeries[0], charts[0], resources->getCpuLoadList());
    refreshFloatChart(ui->graphicsView_chart1, lineSeries[1], charts[1], resources->getDiskFreeSpacePercentageList());
    refreshMemoryChart(ui->graphicsView_chart2, lineSeries[2], charts[2], resources->getMemoryLoadListReference());
}

void SelectedClient::refreshFloatChart(QChartView* chartView, QLineSeries* lineSeries, QChart* chart, std::list<float> dataList) {

//    QValueAxis *percentageAxisY = new QValueAxis();
//    percentageAxisY->setRange(0,100);
//    chart->setAxisY(percentageAxisY);

    lineSeries->clear();
    int iter = 30;
    for (float data : dataList){
        lineSeries->append(iter, data);
        iter--;
    }

    refreshChart(chartView, chart, lineSeries);
}


void SelectedClient::refreshMemoryChart(QChartView* chartView, QLineSeries* lineSeries, QChart* chart, std::list<unsigned long long> dataList) {

//    QValueAxis *memoryAxisY = new QValueAxis();
//    memoryAxisY->setRange(0, resources->getTotalMemory());

//    chart->setAxisY(memoryAxisY);


    lineSeries->clear();
    int iter = 30;
    for (unsigned long long data : dataList){
        lineSeries->append(iter, 100.0 * data/resources->getTotalMemory());
        iter--;
    }

    refreshChart(chartView, chart, lineSeries);
}

void SelectedClient::refreshChart(QChartView* chartView, QChart* chart, QLineSeries* lineSeries) {

    chart->addSeries(lineSeries);
    chart->legend()->hide();
    chart->createDefaultAxes();

    chartView->setChart(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

}


void SelectedClient::on_pushButtonProcesses_clicked()
{
    //<QTcpSocket*,Resources> resourcesSocketMap
    RunningProcesses* p = new RunningProcesses(resources->getProcessesMap());
    p->show();
}

