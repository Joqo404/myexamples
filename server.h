#ifndef SERVER_H
#define SERVER_H
#include <QUdpSocket>
#include <QObject>

class server : public QObject
{
    Q_OBJECT
public:
    explicit server(QObject *parent = nullptr);
    void readDatagrams();
private:
    QUdpSocket *sock;
};


#endif // SERVER_H
