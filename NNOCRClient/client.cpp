#include <iostream>
#include <QDebug>
#include <QBitArray>
#include "client.h"

using namespace std;

Client::Client()
{
    QTextStream cin(stdin);
    tcpSocket = new QTcpSocket(this);
    ds.setDevice(tcpSocket);
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(displayIncoming()));
    tcpSocket->abort();
    tcpSocket->connectToHost(QHostAddress("127.0.0.1"),6666);
    cout <<"Connecting to server."<<endl;
    if (tcpSocket->waitForConnected(1000)){
        text = "add|http://www.selab.isti.cnr.it/ws-mate/example.pdf";
        ds << QByteArray().append(text).toBase64();
    }
}

void Client::displayIncoming(){
    QTextStream cin(stdin);

    ds >> response;
    qDebug() << QString(QByteArray::fromBase64(response));

    text = cin.readLine();
    if(text == "quit") {
        tcpSocket->waitForBytesWritten(1000);
        tcpSocket->disconnectFromHost();
        exit(0);
    }

    ds << QByteArray().append(text).toBase64();
}
