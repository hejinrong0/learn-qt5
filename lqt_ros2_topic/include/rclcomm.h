#ifndef RCLCOMM_H
#define RCLCOMM_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <rclcpp/rclcpp.hpp> // ROS2的客户端接口
#include "std_msgs/msg/int32.hpp"

// 继承QThread, QTread 必须包含run函数
class rclcomm:public QThread
{
    Q_OBJECT
public:
    rclcomm();
    void run() override;
    // 申明一个消息处理回调函数
    void recv_callback(std_msgs::msg::Int32::SharedPtr msg);

// protected:
//     void run();
private:
    // 这里采用ROS1的方式创建节点，需要学习ROS2创建节点的方式
    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr _publisher; // 接收类型 <std_msgs::msg::Int32>
    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr _subscription;
    std::shared_ptr<rclcpp::Node> node; // 创建一个节点

signals:
    void emitTopicData(QString); //
};


#endif // RCLCOMM_H
