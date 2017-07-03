#ifndef THREAD_H
#define THREAD_H
#include <QThread>
#include "tcpsocket.h"
#include "robotcontroller.h"

#define PI 3.141592654f

class Thread1 : public QThread           //rplidar
{
protected:
    void run();
};

class Thread2 : public QThread          //shijue
{
    Q_OBJECT
signals:
    void sendData();

protected:
    void run();

};

class Thread3 : public QThread
{
public:
    Thread3(RobotController * robotcontroller);

protected:
    void run();

private:
    RobotController * robotcontroller;

};

#endif // THREAD_H
