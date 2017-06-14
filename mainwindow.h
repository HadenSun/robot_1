#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QDebug>
#include <QBitmap>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QtNetwork>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include "robotcontroller.h"
#include "robot.h"


namespace Ui {
class MainWindow;
}

class QGraphicsScene;
class QGraphicsView;
class RobotController;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *);

private slots:
    void on_restartButton_clicked();

    void on_leftGroundButton_clicked();

    void on_rightGroundButton_clicked();

    void on_handPositionButton_clicked();

    void on_serverButton_clicked();

    void socket_readPendingDatagrams();

    void on_comButton_clicked();

    void com_readData();

    void on_comRefreshButton_clicked();

    void on_shotButton_clicked();

private:
    void showMapLeft();
    void showMapRight();


    Ui::MainWindow *ui;
    QPixmap *pixmap;            //地图显示区域
    QGraphicsScene *scene;
    QGraphicsView *view;

    RobotController *controller;
    int mapType;                //场地类型，0-左半场，1-右半场

    QUdpSocket *udpSocket;      //socket的udp连接指针
    int socketStat;             //socket监听状态 0-未监听，1-监听

    QSerialPort *comPort;       //串口连接指针
    int comStat;

};

#endif // MAINWINDOW_H
