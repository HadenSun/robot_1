#include "tcpsocket.h"
#include <QDebug>
#include <thread.h>
#include <QtMath>



void Thread1::run()
{
    //激光处理数据
    int data[2];//data[0] 角度 data[1] 深度
    if(lidar[0]!=' ')
            data[1]=(lidar[0]-'0')*1000;
    else
            data[1]=0;
    lidar[0]= ' ';
    if(lidar[1]!=' ')
            data[1]+=(lidar[1]-'0')*100;
    lidar[1] = ' ';
    if(lidar[2]!=' ')
            data[1]+=(lidar[2]-'0')*10;
    lidar[2] = ' ';
    if(lidar[3]!=' ')
            data[1] +=(lidar[3]-'0');
    lidar[3] = ' ';


    if(lidar[4]!=' ')
            data[0]=(lidar[4]-'0')*100;
    else
            data[0]=0;
    lidar[4] = ' ';
    if(lidar[5]!=' ')
            data[0]+=(lidar[5]-'0')*10;
    lidar[5] = ' ';
    if(lidar[6]!=' ')
            data[0]+=(lidar[6]-'0');
    lidar[6] = ' ';






    while(1)
    {

        if(socketStat)
        {

          qDebug()<<"dep"<<data[1]<<"ang"<<data[0];
        }


        //初步设想雷达处理程序在此运行
    }

}


void Thread2::run()
{
    while(1)
    {   if(socketStat)
        {
        qDebug()<<shijue;
        emit sendData(); //发送信号->发送数据给视觉处理
        }
    }

}

Thread3::Thread3(RobotController * robotcontroller)
{
   this->robotcontroller=robotcontroller;

}

void Thread3::run()
{
   qDebug()<<"thread3";

}
