#ifndef COMMUNICATIONCONTROLLER_H
#define COMMUNICATIONCONTROLLER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>
#include <QList>
#include <QThread>

class CommunicationController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float temperature READ getTemperature NOTIFY temperatureChanged)
    Q_PROPERTY(float humidity READ getHumidity NOTIFY humidityChanged)
    Q_PROPERTY(float carbon READ getCarbon NOTIFY carbonChanged)
    Q_PROPERTY(int doorBill READ getDoorBill NOTIFY doorBillChanged)
    Q_PROPERTY(int gate READ getGate NOTIFY gateChanged)
    Q_PROPERTY(int clientsCount READ getClientsCount NOTIFY clientsCountChanged)
    Q_PROPERTY(int volume READ getVolume NOTIFY volumeChanged)

public:
    explicit CommunicationController(QObject *parent = nullptr);
    ~CommunicationController();

signals:
    void dataReceived(const QByteArray &data);
    void temperatureChanged(float temperature);
    void humidityChanged(float humidity);
    void carbonChanged(float carbon);
    void doorBillChanged(int doorBill);
    void gateChanged(int gate);
    void clientsCountChanged(int count);
    void volumeChanged(int volume);

public slots:
    void sendCommand(const QByteArray &command);
    float getTemperature();
    float getHumidity();
    float getCarbon();
    int getDoorBill();
    int getGate();
    int getClientsCount();
    int getVolume();

    void incrementVol();
    void decrementVol();

private slots:
    void handleNewConnection();
    void handleReadyRead();
    void socketDisconnected();
    void checkClientAlive();
    void sendData();
    void receiveData();

private:
    struct ClientInfo {
        QTcpSocket *socket;
        QTimer *timer;
    };

    QTcpServer server;
    QList<ClientInfo> clients;
    float temperature = 0.0;
    float humidity = 0.0;
    float carbon = 0.0;
    int doorBill = 0;
    int gate = 0;
    int connectedClientsCount = 0;
    int volume = 15;
    void parseData(const QByteArray &data);

    QThread sendThread;
    QThread receiveThread;
};

#endif // COMMUNICATIONCONTROLLER_H
