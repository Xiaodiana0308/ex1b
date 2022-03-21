#include"./../inc/Client.h"

int client(struct input_client)
{
    int sockfd;//客户端socket
    if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1){
        perror("socket");
        return -1;
    }
    struct sockaddr_in servaddr;//服务端地址
    memset(&servaddr,0,sizeof(servaddr));
    struct hostent *h;//预留只知道IP的情况
    h=gethostbyname(input_client.ip_1);//直接获得服务端网络相关信息
    servaddr.sin_port=htons(input_client.port_1);//端口信息
    servaddr.sin_family=AF_INET;//协议族，规定好的
    memcpy(&servaddr.sin_addr,h->h_addr,h->h_length);//注意：servaddr.sin_addr与h->h_addr数据类型不一样，但可以互相转化。h->h_addr等价于h->h_addr_list[0]

}