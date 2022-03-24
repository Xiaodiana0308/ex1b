#ifndef Stru
#define Stru

#include <iostream>
#include <string>

class input_client{//客户端调用通信类
    public:
        char ip_1[20];//目标服务端ip地址
        int port_1;//服务端端口
        short beg;//请求类型[赋值作用]
        short beg_list;//目录操作符
        
        char filename[25];//要操作的文件名，包括目录
        char name[15];//输入用户名
        char password[15];//输入的密码
        int permit;//用户登录判定，仅在该字符为1情况下，才允许传输数据，通过返回的pack赋值[赋值作用]
};

struct packet{//TCP数据包 报头+内容
    short beg;//请求类型报头,4字节
    short ack;//确认接收数量，累计，4字节
    short seq;//发送数量，累计，4字节
    short max;//数据总量，4字节
    short beg_list;//目录操作符，4字节
    char lock;//仅在该字符为1情况下，才允许传输数据，1字节
    char name[15];//用户名，15字节
    char password[15];//密码，15字节
    char text[1000];//发送数据内容
};


#endif