#include "tcpsocket.h"
#include <QDebug>
#include <thread.h>
#include <qmath.h>



void Thread1::run()
{
    int dep=0;
    int ang=0;
    for(int i=0;i<4;i++)
    {
        if(lidar[i]==' ')
            break;
        else
        {
            dep=dep+lidar[i]*(10^(3-i));
        }
    }

    for(int i=4;i<7;i++)
    {
        if(lidar[i]==' ')
            break;
        else
        {
            ang=ang+lidar[i]*(10^(6-i));
        }
    }

    while(1)
    {

        if(socketStat)
        qDebug()<<"dep"<<dep<<"ang"<<ang;


        //初步设想雷达处理程序在此运行
    }

}


void Thread2::run()
{
    while(1)
    {   if(socketStat)
        {
        qDebug()<<shijue;
        if(shijue=="1000")
        emit sendData();
        }
    }

}
