#ifndef RUNNINGPROCESSES_H
#define RUNNINGPROCESSES_H

#include <QDialog>

namespace Ui {
class RunningProcesses;
}

class RunningProcesses : public QDialog
{
    Q_OBJECT

public:
    explicit RunningProcesses(QWidget *parent = nullptr);
    RunningProcesses(std::map<int, std::string> i_processesMap);
    ~RunningProcesses();

private:
    Ui::RunningProcesses *ui;
    std::map<int, std::string> processesMap;
};

#endif // RUNNINGPROCESSES_H
