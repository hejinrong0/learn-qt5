#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rclcomm.h" // 导入rclcomm头文件来实例化类

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void CreateRos2Topic();
    void SubRos2Topic();
    rclcomm *commNode; // 声明通信类
public slots:
    void onRecvData(QString);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
