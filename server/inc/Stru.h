#ifndef Stru
#define Stru

#include <iostream>
#include <string>

class get_server{
    public:
        char ip_1[20];//服务端ip地址，不使用
        int port_1;//服务端端口
};

class get_client{//存储客户端通信类
    public:
        // short beg;//请求类型报头
        char filename[500];//当前所在目录,目录大小统一为500
        char name[15];//用户名
        char password[15];//用户密码
};

struct packet{//TCP数据包 报头+内容
    short beg;//请求类型报头,2字节
    short beg_list;//目录操作符，2字节  [目录操作模式启用]
    unsigned int ack;//确认接收数量，累计，4字节  [接收文件方，发送返回包时启用]
    unsigned int seq;//发送数量，累计，4字节  [发送文件方，发送文件包时启用]
    unsigned int max;//数据总量，4字节  [文件传输模式、第一次传输启用]
    char lock;//仅在该字符为1情况下，才允许传输数据，1字节 [登录模式启用]
    char name[15];//用户名，15字节    [登录、注册模式启用]
    char password[15];//密码，15字节  [登录、注册模式启用]
    char text[1000];//发送数据内容
};

struct name_password{//用户信息结构体,20个上限
    char name[20][15];
    char password[20][15];
};

struct filename{//某目录下文件名结构体
    char filen[50][20];//名称
    int typen[50];//类型
};

#endif