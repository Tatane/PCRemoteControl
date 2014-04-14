#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QtNetwork>

class TCPClient : public QObject
{
    Q_OBJECT

public:
    static TCPClient * getInstance();
    virtual ~TCPClient();

    void wakeUpComputer(QString targetIPv4, QString MacAdress, quint16 port);

private:
    TCPClient();
    static TCPClient * mInstance;

    QTcpSocket * mSocket;

    QHostAddress mTargetIPv4;
    QString mTargetMacAdresse;

signals:
    void writeToConsole(QString);


private slots:
    void sendMagicPacket();
};

#endif // TCPCLIENT_H
