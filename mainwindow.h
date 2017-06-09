#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QDebug>

namespace Ui {
class MainWindow;
}

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

private:
    Ui::MainWindow *ui;
    QPixmap pixmap;         //地图显示区域
    QBitmap robotBitmap;    //机器人位图
};

#endif // MAINWINDOW_H
