#include "tcpsocket.h"
#include <QDebug>
#include <thread.h>

void Thread1::run()
{
    while(1)
    {
        qDebug()<<str;

        //初步设想雷达处理程序在此运行
    }
}

void Thread2::run()
{
    while(1)
    {
        qDebug()<<"thread 2";
    }
}
