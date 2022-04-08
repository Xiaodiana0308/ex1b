project(MYSWAP)
#项目名
cmake_minimum_required(VERSION 3.16)
#cmake最低版本
set(CMAKE_CXX_STANDARD 14)
#c++最低协议
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
#连接多种版本的qt源文件
SET(CMAKE_AUTOMOC ON) 
#打开ui文件自动编译(moc主要用途 是将有QTOBJECT等宏的文件 展开生成编译器能识别的cpp文件 名称为moc_xxx.cpp，moc 主要是自动调用了qt库目录bin 下的moc工具命令)
SET(CMAKE_AUTOUIC ON) 
#有窗口设计文件XXX.ui，需要先进行uic编译生成一个ui_xxx.h的文件
SET(CMAKE_AUTORCC ON) 
#rcc 主要是用来将.qrc资源文件编译成 xx.cpp 提供资源符号等
SET(CMAKE_INCLUDE_CURRENT_DIR ON)
#该开关主要是设置前面几个自动生成的文件路径可识别 

# if(ANDROID)
#  add_library(Test SHARED
#   main.cpp
#   mainwindow.cpp
#   mainwindow.h
#   mainwindow.ui
#  )
# else()
#  add_executable(Test
#   main.cpp
#   mainwindow.cpp
#   mainwindow.h
#   mainwindow.ui
#  )
# endif()

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB headers ${PROJECT_SOURCE_DIR}/inc/*.h)

add_executable(main main.cpp ${sources} ${headers})

target_link_libraries(main PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

target_include_directories(main PRIVATE "${CMAKE_BINARY_DIR}/Test_autogen/include_Debug")