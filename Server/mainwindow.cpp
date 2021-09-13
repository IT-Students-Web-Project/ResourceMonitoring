#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "resources.h"
#include "selectedclient.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_server = new QTcpServer();

    if(m_server->listen(QHostAddress::Any, 6881))
    {
       connect(this, &MainWindow::newMessage, this, &MainWindow::displayMessage);
       connect(m_server, &QTcpServer::newConnection, this, &MainWindow::newConnection);
       ui->statusBar->showMessage("Server is listening...");
    }
    else
    {
        QMessageBox::critical(this,"QTCPServer",QString("Unable to start the server: %1.").arg(m_server->errorString()));
        exit(EXIT_FAILURE);
    }

}

MainWindow::~MainWindow()
{
    foreach (QTcpSocket* socket, connection_set)
    {
        socket->close();
        socket->deleteLater();
    }

    m_server->close();
    m_server->deleteLater();

    delete ui;
}

void MainWindow::newConnection()
{
    while (m_server->hasPendingConnections())
        appendToSocketList(m_server->nextPendingConnection());
}

void MainWindow::appendToSocketList(QTcpSocket* socket)
{
    connection_set.insert(socket);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::readSocket);
    connect(socket, &QTcpSocket::disconnected, this, &MainWindow::discardSocket);
    connect(socket, &QAbstractSocket::errorOccurred, this, &MainWindow::displayError);
    displayMessage(QString("INFO :: Client with sockd:%1 has just entered the room").arg(socket->socketDescriptor()));
    resourcesSocketMap.insert(socket,new Resources());

}

void MainWindow::readSocket()
{
    QTcpSocket* socket = reinterpret_cast<QTcpSocket*>(sender());

    QByteArray buffer;

    QTextStream socketStream(socket);

    socketStream >> buffer;


    QString dataQString = QString(buffer);
    resourcesSocketMap[socket]->DeserializeJson(json::parse(dataQString.toStdString()));
    qDebug() << dataQString;
    QString message = QString::fromStdString(resourcesSocketMap[socket]->getHostName()) + " has succesfully sent resources data";
    emit newMessage(message);
    bool notFound = true;
    for (int i = 0; i < ui->listWidget->count(); i++){
        if(ui->listWidget->item(i)->text() == QString::fromStdString(resourcesSocketMap[socket]->getHostName()))
            notFound = false;
    }
    if(notFound)
        ui->listWidget->addItem(QString::fromStdString(resourcesSocketMap[socket]->getHostName()));
    return;
}

void MainWindow::discardSocket()
{

    QTcpSocket* socket = reinterpret_cast<QTcpSocket*>(sender());
    QSet<QTcpSocket*>::iterator it = connection_set.find(socket);
    for (int i = 0; i < ui->listWidget->count(); i++){
        if(ui->listWidget->item(i)->text() == (QString::fromStdString(resourcesSocketMap[socket]->getHostName())))
            ui->listWidget->takeItem(i);
    }
    resourcesSocketMap.remove(socket);
    if (it != connection_set.end()){
        displayMessage(QString("INFO :: A client has just left the room").arg(socket->socketDescriptor()));
        connection_set.remove(*it);
    }
    socket->deleteLater();
}

void MainWindow::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
        case QAbstractSocket::RemoteHostClosedError:
        break;
        case QAbstractSocket::HostNotFoundError:
            QMessageBox::information(this, "QTCPServer", "The host was not found. Please check the host name and port settings.");
        break;
        case QAbstractSocket::ConnectionRefusedError:
            QMessageBox::information(this, "QTCPServer", "The connection was refused by the peer. Make sure QTCPServer is running, and check that the host name and port settings are correct.");
        break;
        default:
            QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
            QMessageBox::information(this, "QTCPServer", QString("The following error occurred: %1.").arg(socket->errorString()));
        break;
    }
}

void MainWindow::displayMessage(const QString& str)
{
    ui->textBrowser_receivedMessages->append(str);
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    displayMessage(item->text() + " clicked");
    //<QTcpSocket*,Resources> resourcesSocketMap
    foreach (QTcpSocket* sock, resourcesSocketMap.keys())
        if (QString::fromStdString(resourcesSocketMap.value(sock)->getHostName()) == item->text() ){
            SelectedClient* c = new SelectedClient(resourcesSocketMap.value(sock));
            c->show();
        }
}

