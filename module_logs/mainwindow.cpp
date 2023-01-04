#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->horizontalHeader()->resizeSection(1, 250);

    // 触发测试日志
    connect(ui->actionLog,&QPushButton::clicked,this,&MainWindow::WriteLogs);
    // 清除日志
    connect(ui->clearBtn,&QPushButton::clicked,this,&MainWindow::ClearLogs);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::WriteLogs()
{
    QString loopTestStr = ui->loopTest->text();
    qDebug() << "input loop Test" << loopTestStr;
    if (loopTestStr == "") {
        qInfo("loopTestStr is not exits");
        return;
    }

    ClearLogs();

    int loopTestNum = loopTestStr.toInt();

//    ui->tableWidget->setRowCount(loopTestNum);

//    int rowCount = ui->tableWidget->rowCount();
//    ui->tableWidget->insertRow(rowCount);

    for (int i = 0; i < loopTestNum; i = i + 1) {
//        int rowCount = ui->tableWidget->rowCount();
//        ui->tableWidget->insertRow(rowCount);
        ui->tableWidget->insertRow(i);
        QTableWidgetItem *newItem = new QTableWidgetItem(tr("this is %1").arg(i));
        ui->tableWidget->setItem(i, 0, newItem);
        QTableWidgetItem *it = new QTableWidgetItem(tr("%1").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:zzz")));
        ui->tableWidget->setItem(i, 1, it);
        qInfo("this is qtablewidgetitem");
//        QThread::msleep(1000);
        ui->tableWidget->repaint();
        ui->tableWidget->scrollToBottom();
    }
}
void MainWindow::ClearLogs()
{
    qInfo("clear logs");
//    ui->tableWidget->clear();
    ui->tableWidget->clearContents();
    quint16 table_listCount = ui->tableWidget->rowCount();
    qInfo() << table_listCount;
    for (int i = table_listCount; i >= 0; i--) {
        ui->tableWidget->removeRow(i);
    }
//    ui->tableWidget->removeRow();
}
