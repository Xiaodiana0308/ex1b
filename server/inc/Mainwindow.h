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
#include"./inc/Server.h"
#include"./inc/Stru.h"


class mainwindow : public QMainWindow
{
    Q_OBJECT
    public:
        explicit mainwindow(QWidget *parent = 0);
        //文本框
        QLabel *QLa0;//标题
        //输入框
        QLineEdit *QLin1;//端口号
        
        //按钮
        QPushButton *QPu0;//启动按钮
        QPushButton *QPu1;//关闭按钮
        //通信相关
        class get_server get_serv;
        struct name_password npd;
        int iname=0;//注册次序,不会重置

    signals:

public slots:
    void QPu0_slots();//启动
private:

};

#endif