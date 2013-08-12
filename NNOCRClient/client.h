#ifndef CLIENT_H
#define CLIENT_H

#include <QtNetwork>
#include <QtCore>

class Client : public QObject
{
    Q_OBJECT
public:
    Client();
private slots:
    void displayIncoming();
private:
    QTcpSocket *tcpSocket;
    QDataStream ds;
    QString text;
    QByteArray response;
};

#endif // CLIENT_H
