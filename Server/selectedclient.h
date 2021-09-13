#ifndef SELECTEDCLIENT_H
#define SELECTEDCLIENT_H

#include <QDialog>
#include "resources.h"
#include "runningprocesses.h"

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
};

#endif // SELECTEDCLIENT_H
