#include "server.h"
#include <QDebug>

server::server(QObject *parent) : QObject(parent) {
    sock = new QUdpSocket(this);
    //бинд сервака к адресу и порту
    if (!sock->bind(QHostAddress::LocalHost, 1234)) {
        qDebug() << "Failed to bind socket:" << sock->errorString();
    } else {
        qDebug() << "Server started on port 1234";
    }

    connect(sock, &QUdpSocket::readyRead, this, &server::readDatagrams);
}

void server::sayhello(){
    qDebug() << "hello";
}

void server::readDatagrams(){
    qDebug() << "он пытается...";
    while (sock->hasPendingDatagrams()) {
        qDebug() << "херачит!";
        QByteArray buffer;
        buffer.resize(sock->pendingDatagramSize());
        QHostAddress senderAddress;
        quint16 senderPort;
        sock->readDatagram(buffer.data(), buffer.size(), &senderAddress, &senderPort);
        qDebug() <<"server:\n" << "Received message:" << buffer << "from" << senderAddress.toString()
                 << ":" << senderPort;
    }
}
