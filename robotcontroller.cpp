#include "robotcontroller.h"
#include "robot.h"
#include <QGraphicsScene>

RobotController::RobotController(QGraphicsScene & scene,QObject *parent) :
    QObject(parent),
    scene(scene),
    pRobot(new Robot(*this))
{
}

RobotController::~RobotController()
{
}

/* robotInit
 * 描述：robot初始化
 * 输入：无
 * 输出：无
 */
void RobotController::robotInit()
{
    switch (mapType) {
    case LeftMap:
        pRobot->setMapType(0);
        pRobot->setCoordinate(0,0);
        scene.addItem(pRobot);
        break;
    case RightMap:
        pRobot->setMapType(1);
        pRobot->setCoordinate(0,0);
        scene.addItem(pRobot);
        break;
    default:
        break;
    }
}

/* setMapType
 * 描述：设置地图类型
 * 输入：mapType - 0：左半场
 *                1：右半场
 * 输出：无
 */
void RobotController::setMapType(int mapType)
{
    switch (mapType) {
    case 0:
        this->mapType = LeftMap;
        break;
    case 1:
        this->mapType = RightMap;
        break;
    default:
        break;
    }
}

/* setRobotCoordinate
 * 描述：设置robot坐标，给手动设置坐标提供接口
 * 输入：x - X轴坐标
 *      y - Y轴坐标
 * 输出：无
 */
void RobotController::setRobotCoordinate(float x,float y,float theta)
{
    pRobot->setCoordinate(x,y,theta);
    scene.addItem(pRobot);
    scene.update();
}

/* setRobotSpeedFromArm
 * 描述：通过串口获得10ms内运动，传递给robot类并显示
 * 输入：x - x轴运动数据
 *      y - y轴运动数据
 *      theta - 自转运动数据
 * 输出：无
 */
void RobotController::setRobotSpeedFromArm(float x, float y, float theta)
{
    float xOfCoordinate = pRobot->getXOfCoordinate();
    float yOfCoordinate = pRobot->getYOfCoordinate();
    float thetaOfCoordinate = pRobot->getTheta();

    xOfCoordinate += x;
    yOfCoordinate += y;
    thetaOfCoordinate += theta;

    while(thetaOfCoordinate > 360)
        thetaOfCoordinate -= 360;

    while(thetaOfCoordinate < 0)
        thetaOfCoordinate += 360;

    pRobot->setCoordinate(xOfCoordinate,yOfCoordinate,thetaOfCoordinate);
    scene.addItem(pRobot);
    scene.update();
}

void RobotController::getRobotCoordinate(float *x, float *y, float *theta)
{
    *x = pRobot->getXOfCoordinate();
    *y = pRobot->getYOfCoordinate();
    *theta = pRobot->getTheta();
}
