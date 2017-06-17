#include "mainwindow.h"
#include "robotcontroller.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    scene(new QGraphicsScene(this)),
    view(new QGraphicsView(scene,this)),
    controller(new RobotController(*scene,this)),
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

    //读取COM口信息
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        ui->comComboBox->addItem(info.portName());
    }


    //默认初始化
    ui->xLineEdit->setText("0");
    ui->yLineEdit->setText("0");
    ui->thetaLineEdit->setText("0");
    mapType = 0;
    socketStat = 0;
    comStat = 0;
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
    ui->xLineEdit->setText("0");
    ui->yLineEdit->setText("0");
    ui->thetaLineEdit->setText("0");

    switch (mapType) {
    case 0:
        showMapLeft();
        controller->setMapType(0);
        controller->robotInit();
        break;
    case 1:
        showMapRight();
        controller->setMapType(1);
        controller->robotInit();
        break;
    default:
        break;
    }
}

/* on_leftGroundButton_clicked
 * 描述：绘制左半场按钮点击事件
 * 输入：无
 * 输出：无
 */
void MainWindow::on_leftGroundButton_clicked()
{
    showMapLeft();
    mapType = 0;
    controller->setMapType(0);
    controller->robotInit();
}

/* on_rightGroundButton_clicked
 * 描述：绘制右半场按钮点击事件
 * 输入：无
 * 输出：无
 */
void MainWindow::on_rightGroundButton_clicked()
{
    showMapRight();
    mapType = 1;
    controller->setMapType(1);
    controller->robotInit();
}

/* on_handPositionButton_clicked
 * 描述：手动设置机器人位置按钮点击事件
 * 输入：无
 * 输出：无
 */
void MainWindow::on_handPositionButton_clicked()
{
    float x,y,theta;
    x = ui->xLineEdit->text().toFloat();
    y = ui->yLineEdit->text().toFloat();
    theta = ui->thetaLineEdit->text().toFloat();

    controller->setRobotCoordinate(x,y,theta);
}


/* on_serverButton_clicked
 * 描述：建立udp的server端监听
 * 输入：无
 * 输出：无
 */
void MainWindow::on_serverButton_clicked()
{
    if(socketStat == 0)
    {
        //获取端口
        int port = ui->portLineEdit->text().toInt();
        if(port == 0)
            port = 6655;
        ui->portLineEdit->setText(QString::number(port));

        //初始化socket
        udpSocket = new QUdpSocket(this);
        udpSocket->bind(QHostAddress::LocalHost,port);
        connect(udpSocket,SIGNAL(readyRead()),this,SLOT(socket_readPendingDatagrams()));

        //ui部分调整
        ui->serverButton->setText("Server关闭");
        ui->portLineEdit->setEnabled(false);
        socketStat = 1;
    }
    else
    {
        //关闭socket
        disconnect(udpSocket,SIGNAL(readyRead()),this,SLOT(socket_readPendingDatagrams()));
        delete udpSocket;
        //ui调整
        ui->serverButton->setText("Server打开");
        ui->portLineEdit->setEnabled(true);
        socketStat = 0;
    }
}

/* socket_readPendingDatagrams
 * 描述：udp连接接收槽函数
 * 输入：无
 * 输出：无
 */
void MainWindow::socket_readPendingDatagrams()
{
    QByteArray datagram;
    while(udpSocket->hasPendingDatagrams())
    {
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(),datagram.size());
    }
    ui->socketLineEditer->setText(datagram.data());
}

/* on_comButton_clicked
 * 描述：点击打开串口
 * 输入：无
 * 输出：无
 */
