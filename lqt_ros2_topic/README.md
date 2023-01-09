### 创建一个ROS2话题


## 项目目录
├── CMakeLists.txt
├── include     // 存放头文件
│   ├── mainwindow.h
│   └── rclcomm.h
├── package.xml
├── README.md
├── resource // 存放资源文件
├── src // 存放cpp文件
│   ├── main.cpp
│   ├── mainwindow.cpp
│   └── rclcomm.cpp
└── ui // 存放ui文件
    └── mainwindow.ui


#### 公共类
创建rclcomm公共类，引入QTthread、rclcpp 类

#### 发布一个话题
    commNode = new rclcomm(); // 指针初始化
    commNode->start(); // 自动调用类中的run()函数 void rclcomm::run()

#### 订阅一个话题


#### 操作步骤
1. ros2创建一个功能包
2. qt Creator创建一个cmake项目
3. 将ros2功能包meger（合并）到第2步操作cmake项目中
4. 新建一个rclcomm类，新建类成功后需要执行cmake（该cmake需要在终端中手动执行cmake ..
在qtCreator中执行会导致一直循环）。cmake之后结束后，在qtCreator编辑器中会显示rclcomm相关文件。


### 参考文献
[话题](https://book.guyuehome.com/ROS2/2.%E6%A0%B8%E5%BF%83%E6%A6%82%E5%BF%B5/2.4_%E8%AF%9D%E9%A2%98/）
