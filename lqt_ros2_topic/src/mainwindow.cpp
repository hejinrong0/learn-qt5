#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QStringListModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    commNode = new rclcomm(); // 指针初始化
    commNode->start(); // 自动调用类中的run()函数 void rclcomm::run()

    // 连接信号 RCLCOMM 的信号槽
    connect(commNode, SIGNAL(emitTopicData(QString)),this,SLOT(onRecvData(QString)));

    // 发布话题按钮
    connect(ui->publisherBtn,&QPushButton::clicked,this,&MainWindow::CreateRos2Topic);
    // 订阅话题
    connect(ui->subscriberBtn,&QPushButton::clicked,this,&MainWindow::SubRos2Topic);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CreateRos2Topic()
{
    ui->publishLabel->clear();
    ui->publishLabel->setText("create ros2 topic");
}

void MainWindow::SubRos2Topic()
{
    ui->subscribeLabel->clear();
    ui->subscribeLabel->setText("sub ros2 topic");
}

void MainWindow::onRecvData(QString msg)
{
//    ui->label->clear();
//    ui->label->setText(msg);

    // 向QListView添加数据
    QStringListModel *model;
    model = new QStringListModel(this);
    model->setStringList(QStringList()<<msg);

    ui->listView->setModel(model);
}

