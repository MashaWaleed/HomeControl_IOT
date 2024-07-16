#include "CommunicationController.h"
#include <QDebug>

CommunicationController::CommunicationController(QObject *parent) : QObject(parent)
{
    server.listen(QHostAddress::Any, 8080);
    connect(&server, &QTcpServer::newConnection, this, &CommunicationController::handleNewConnection);

    // Move send and receive functions to their respective threads
    QThread *sendThread = new QThread;
    QThread *receiveThread = new QThread;

    connect(sendThread, &QThread::started, this, &CommunicationController::sendData);
    connect(receiveThread, &QThread::started, this, &CommunicationController::receiveData);

    moveToThread(sendThread);
    moveToThread(receiveThread);

    sendThread->start();
    receiveThread->start();
}

CommunicationController::~CommunicationController()
{
    sendThread.quit();
    receiveThread.quit();
    sendThread.wait();
    receiveThread.wait();
}

void CommunicationController::handleNewConnection()
{
    QTcpSocket *socket = server.nextPendingConnection();
    QTimer *timer = new QTimer(this);
    timer->setInterval(10000); // 10 seconds interval
    timer->setSingleShot(true);

    ClientInfo clientInfo = {socket, timer};
    clients.append(clientInfo);

    connect(socket, &QTcpSocket::readyRead, this, &CommunicationController::handleReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &CommunicationController::socketDisconnected);
    connect(timer, &QTimer::timeout, this, &CommunicationController::checkClientAlive);

    timer->start();

    connectedClientsCount++;
    emit clientsCountChanged(connectedClientsCount);
    qDebug() << "Client connected. Total clients:" << connectedClientsCount;
}

void CommunicationController::handleReadyRead()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    for (ClientInfo &client : clients) {
        if (client.socket == socket) {
            client.timer->start(); // Reset the timer on data reception
            break;
        }
    }

    while (socket && socket->bytesAvailable() > 0)
    {
        QByteArray data = socket->readAll();
        emit dataReceived(data);
        parseData(data);
    }
}

void CommunicationController::socketDisconnected()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    for (int i = 0; i < clients.size(); ++i) {
        if (clients[i].socket == socket) {
            clients[i].timer->stop();
            clients[i].timer->deleteLater();
            clients.removeAt(i);
            connectedClientsCount--;
            emit clientsCountChanged(connectedClientsCount);
            qDebug() << "Client disconnected. Total clients:" << connectedClientsCount;
            socket->deleteLater();
            break;
        }
    }
}

void CommunicationController::checkClientAlive()
{
    QTimer *timer = qobject_cast<QTimer*>(sender());
    for (int i = 0; i < clients.size(); ++i) {
        if (clients[i].timer == timer) {
            clients[i].socket->disconnectFromHost();
            break;
        }
    }
}

void CommunicationController::parseData(const QByteArray &data)
{
    // Parse incoming messages in the format "$id,value#"
    QList<QByteArray> messages = data.split('#');
    for (const QByteArray &message : messages)
    {
        if (message.isEmpty())
            continue;

        int id = message.mid(1, message.indexOf(',') - 1).toInt();
        float value = message.mid(message.indexOf(',') + 1).toFloat();

        switch (id)
        {
        case 1:
            if (temperature != value) {
                temperature = value;
                emit temperatureChanged(temperature); // Emit the signal
            }
            qDebug() << "Temp" << temperature;
            break;
        case 2:
            if (humidity != value) {
                humidity = value;
                emit humidityChanged(humidity); // Emit the signal
            }
            qDebug() << "Humidity" << humidity;
            break;
        case 3:
            if (carbon != value) {
                carbon = value;
                emit carbonChanged(carbon); // Emit the signal
            }
            qDebug() << "Carbon" << carbon;
            break;
        case 4:
            if (doorBill != value) {
                doorBill = value;
                emit doorBillChanged(doorBill); // Emit the signal
            }
            qDebug() << "doorBill" << doorBill;
            break;
        case 5:
            if (gate != value) {
                gate = value;
                emit gateChanged(gate); // Emit the signal
            }
            qDebug() << "gate" << gate;
            break;
        default:
            // Unknown ID
            break;
        }
    }
}

void CommunicationController::sendCommand(const QByteArray &command)
{
    for (const ClientInfo &client : clients)
    {
        client.socket->write(command);
        client.socket->flush();
    }
}

float CommunicationController::getTemperature()
{
    return this->temperature;
}

float CommunicationController::getHumidity()
{
    return this->humidity;
}

float CommunicationController::getCarbon()
{
    return this->carbon;
}

int CommunicationController::getDoorBill()
{
    return this->doorBill;
}

int CommunicationController::getGate()
{
    return this->gate;
}

int CommunicationController::getClientsCount()
{
    return this->connectedClientsCount;
}

int CommunicationController::getVolume()
{
    return this->volume;
}
void CommunicationController::incrementVol()
{
    if (this->volume < 30) {
        this->volume += 1;
        qDebug() << "volume : " << volume;
        emit volumeChanged(this->volume);
    }
}

void CommunicationController::decrementVol()
{
    if (this->volume > 0) {
        this->volume -= 1;
        qDebug() << "volume : " << volume;
        emit volumeChanged(this->volume);
    }
}

void CommunicationController::sendData()
{
    while (true)
    {
        QThread::msleep(1000);
        QByteArray data = "Sending data from server...";
        sendCommand(data);
    }
}

void CommunicationController::receiveData()
{
    while (true)
    {
        QThread::msleep(1000);
        QByteArray data = "Receiving data at server...";
        handleReadyRead();
    }
}
