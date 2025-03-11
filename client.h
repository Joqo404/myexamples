#ifndef CLIENT_H
#define CLIENT_H
#include <QUdpSocket>
#include <QObject>

class client : public QObject
{
    Q_OBJECT
public:
    explicit client(QObject *parent = nullptr);
    void start();
    void lisendatagram();
private:
    QUdpSocket *sock;
};


#endif // CLIENT_H
