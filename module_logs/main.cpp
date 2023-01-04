#include "mainwindow.h"

#include <QApplication>
#include <QDir>
#include <QDateTime>
#include <QTextStream>
#include <QDebug>
#include <iostream>

/* 日志文件系统
   1. 在main 函数中注册日志文件函数
   2. 使用写入文件函数
 */

/* 写入文件函数 */
void WriteLog(QString str, QString LogType) {

//    QDir dir;
//    QString dirName = "./log";
//    /* 判断根目录下是否有log文件夹，如果没有则创建log文件夹 */
//    if (!dir.exists(dirName))
//    {
//        dir.mkpath(dirName);
//    }
    QString fileFolder = qApp->applicationDirPath()+"/log/"+QDateTime::currentDateTime().toString("yyyy-MM-dd");
    QDir dir(fileFolder);
    if (!dir.exists())
    {
        dir.mkpath(fileFolder);
    }
    QString filePath = QString("%1/%2.log").arg(fileFolder).arg(LogType);
    QString strToWrite = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:zzz") + " " + QString("%1").arg(str);
//    strToWrite.append(QString("\r\n%1").arg(str));
    QFile file(filePath);
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream text_stream(&file);
    text_stream<<strToWrite<<"\r\n";
    file.flush();
    file.close();

//    std::cout<<strToWrite.toLocal8Bit().constData()<<std::endl;
}

/* 注册函数 */
void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
    QString txtMessage = "";
    QString messageType = "";
    switch (type) {
    case QtDebugMsg:  // 调试信息提示
        messageType = "Debug";
        txtMessage = QString("Debug: %1 (%2:%3,%4)\n").arg(msg).arg(context.file).arg(QString::number(context.line)).arg(context.function);
        break;
    case QtInfoMsg: // 
        messageType = "Info";
        txtMessage = QString("Info: %1 (%2:%3,%4)\n").arg(msg).arg(context.file).arg(QString::number(context.line)).arg(context.function);
        break;
    case QtWarningMsg: // 一般warning提示
        messageType = "Warning";
        txtMessage = QString("Warning: %1 (%2:%3,%4)\n").arg(msg).arg(context.file).arg(QString::number(context.line)).arg(context.function);
        break;
    case QtCriticalMsg: // 严重错误提示
        messageType = "Critical";
        txtMessage = QString("Critical: %1 (%2:%3,%4)\n").arg(msg).arg(context.file).arg(QString::number(context.line)).arg(context.function);
        break;
    case QtFatalMsg: // 致命错误提示
        messageType = "Fatal";
        txtMessage = QString("Fatal: %1 (%2:%3,%4)\n").arg(msg).arg(context.file).arg(QString::number(context.line)).arg(context.function);
        abort();
    }
    WriteLog(txtMessage, messageType);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // 注册监听级别函数
    qInstallMessageHandler(myMessageOutput);
    qDebug() <<"debug";
    MainWindow w;
    w.show();
    return a.exec();
}
