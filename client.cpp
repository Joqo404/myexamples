#include "client.h"
#include <QDebug>

client::client(QObject *parent) : QObject(parent) {
    sock = new QUdpSocket(this);
    start();
}

void client::start() {
    QHostAddress serverAddress = QHostAddress::Any;
    quint16 serverPort = 1234;
    if (!sock->bind(QHostAddress::LocalHost, 1235)) {
        qDebug() << "Failed to bind socket:" << sock->errorString();
    } else {
        qDebug() << "client: started on port 1235";
    }
    // Данные для отправки
    QByteArray data = "client: zdarova zaebal!";

    // Отправка данных на сервер
    qint64 bytesSent = sock->writeDatagram(data, serverAddress, serverPort);

    if (bytesSent == -1) {
        qDebug() << "не вышло" << sock->errorString();
    } else {
        qDebug() << "client: данные отправленны:" << data;
    }
    //Ответ от сервера

}