void MainWindow::on_comButton_clicked()
{
    if(comStat == 0)
    {
        //获取选择的波特率
        int baudId = ui->baudRateComboBox->currentIndex();
        QSerialPort::BaudRate baudRate;
        switch (baudId) {
        case 0:
            baudRate = QSerialPort::Baud1200;
            break;
        case 1:
            baudRate = QSerialPort::Baud2400;
            break;
        case 2:
            baudRate = QSerialPort::Baud4800;
            break;
        case 3:
            baudRate = QSerialPort::Baud9600;
            break;
        case 4:
            baudRate = QSerialPort::Baud19200;
            break;
        case 5:
            baudRate = QSerialPort::Baud38400;
            break;
        case 6:
            baudRate = QSerialPort::Baud57600;
            break;
        case 7:
            baudRate = QSerialPort::Baud115200;
            break;
        default:
            QMessageBox::warning(NULL,"警告","无效波特率！",QMessageBox::Yes);
            break;
        }

        //获取数据位
        int dataBitsId = ui->dataBitsComboBox->currentIndex();
        QSerialPort::DataBits dataBits;
        switch (dataBitsId) {
        case 0:
            dataBits = QSerialPort::Data5;
            break;
        case 1:
            dataBits = QSerialPort::Data6;
            break;
        case 2:
            dataBits = QSerialPort::Data7;
            break;
        case 3:
            dataBits = QSerialPort::Data8;
            break;
        default:
            QMessageBox::warning(NULL,"警告","无效数据位！",QMessageBox::Yes);
            break;
        }

        //获取校验位
        int parityId = ui->parityComboBox->currentIndex();
        QSerialPort::Parity parity;
        switch (parityId) {
        case 0:
            parity = QSerialPort::NoParity;
            break;
        case 1:
            parity = QSerialPort::EvenParity;
            break;
        case 2:
            parity = QSerialPort::OddParity;
            break;
        case 3:
            parity = QSerialPort::SpaceParity;
            break;
        case 4:
            parity = QSerialPort::MarkParity;
            break;
        default:
            QMessageBox::warning(NULL,"警告","无效校验位！",QMessageBox::Yes);
            break;
        }

        //获取停止位
        int stopBitsId = ui->stopBitsComboBox->currentIndex();
        QSerialPort::StopBits stopBits;
        switch (stopBitsId) {
        case 0:
            stopBits = QSerialPort::OneStop;
            break;
        case 1:
            stopBits = QSerialPort::OneAndHalfStop;
            break;
        case 2:
            stopBits = QSerialPort::TwoStop;
            break;
        default:
            QMessageBox::warning(NULL,"警告","无效停止位！",QMessageBox::Yes);
            break;
        }

        QString comName = ui->comComboBox->currentText();

        //打开串口
        comPort = new QSerialPort(comName);
        if(comPort->open(QIODevice::ReadWrite))
        {
            comPort->setBaudRate(baudRate);
            comPort->setStopBits(stopBits);
            comPort->setParity(parity);
            comPort->setDataBits(dataBits);
            comPort->setFlowControl(QSerialPort::NoFlowControl);        //没有流控

            comPort->clearError();
            comPort->clear();
            connect(comPort,SIGNAL(readyRead()),this,SLOT(com_readData()));

            //修改UI
            ui->comButton->setText("关闭串口");
            ui->baudRateComboBox->setEnabled(false);
            ui->dataBitsComboBox->setEnabled(false);
            ui->parityComboBox->setEnabled(false);
            ui->stopBitsComboBox->setEnabled(false);
            ui->comComboBox->setEnabled(false);
            ui->comRefreshButton->setEnabled(false);
            comStat = 1;
        }
        else
        {
            //打开串口失败
            QMessageBox::warning(NULL,"警告","打开串口失败",QMessageBox::Yes);
            delete comPort;
        }

    }
    else
    {
        //关闭串口
        comPort->close();
        delete comPort;
        //ui调整
        ui->comButton->setText("打开串口");
        ui->baudRateComboBox->setEnabled(true);
        ui->dataBitsComboBox->setEnabled(true);
        ui->parityComboBox->setEnabled(true);
        ui->stopBitsComboBox->setEnabled(true);
        ui->comComboBox->setEnabled(true);
        ui->comRefreshButton->setEnabled(true);
        comStat = 0;
    }

}

/* com_readData
 * 描述：COM口数据读入槽
 * 输入：无
 * 输出：无
 */
void MainWindow::com_readData()
{
    QByteArray arr = comPort->readAll();
    unsigned char *data = (unsigned char *)arr.data();
    QPalette palette;

    if(data[0] == 0xA5 && data[1] == 0x5A)
    {
        if(comCheckSum(data,arr.size()))
        {
            palette.setColor(QPalette::Text,Qt::black);
            //校验通过，图像更新
            float x,y,theta;
            x = data[2] / 100.0f;
            y = data[3] / 100.0f;
            theta = data[4] / 100.0f;
            controller->setRobotSpeedFromArm(x,y,theta);

            controller->getRobotCoordinate(&x,&y,&theta);
            ui->xLineEdit->setText(QString::number(x));
            ui->yLineEdit->setText(QString::number(y));
            ui->thetaLineEdit->setText(QString::number(theta));
        }
        else
            palette.setColor(QPalette::Text,Qt::red);
    }
    else
    {
        palette.setColor(QPalette::Text,Qt::red);
    }

    ui->comLineEdit->setPalette(palette);
    ui->comLineEdit->setText(arr.data());
}

/* on_comRefreshButton_clicked
 * 描述：刷新按钮按下，刷新com口信息
 * 输入：无
 * 输出：无
 */
void MainWindow::on_comRefreshButton_clicked()
{
    //清空原来内容
    ui->comComboBox->clear();
    //遍历可用串口号
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        ui->comComboBox->addItem(info.portName());
    }
}

/* on_shotButton_clicked
 * 描述：弹射开关，现暂时用作串口发送
 * 输入：无
 * 输出：无
 */
void MainWindow::on_shotButton_clicked()
{
    if(comStat == 1)
    {
        comPort->clearError();
        comPort->write("hello");

        if(comPort->error() != QSerialPort::NoError)
            QMessageBox::warning(NULL,"警告","数据发送失败！",QMessageBox::Yes);
        comPort->clearError();
    }
}

/* comCheckSum
 * 描述：串口接收数据和校验
 * 输入：*data - 接收数据指针
 *      size - 数据长度
 * 输出：校验结果
 */
bool MainWindow::comCheckSum(unsigned char *data, int size)
{
    unsigned char checksum = 0;
    for (int i = 1;i < size;i++) {
        checksum += *data++;
    }

    if(checksum == *data)
        return true;
    else
        return false;
}
