#ifndef Stru
#define Stru

#include <iostream>
#include <string>

struct input_client{//客户端调用通信类
    char *ip_1;//目标服务端ip地址
    int port_1;//服务端端口
    short beg;//请求类型报头
    char *filename;//要操作的文件名，包括目录
};

struct headline{//TCP数据包报头
    short beg;//请求类型报头
    short ack;//确认接收数量，累计，4字节（客户端），服务端则在15模式下发送文件大小。
    short seq;//发送数量，累计，4字节
};


#endif