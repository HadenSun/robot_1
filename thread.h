#ifndef THREAD_H
#define THREAD_H
#include <QThread>

class Thread1 : public QThread
{
protected:
    void run();
};

class Thread2 : public QThread
{
protected:
    void run();
};

#endif // THREAD_H
