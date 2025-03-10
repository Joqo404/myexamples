#include "server.h"

server::server(QObject *parent) : QObject(parent) {
    sock = new QUdpSocket(this);
    sock->bind(QHostAddress::LocalHost, 1234);
    connect(sock, &QUdpSocket::readyRead, this, &server::readDatagrams);
}

void server::readDatagrams(){
    while(sock->hasPendingDatagrams()){
        QByteArray buffer;
        buffer.resize(sock->pendingDatagramSize());
        QHostAddress senderAddress; // Адрес отправителя
        quint16 senderPort;
        sock->readDatagram(buffer.data(),buffer.size(),&senderAddress, &senderPort);
        qDebug() << "Received message:" << buffer << "from" << senderAddress.toString() <<
                 <<":" << senderPort;

    }
}
