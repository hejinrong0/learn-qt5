#include <QCoreApplication>
#include <QProcess>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    // 创建QProcess对象并设置外部程序命令和参数
    QProcess process;
    process.setProgram("ping");
    process.setArguments(QStringList() << "www.google.com");

    // 开始执行外部程序
    process.start();

    // 连接readyReadStandardOutput()信号以在输出可用时更新GUI界面
    QObject::connect(&process, &QProcess::readyReadStandardOutput, [&process]() {
        QString output(process.readAllStandardOutput());
        qDebug() << output;
        // 在此处更新GUI界面
    });

    // 等待外部程序执行完毕
    process.waitForFinished();

    // 读取外部程序输出并打印到控制台
    QString output(process.readAllStandardOutput());
    qDebug() << output;

    return app.exec();
}
