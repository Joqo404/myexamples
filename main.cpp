#include <QCoreApplication>
#include <QUdpSocket>
#include "server.h"
#include "client.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    server server;
    client client;
    return a.exec();
}
