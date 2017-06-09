#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pixmap = QPixmap(720,545);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(&pixmap);
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


    ui->label->setPixmap(pixmap);
}

void MainWindow::on_restartButton_clicked()
{
    qDebug() << this->size();
}

void MainWindow::on_leftGroundButton_clicked()
{
    qDebug() << ui->horizontalLayout->sizeHint();
}

void MainWindow::on_rightGroundButton_clicked()
{
    qDebug() << ui->verticalLayout->sizeHint();
}
