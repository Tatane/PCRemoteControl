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

void TCPClient::wakeUpComputer(QHostAddress targetIPv4, QString MacAdress)
{
    mTargetIPv4 = targetIPv4;
    mTargetMacAdresse = MacAdress;

    mSocket = new QTcpSocket();
    connect(mSocket, SIGNAL(connected()), this, SLOT(sendMagicPacket()));

    mSocket->connectToHost(targetIPv4, PORT_WAL, QTcpSocket::ReadWrite);
}

TCPClient::TCPClient()
    : mTargetIPv4("0:0:0:0")
    , mTargetMacAdresse("00:00:00:00:00:00")
{
}

void TCPClient::sendMagicPacket()
{
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
}
