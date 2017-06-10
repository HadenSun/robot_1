#ifndef ROBOTCONTROLLER_H
#define ROBOTCONTROLLER_H

#include <QObject>
#include "robot.h"

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

private:
    QGraphicsScene &scene;
    Robot *pRobot;
    MapType mapType;
};

#endif // ROBOTCONTROLLER_H
