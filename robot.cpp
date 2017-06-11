#include "robot.h"

Robot::Robot(RobotController &controller) :
    controller(controller)
{
    xOfCoordinate = 0;
    yOfCoordinate = 0;
    xOfMap = 0;
    yOfMap = 0;
}

Robot::~Robot()
{

}

/* shape
 * 描述：继承自父类，抽象类复写，元素外观,按照60cm计算
 * 输入：无
 * 输出：元素路径
 */
QPainterPath Robot::shape() const
{
    QPainterPath path;
    path.addRect(QRectF(xOfMap-15,yOfMap-15,30,30));

    return path;
}

/* paint
 * 描述：继承自父类，抽象类实例化复写
 * 输入：
 * 输出：无
 */
void Robot::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    painter->fillPath(shape(),Qt::yellow);
    painter->restore();
}

/* boundingRect
 * 描述：继承自父类，抽象类复写，标定元素范围，按100cm计算
 * 输入：无
 * 输出：无
 */
QRectF Robot::boundingRect() const
{
    QRectF bound = QRectF(xOfMap,yOfMap,50,50);

    return bound;
}

/* setPosition
 * 描述：设定robot中心位置，单位m
 * 输入：x - X轴位置
 *      y - Y轴位置
 * 输出：无
 */
void Robot::setCoordinate(float x,float y)
{
    this->xOfCoordinate = x;
    this->yOfCoordinate = y;

    xOfMap = centerXOfMap + x * 50;
    yOfMap = centerYOfMap - y * 50;
}

/* setMapType
 * 描述：设置球场类型
 * 输入：mapType - 0：左半场
 *                1：右半场
 * 输出：无
 */
void Robot::setMapType(int mapType)
{
    this->mapType = mapType;
    switch (mapType) {
    case 0:
        centerXOfMap = 635;
        centerYOfMap = 510;
        break;
    case 1:
        centerXOfMap = 85;
        centerYOfMap = 510;
        break;
    default:
        break;
    }
}
