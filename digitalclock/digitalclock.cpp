
#include <QtWidgets>

#include "digitalclock.h"

DigitalClock::DigitalClock(QWidget *parent)
    : QLCDNumber(parent)
{
    setSegmentStyle(Filled); // 设置显示器风格
    setDigitCount(12); // 设置所显示的位数

    QTimer *timer = new QTimer(this); // 产生一个定时器
    connect(timer, SIGNAL(timeout()),this,SLOT(showTime())); // 关联定时器的信号与槽
    timer->start(1); // 开始一个定时器，没1毫秒更新显示时间

    showTime(); // 调用时间显示函数

    setWindowTitle(tr("Digital Clock")); // 设置显示器窗口标题
    resize(800, 200); // 设置窗口大小
}

void DigitalClock::showTime()
{
    QTime time = QTime::currentTime(); // 获取当前时间
    QString text = time.toString("hh:mm:ss:zzz"); // 定义时间显示格式
    // 中间冒号按秒闪动
   if ((time.second() % 2) == 0) {
       text[2] = ' ';
       text[5] = ' ';
       text[8] = ' ';
   }
    display(text);
}
