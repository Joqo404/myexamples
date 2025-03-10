#include <QCoreApplication>
#include <QUdpSocket>
#include "server.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    server server;
    return a.exec();
}
