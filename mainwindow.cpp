#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    scene(new QGraphicsScene(this)),
    view(new QGraphicsView(scene,this)),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //在主界面添加view
    ui->horizontalLayout->addWidget(view);
    //设置scene大小
    scene->setSceneRect(0,0,720,545);
    //默认左上角
    view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    view->setFixedSize(725,550);

    //设置view背景
    pixmap = new QPixmap(720,545);
    QPainter p(pixmap);
    p.setBrush(QBrush(Qt::gray));
    p.drawRect(0,0,720,545);
    view->setBackgroundBrush(QBrush(*pixmap));
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* paintEvent
 * 描述：ui启动绘制事件
 * 输入：QPaintEvent -
 * 输出：无
 */
void MainWindow::paintEvent(QPaintEvent *)
{
    //showMapLeft();
}

/* showMapLeft
 * 描述：绘制左半场地图
 * 输入：无
 * 输出：无
 */
void MainWindow::showMapLeft()
{
    //清除现有pixmap
    QPixmap *pPixmap;
    pPixmap = pixmap;
    pixmap = new QPixmap(720,545);
    pPixmap->~QPixmap();

    QPainter painter(pixmap);
    //设置背景色
    painter.setPen(Qt::gray);
    painter.setBrush(Qt::gray);
    painter.drawRect(0,0,720,545);

    //设置线条颜色
    painter.setPen(Qt::black);
    painter.setBrush(Qt::transparent);

    //绘制球场边界
    QPainterPath groundPath;
    groundPath.moveTo(710,110);
    groundPath.lineTo(10,110);
    groundPath.lineTo(10,485);
    groundPath.lineTo(710,485);
    groundPath.moveTo(660,485);
    groundPath.lineTo(660,535);
    groundPath.lineTo(610,535);
    groundPath.lineTo(610,485);
    groundPath.moveTo(710,485);
    groundPath.lineTo(710,110);
    groundPath.moveTo(10,110);
    groundPath.lineTo(10,10);
    painter.drawPath(groundPath);

    //中圈线
    QPainterPath centerPath;
    centerPath.moveTo(620,110);
    centerPath.arcTo(620,20,180,180,180,90);
    centerPath.moveTo(580,110);
    centerPath.arcTo(580,-20,260,260,180,90);
    centerPath.moveTo(540,110);
    centerPath.arcTo(540,-60,340,340,180,90);
    painter.drawPath(centerPath);

    //三分线
    QPainterPath threePath;
    threePath.moveTo(10,437.5);
    threePath.lineTo(173.1,437.5);
    threePath.arcTo(-248.75,-227.5,675,675,284,166);
    painter.drawPath(threePath);

    //罚球线
    QPainterPath freeThrowPath;
    freeThrowPath.moveTo(210,110);
    freeThrowPath.arcTo(210,20,180,180,180,360);
    painter.drawPath(freeThrowPath);

    //投篮边线
    QPainterPath basketLinePath;
    basketLinePath.moveTo(10,171.64);
    basketLinePath.arcTo(-11.25,10,200,200,218,284);
    painter.drawPath(basketLinePath);

    //底线置球位
    QPainterPath endBallPath;
    endBallPath.moveTo(97.5,460);
    endBallPath.lineTo(60,460);
    painter.drawPath(endBallPath);

    //篮筐
    QPainterPath basketPath;
    basketPath.moveTo(88.75,85);
    basketPath.lineTo(88.75,135);
    painter.setPen(Qt::red);
    painter.drawPath(basketPath);


    view->setBackgroundBrush(QBrush(*pixmap));
}

/* showMapRight
 * 描述：右半场地图绘制
 * 输入：无
 * 输出：无
 */
void MainWindow::showMapRight()
{
    //清除现有pixmap
    QPixmap *pPixmap;
    pPixmap = pixmap;
    pixmap = new QPixmap(720,545);
    pPixmap->~QPixmap();

    QPainter painter(pixmap);
    //设置背景色
    painter.setPen(Qt::gray);
    painter.setBrush(Qt::gray);
    painter.drawRect(0,0,720,545);

    //设置线条颜色
    painter.setPen(Qt::black);
    painter.setBrush(Qt::transparent);

    //绘制球场边界
    QPainterPath groundPath;
    groundPath.moveTo(10,110);
    groundPath.lineTo(710,110);
    groundPath.lineTo(710,485);
    groundPath.lineTo(10,485);
    groundPath.moveTo(60,485);
    groundPath.lineTo(60,535);
    groundPath.lineTo(110,535);
    groundPath.lineTo(110,485);
    groundPath.moveTo(10,485);
    groundPath.lineTo(10,110);
    groundPath.moveTo(710,110);
    groundPath.lineTo(710,10);
    painter.drawPath(groundPath);

    //中圈线
    QPainterPath centerPath;
    centerPath.moveTo(10,200);
    centerPath.arcTo(-80,20,180,180,270,90);
    centerPath.moveTo(10,240);
    centerPath.arcTo(-120,-20,260,260,270,90);
    centerPath.moveTo(10,280);
    centerPath.arcTo(-160,-60,340,340,270,90);
    painter.drawPath(centerPath);

    //三分线
    QPainterPath threePath;
    threePath.moveTo(631.25,-227.5);
    threePath.arcTo(293.75,-227.5,675,675,90,166);
    threePath.lineTo(710,437.5);
    painter.drawPath(threePath);

    //罚球线
    QPainterPath freeThrowPath;
    freeThrowPath.moveTo(330,110);
    freeThrowPath.arcTo(330,20,180,180,180,360);
    painter.drawPath(freeThrowPath);

    //投篮边线
    QPainterPath basketLinePath;
    basketLinePath.moveTo(710,48.36);
    basketLinePath.arcTo(531.25,10,200,200,38,284);
    painter.drawPath(basketLinePath);

    //底线置球位
    QPainterPath endBallPath;
    endBallPath.moveTo(622.5,460);
    endBallPath.lineTo(660,460);
    painter.drawPath(endBallPath);

    //篮筐
    QPainterPath basketPath;
    basketPath.moveTo(631.25,85);
    basketPath.lineTo(631.25,135);
    painter.setPen(Qt::red);
    painter.drawPath(basketPath);


    view->setBackgroundBrush(QBrush(*pixmap));
}

/* on_restartButton_clicked
 * 描述：重置按钮点击
 * 输入：无
 * 输出：无
 */
void MainWindow::on_restartButton_clicked()
{
    qDebug() << this->size();
}

/* on_leftGroundButton_clicked
 * 描述：绘制左半场按钮点击事件
 * 输入：无
 * 输出：无
 */
void MainWindow::on_leftGroundButton_clicked()
{
    showMapLeft();

}

/* on_rightGroundButton_clicked
 * 描述：绘制右半场按钮点击事件
 * 输入：无
 * 输出：无
 */
void MainWindow::on_rightGroundButton_clicked()
{
    showMapRight();
}
