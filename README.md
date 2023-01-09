# learn-qt5
qt5 is learned and qt5 instances are recorded



1. module_logs 日志模块
2. lqt_table 表格操作
3. lqt_image 图片操作
4. lqt_video 实时数据操作
5. lqt_ros2_topic ROS2话题 创建和监听
6. lqt_qt5_widget 一些qt基础控件


### 变更日志
【表格操作】
1. 新增、删除 行 
2. 新增、删除 列
3. 清空表格所有内容 clear Table
4. 清空表格内容（不删除标题行和列）clear Con
5. 填充数据


### 5. lqt_ros2_topic ROS2话题 创建和监听
#### 思路
5.1 qt_creator创建cmake项目 lqt_ros2_topic
5.2 创建ROS2功能包 ros2 pkg create --build-type ament_cmake lqt_ros2_topic
5.3 合并两个项目的CMakeLists.txt文件内容

#### 开发
1. 终端中source ROS2环境变量
2. 在启动ROS2环境变量清空下使用命令行启动qtcreator