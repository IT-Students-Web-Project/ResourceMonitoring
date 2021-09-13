#ifndef SELECTEDCLIENT_H
#define SELECTEDCLIENT_H

#include <QDialog>
#include "resources.h"

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

private:
    Ui::SelectedClient *ui;
    Resources* resources;
};

#endif // SELECTEDCLIENT_H
