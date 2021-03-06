#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QMetaType>
#include <QSet>
#include <QMap>
#include <QStandardPaths>
#include <QTcpServer>
#include <QTcpSocket>
#include "resources.h"
#include <QAbstractItemModel>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void newMessage(QString);
private slots:
    void newConnection();
    void appendToSocketList(QTcpSocket* socket);

    void readSocket();
    void discardSocket();
    void displayError(QAbstractSocket::SocketError socketError);

    void displayMessage(const QString& str);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;

    Resources testResources;
    QMap<QTcpSocket*,Resources*> resourcesSocketMap;
    QTcpServer* m_server;
    QSet<QTcpSocket*> connection_set;
};
#endif // MAINWINDOW_H
