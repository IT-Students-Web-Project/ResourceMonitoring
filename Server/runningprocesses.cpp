#include "runningprocesses.h"
#include "ui_runningprocesses.h"

RunningProcesses::RunningProcesses(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RunningProcesses)
{
    ui->setupUi(this);
}

RunningProcesses::RunningProcesses(std::map<int, std::string> i_processesMap) :
    QDialog(nullptr),
    ui(new Ui::RunningProcesses)
{
    ui->setupUi(this);
    processesMap = i_processesMap;
    for (const auto& [key, value] : processesMap) {
        ui->listWidgetProcesses->addItem(QString::number(key) + " \t" + QString::fromStdString(value));
    }
}

RunningProcesses::~RunningProcesses()
{
    delete ui;
}
