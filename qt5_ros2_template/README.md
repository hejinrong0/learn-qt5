#  qt5 + ros2 开发一款人机交互HMI模板

# 功能：


## 目录结构
#### qtcreate 创建的目录
```
├── CMakeLists.txt
├── CMakeLists.txt.user
├── main.cpp
├── mainwindow.cpp
├── mainwindow.h
└── mainwindow.ui
```

#### ros2 创建的功能包
```
├── CMakeLists.txt
├── include
│   └── qt5_ros2_template
├── package.xml
└── src
```


#### 合并后的工作目录
```
.
├── CMakeLists.txt
├── include
│   ├── mainwindow.h
│   └── qt5_ros2_template
├── package.xml
├── README.md
├── src
│   └── mainwindow.cpp
└── ui
    └── mainwindow.ui
```

> 对合并后的工作目录做补充说明

```
├── CMakeLists.txt
├── CMakeLists.txt.user
├── include // 存放头文件 .hpp .h
│   ├── mainobject.h
│   ├── mainwindow.h
│   └── splashscreen.h
├── package.xml
├── README.md
├── resource // 存放系统中使用的资源文件
│   └── resource.qrc
├── src // 存放主逻辑代码文件
│   ├── main.cpp
│   ├── mainobject.cpp
│   ├── mainwindow.cpp
│   └── splashscreen.cpp
└── ui // 存放ui文件
    └── mainwindow.ui

```


# 环境准备
1. 使用qtcreate创建一个cmake项目
2. 使用ros2 创建一个功能包
> ros2 pkg create --build-type ament_cmake <package_name>
3. 将创建的功能包与创建的cmake项目合并，后期开发都在这个合并的功能包中；
启动qtcrete 的时候，需要在已经启动ros2环境下使用命令行启动，这样在cmake
过程中，可以将ament_cmae的包预加载进来，否则编译报错。
4. 启动ros2环境命令
> source /opt/ros/humble/setup.bash
5. 启动qt环境
>./Qt5.9.9/Tools/QtCreator/bin/qtcreator


# 开发记录


