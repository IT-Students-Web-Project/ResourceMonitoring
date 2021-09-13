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
}

SelectedClient::~SelectedClient()
{
    delete ui;
}
