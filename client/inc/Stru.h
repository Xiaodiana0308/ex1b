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
        
        // char filename[25];//要操作的文件名，包括目录
        char name[15];//输入用户名
        char password[15];//输入的密码
        int permit;//用户登录判定，仅在该字符为1情况下，才允许传输数据，通过返回的pack赋值[赋值作用]
        char send_filename[50];//文件名
        char send_filepath[450];//文件路径
        char send_full[500];//文件名+路径[下载、上传专用]
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


#endif