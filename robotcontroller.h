#ifndef ROBOTCONTROLLER_H
#define ROBOTCONTROLLER_H

#include <QObject>
#include "robot.h"
#define PI 3.141592654f
#define MOTOR_L 0.2013f

class QGraphicsScene;
class QKeyEvent;
class Robot;

class RobotController : public QObject
{
    Q_OBJECT
public:
    enum MapType
    {
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
    void robot_straight_stage(float X_I,float Y_I,float Theta_I);
    void set_motor_vx_vy_w(float vx,float vy,float w);
    void robot_turnOrigin_stage(float theta);
    float control1_W(float W);
    float control2_W(float W);
    float control3_W(float W);

private:
    QGraphicsScene &scene;
    Robot *pRobot;
    MapType mapType;
};




#endif // ROBOTCONTROLLER_H
