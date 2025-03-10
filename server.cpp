#include "server.h"

server::server() {
    QUdpSocket socket = new QUdpSocket(this);
    socket.bind(QHostAddress::LocalHost,1234);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}
