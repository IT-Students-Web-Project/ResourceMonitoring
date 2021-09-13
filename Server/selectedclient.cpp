#include "selectedclient.h"
#include "ui_selectedclient.h"

SelectedClient::SelectedClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectedClient)
{
    ui->setupUi(this);
}

SelectedClient::SelectedClient(Resources* r) : QDialog(nullptr),
    ui(new Ui::SelectedClient)
{
    resources = r;
    ui->setupUi(this);
    ui->labelHost->setText(QString::fromStdString(resources->getHostName()));
    ui->labelUser->setText(QString::fromStdString(resources->getUserName()));
    ui->labelCpuLoad->setText(QString::number(resources->getCpuLoad()) + "%");
    ui->labelDisk->setText(QString::number(resources->getDiskFreeSpacePercentage())+ "%");
    ui->labelMemory->setText(QString::number(resources->getTotalMemory()));
    ui->labelUsedMemory->setText(QString::number(1.0*resources->getMemoryLoad()/resources->getTotalMemory()) + "%");
    int iter = 1;
    for (float cpuLoad : resources->getCpuLoadList()){
        lineSeries[0]->append(iter, cpuLoad);
        iter++;
    }
    iter = 1;
    for (float diskSpace : resources->getDiskFreeSpacePercentageList()){
        lineSeries[1]->append(iter, diskSpace);
        iter++;
    }
    iter = 1;
    for (float memoryLoad : resources->getMemoryLoadListReference()){
        lineSeries[2]->append(iter, 1.0 * memoryLoad/resources->getTotalMemory());
        iter++;
    }
    charts[0]->setTitle("Cpu load");
    charts[1]->setTitle("Free disk space");
    charts[2]->setTitle("Free memory");
    for (int i = 0; i < 3; i++) {
        charts[i]->addSeries(lineSeries[i]);
        charts[i]->legend()->hide();
        charts[i]->createDefaultAxes();
    }
    ui->graphicsView_chart0->setChart(charts[0]);
    ui->graphicsView_chart1->setChart(charts[1]);
    ui->graphicsView_chart2->setChart(charts[2]);
    ui->graphicsView_chart0->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView_chart1->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView_chart2->setRenderHint(QPainter::Antialiasing);
}

SelectedClient::~SelectedClient()
{
    delete ui;
}

void SelectedClient::on_pushButtonProcesses_clicked()
{
    //<QTcpSocket*,Resources> resourcesSocketMap
    RunningProcesses* p = new RunningProcesses(resources->getProcessesMap());
    p->show();
}

