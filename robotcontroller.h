#ifndef ROBOTCONTROLLER_H
#define ROBOTCONTROLLER_H

#include <QObject>
#include "robot.h"
#include <QtNetwork>
#include <QThread>
#include <QDebug>

extern int socketStat; //socket监听状态 0-未监听，1-监听
extern QByteArray str;


class QGraphicsScene;
class QKeyEvent;
class Robot;

class RobotController : public QObject
{
    Q_OBJECT
public:
    enum MapType{
        LeftMap,
        RightMap
    };

    RobotController(QGraphicsScene &scene, QObject *parent = 0);
    ~RobotController();
    void robotInit(); //机器人初始化
    void setMapType(int mapType);
    void setRobotCoordinate(float x = 0,float y = 0,float theta = 0);
    void setRobotSpeedFromArm(float x = 0,float y = 0,float theta = 0);
    void getRobotCoordinate(float *x,float *y,float *theta);

private:
    QGraphicsScene &scene;
    Robot *pRobot;
    MapType mapType;
};


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

    QTcpSocket *clientConnection; //socket的tcp连接指针


};


class Thread : public QThread
{
protected:
    void run();
};


#endif // ROBOTCONTROLLER_H
