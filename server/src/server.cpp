#include"./../inc/Server.h"

int server(class get_server get_serv,struct name_password *npd)
{
    //创建服务端
    int listenfd;
    if((listenfd=socket(AF_INET,SOCK_STREAM,0))==-1){
        perror("socket");
        return -1;
    }

    //创建服务端网络地址
    struct sockaddr_in servaddr;
    memset(&servaddr,0,sizeof(servaddr));//开辟空间并初始化[类型指针，0，类型大小]
    servaddr.sin_family=AF_INET;//协议族
    servaddr.sin_port=htons(get_serv.port_1);//服务端端口
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);//服务端网络地址，任意

    //绑定端口
    if(bind(listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr))!=0){
        perror("bind");
        close(listenfd);
        return -1;
    }

    //设置为监听状态
    if(listen(listenfd,5)!=0){
        perror("listen");
        close(listenfd);
        return -1;
    }

    //接收客户端的连接
    int clientfd;//客户端的socket
    int socklen=sizeof(struct sockaddr_in);//存储struct sockaddr_in的大小，accept函数需要
    struct sockaddr_in clientaddr;//客户端网络地址,由accept确定。
    if((clientfd=accept(listenfd,(struct sockaddr *)&clientaddr,(socklen_t *)&socklen))==-1){
        perror("accept error!");
        close(listenfd);
        close(clientfd);
        return -1; 
    }
    std::cout<<"连接建立"<<std::endl;

    //数据交互
    class packet get_text;//接收数据包
    class packet send_text;//发送数据包
    int iret;//接收、发送总数据大小
    int iname=0;//注册次序
    int break_two;//跳出两个循环用
    while(get_text.beg!=3)//否则一直连接
    {
        //接收数据
        memset(&get_text,'\0',sizeof(get_text));
        memset(&send_text,'\0',sizeof(send_text));//清空两个数据包
        if((iret=recv(clientfd,&get_text,sizeof(get_text),0))<=0){
            printf("iret=%d\n",iret);
            perror("recv");
            close(listenfd);
            close(clientfd);
            return -1;
        }
        switch(get_text.beg){
            case 0:{//异常模式
                //异常返回包专用
                const char *wrong="Request_cannot_be_empty";//请求不能为空
                send_text.beg=10;
                memcpy(&send_text.text,wrong,strlen(wrong));
                break;
            }
            case 1:{//注册模式
                printf("收到注册请求\n");
                break_two=0;
                for(int i=0;i<20;i++){
                    if(strcmp((*npd).name[i],get_text.name)==0){
                        const char *wrong="Cannot_have_the_same_name_as_another_user";//不能与其他用户重名
                        send_text.beg=10;
                        memcpy(&send_text.text,wrong,strlen(wrong));
                        break_two=1;
                        break;
                    }
                }
                if(break_two==1){
                    break;
                }
                //注册成功
                memcpy(&(*npd).name[iname],get_text.name,sizeof(get_text.name));
                memcpy(&(*npd).password[iname],get_text.password,sizeof(get_text.password));
                send_text.beg=11;
                iname++;
                break;
            }
            case 2:{//登录模式
                printf("收到登录请求\n");
                break_two=0;
                for(int i=0;i<20;i++)
                {
                    if(strcmp((*npd).name[i],get_text.name)==0){
                        if(strcmp((*npd).password[i],get_text.password)==0){
                            send_text.lock=1;//认证成功
                            send_text.beg=12;
                            break_two=1;
                            break;
                        }
                        else break;
                    }
                }
                if(break_two==1){
                    break;
                }
                //认证失败
                const char *wrong="Wrong_user_name_or_password";//用户名或密码错误
                send_text.beg=10;
                memcpy(&send_text.text,wrong,strlen(wrong));
                break;
            }
            case 4:{//目录操作模式
                break;
            }
            case 5:{//下载模式
                break;
            }
            case 6:{//上传模式
                break;
            }
            case 25:{//继续下载文件
                break;
            }
            case 26:{//继续上传文件
                break;
            }
        }
        //发送数据
        if((iret=send(clientfd,&send_text,sizeof(struct packet),0))<=0){
            printf("iret=%d\n",iret);
            perror("send");
            close(listenfd);
            close(clientfd);
            return -1;
        }
    }
    
    std::cout<<"Receive data:"<<get_text.beg<<std::endl;

    
    //关闭socket
    close(listenfd);
    close(clientfd);
    return 0;
}