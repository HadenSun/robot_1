#ifndef TCPSOCKET_H
#define TCPSOCKET_H
#include <QtNetwork>
#include <QByteArray>

extern int socketStat; //socket监听状态 0-未监听，1-监听
extern QByteArray str;

class Tcpserver : public QTcpServer
{
    Q_OBJECT

public:
    void getlisten() {this->listenConnection();}

signals:
    void renew_ui();


private slots:
    void listenConnection();

    void acceptConnection();

    void readClient();

private :

    QTcpSocket *rplidarConnection; //socket的tcp连接指针
    QTcpSocket *shijueConnection;


};



#endif // TCPSOCKET_H
