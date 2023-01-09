#include "rclcomm.h"

rclcomm::rclcomm()
{
    // 初始化节点
    int argc = 0;
    char **argv = NULL; // 问题：** 两个星号的作用是什么？
    rclcpp::init(argc, argv);
    // node 进行初始化赋值，并指定节点名称
    node = rclcpp::Node::make_shared("lqt_ros2_topic");
    // 堆栈大小 10
    _publisher = node->create_publisher<std_msgs::msg::Int32>("lqt_ros2_topic_publisher", 10);
    // 消息订阅者初始化                                                订阅者名称                    堆栈大小  绑定回调函数，一个占位符
    _subscription = node->create_subscription<std_msgs::msg::Int32>("lqt_ros2_topic_publisher", 10,std::bind(&rclcomm::recv_callback,this,std::placeholders::_1));
}

// 实现run函数
void rclcomm::run() 
{
    qDebug("rclcomm::run()");
    std_msgs::msg::Int32 pub_msg;
    pub_msg.data = 0;
    // 1赫兹的频率发布
    rclcpp::WallRate loop_rate(1);
    // 通过rclcpp::ok()函数确定通信是否正常
    while (rclcpp::ok()) {
        // 发布话题
        pub_msg.data++;
        _publisher->publish(pub_msg);
        rclcpp::spin_some(node);
        loop_rate.sleep();
    }
    rclcpp::shutdown();
}

void rclcomm::recv_callback(const std_msgs::msg::Int32::SharedPtr msg)
{
    qDebug("rclcom::recv_callback");
    qDebug()<<msg->data;
    // 将数据发送给信号
    emit emitTopicData(QString::fromStdString(std::to_string(msg->data)));
}
