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
