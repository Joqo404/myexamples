#ifndef SERVER_H
#define SERVER_H
#include <QUdpSocket>

class server
{
public:
    server(){
        QUdpSocket socket = new QUdpSocket(this);
        socket.bind(QHostAddress::LocalHost,1234);
    }
};

#endif // SERVER_H
