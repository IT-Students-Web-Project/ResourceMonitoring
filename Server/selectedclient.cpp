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
    ui->label->setText(QString::fromStdString(resources->getHostName()));
}

SelectedClient::~SelectedClient()
{
    delete ui;
}
