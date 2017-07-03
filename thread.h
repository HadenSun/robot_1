#ifndef THREAD_H
#define THREAD_H
#include <QThread>
#include "tcpsocket.h"

class Thread1 : public QThread
{
protected:
    void run();
};

class Thread2 : public QThread
{
    Q_OBJECT
signals:
    void sendData();

protected:
    void run();

};

#endif // THREAD_H
