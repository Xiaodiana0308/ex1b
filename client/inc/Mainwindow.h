#ifndef Mainwindow
#define Mainwindow

#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QProgressBar>

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <assert.h>
#include <fstream>
#include"Stru.h"
#include"Secure.h"


class mainwindow : public QMainWindow
{
    Q_OBJECT
    public:
        explicit mainwindow(QWidget *parent = 0);
        //文本框
        QLabel *QLa0;//标题
        QLabel *QLa1;//IP
        QLabel *QLa2;//端口
        QLabel *QLa3;//用户名
        QLabel *QLa4;//密码
        QLabel *QLa5;//输出框
        //输入框
        QLineEdit *QLin1;//IP输入
        QLineEdit *QLin2;//端口输入
        QLineEdit *QLin3;//账号
        QLineEdit *QLin4;//密码
        QLineEdit *QLin5;//路径输入
        QLineEdit *QLin6;//文件名输入
        //按钮
        QPushButton *QPu0;//注册按钮1
        QPushButton *QPu1;//登录按钮2
        QPushButton *QPu2;//注销按钮3
        QPushButton *QPu3;//查看当前目录按钮4
        QPushButton *QPu4;//进入目录按钮5
        QPushButton *QPu5;//返回上一级目录按钮6
        QPushButton *QPu6;//新建文件夹按钮7
        QPushButton *QPu7;//删除文件夹按钮8
        QPushButton *QPu8;//下载文件按钮9
        QPushButton *QPu9;//上传文件按钮10
        //进度条
        QProgressBar *Qprog;//上传下载进度条
        //通信相关
        class input_client in_clie1;//客户端客户对象
        int sockfd;//客户端socket
        struct sockaddr_in servaddr;//服务端地址结构体
        struct hostent *h;//预留只知道域名的情况

        struct packet text_out;//传输数据包
        struct packet text_get;//接收数据包
        int user_if;//登录成功判断

        //通信函数
        void client();//共用传输模块

    signals:

public slots:
    void QPu0_slots();//连接注册
    void QPu1_slots();//登录
    void QPu2_slots();//注销
    void QPu3_slots();//查看当前目录
    void QPu4_slots();//进入目录
    void QPu5_slots();//返回上一级目录
    void QPu6_slots();//新建文件夹
    void QPu7_slots();//删除文件夹
    void QPu8_slots();//下载文件
    void QPu9_slots();//上传文件

private:

};

#endif