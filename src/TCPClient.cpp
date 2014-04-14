#include "TCPClient.h"


const quint16 PORT_WAL = 9;

TCPClient* TCPClient::mInstance = 0;

TCPClient *TCPClient::getInstance()
{
    if (mInstance == 0){
        mInstance= new TCPClient();
    }
    return mInstance;
}

TCPClient::~TCPClient()
{

}

void TCPClient::wakeUpComputer(QString targetIPv4, QString MacAdress, quint16 port)
{
    mTargetIPv4 = targetIPv4;
    mTargetMacAdresse = MacAdress;

    mSocket = new QTcpSocket();

    QHostAddress adresseIP;
    bool b = adresseIP.setAddress(targetIPv4);
    QString temp("Parsing IP(%1) : %2 => %3");
    temp = temp.arg(targetIPv4).arg(b?"Success":"Failure").arg(adresseIP.toString());
    writeToConsole(temp);

    connect(mSocket, SIGNAL(connected()), this, SLOT(sendMagicPacket()));

    mSocket->connectToHost(adresseIP, port, QTcpSocket::ReadWrite);
}

TCPClient::TCPClient()
    : mTargetIPv4("0.0.0.0")
    , mTargetMacAdresse("00:00:00:00:00:00")
{
}

void TCPClient::sendMagicPacket()
{
    writeToConsole("Connected. Sending magic packet...");
    QByteArray trame;

    for(int i=0; i<6; ++i){
        trame.append(255);
    }

    qDebug()<<"macadress is"<<mTargetMacAdresse;

    for(int i=0; i<16; i++)
    {
        QStringList splittedMacAdress = mTargetMacAdresse.split(':');
        foreach (QString macAdressPart, splittedMacAdress) {
            int value = macAdressPart.toInt(0, 16);
            trame.append(value);
        }
    }

    int n = mSocket->write(trame.constData(), 102);
    writeToConsole(QString("%1 octets écrits").arg(n));
}
