#ifndef ROBOT_H
#define ROBOT_H


#include <QGraphicsItem>
#include <QPainter>
#include <QRectF>
#include "robotcontroller.h"

class RobotController;

class Robot : public QGraphicsItem
{
public:
    Robot(RobotController &controller);
    ~Robot();
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    void setCoordinate(float x = 0,float y = 0,float theta = 0);        //设置坐标，单位m
    void setMapType(int mapType);               //设置球场类型
    float getXOfCoordinate();
    float getYOfCoordinate();
    float getTheta();

private:
    float xOfMap;           //像素
    float yOfMap;
    float theta;
    float xOfCoordinate;    //坐标
    float yOfCoordinate;
    float centerYOfMap;     //起始位置像素
    float centerXOfMap;
    int mapType;            //球场类型，0-左半场，1-右半场
    RobotController &controller;
};

#endif // ROBOT_H
