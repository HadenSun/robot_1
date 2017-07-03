#ifndef TCPSOCKET_H
#define TCPSOCKET_H
#include <QtNetwork>
#include <QByteArray>
#include <QString>

extern int socketStat; //socket监听状态 0-未监听，1-监听
extern QByteArray lidar;
extern QByteArray shijue;


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

    void readwriteClient();

    void sockSend();

private :

    QTcpSocket *rplidarConnection=NULL; //socket的tcp连接指针
    QTcpSocket *shijueConnection=NULL;


};



#endif // TCPSOCKET_H
