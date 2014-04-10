#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QtNetwork>

class TCPClient : public QObject
{
    Q_OBJECT

public:
    static TCPClient * getInstance();
    virtual ~TCPClient();

    void wakeUpComputer(QHostAddress targetIPv4, QString MacAdress);

private:
    TCPClient();
    static TCPClient * mInstance;

    QTcpSocket * mSocket;

    QHostAddress mTargetIPv4;
    QString mTargetMacAdresse;

private slots:
    void sendMagicPacket();
};

#endif // TCPCLIENT_H
