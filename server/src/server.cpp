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
    class get_client save_c;//登录成功后存储用户信息
    memset(&save_c,'\0',sizeof(save_c));
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
                memcpy(&save_c.name,get_text.name,sizeof(get_text.name));
                printf("注册用户名:%s\n",get_text.name);
                memcpy(&save_c,get_text.password,sizeof(get_text.password));
                if(list_mkdir(&save_c)!=0){//创建用户空间
                    const char *wrong="Create_path_failed";//创建文件失败
                    send_text.beg=10;
                    memcpy(&send_text.text,wrong,strlen(wrong));
                    break;
                }
                memset(&save_c,'\0',sizeof(save_c));//及时清空

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
                            //注入用户信息
                            memcpy(&save_c.name,get_text.name,sizeof(get_text.name));
                            memcpy(&save_c,get_text.password,sizeof(get_text.password));//整个连接过程中有效
                            printf("登录用户名:%s\n",get_text.name);
                            list_00(&save_c);//自动进入目录

                            memcpy(&send_text.text,save_c.filename,sizeof(save_c.filename));
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
            case 3:{//退出
                printf("收到注销请求\n");
                close(listenfd);
                close(clientfd);
                return 0;
                break;
            }
            case 4:{//目录操作模式
                switch (get_text.beg_list)
                {
                    case 1:{//获得目录下所有文件名
                        printf("收到查看目录文件请求\n");
                        struct filename fn;
                        memset(&fn,'\0',sizeof(fn));
                        list_01(&save_c,&fn);
                        char fn_c1[500]={0};
                        char fn_c2[500]={0};
                        if(fn.typen[0]!=0){//读取到了[注意采用第0个位置的文件类型判断]
                            int i=0;
                            while(fn.typen[i]!=0)
                            {
                                memset(&fn_c2,'\0',sizeof(fn_c2));//清空2
                                memcpy(&fn_c2,fn_c1,strlen(fn_c1));//存入2
                                memset(&fn_c1,'\0',sizeof(fn_c1));//清空1
                                sprintf(fn_c1,"%s%s %d ",fn_c2,fn.filen[i],fn.typen[i]);//给1接上：  文件名,文件类型,
                                i++;
                            }
                            memcpy(&send_text.text,fn_c1,sizeof(fn_c1));
                        }
                        send_text.beg=14;
                        send_text.beg_list=1;
                        break;
                    }
                    case 2:{//进入目录
                        int list_2;
                        if((list_2=list_02(&save_c,get_text.text))!=0){//无法进入
                            const char *wrong="Directory_does_not_exist";//目录不存在
                            send_text.beg=10;
                            memcpy(&send_text.text,wrong,strlen(wrong));
                            break;
                        }
                        send_text.beg=14;
                        send_text.beg_list=2;
                        break;
                    }
                    case 3:{//返回上一目录
                        int list_3;
                        if((list_3=list_03(&save_c))!=0){//无法进入
                            const char *wrong="Unable_to_access_unauthorized_space";//无法访问未授权的空间
                            send_text.beg=10;
                            memcpy(&send_text.text,wrong,strlen(wrong));
                            break;
                        }
                        send_text.beg=14;
                        send_text.beg_list=3;
                        break;
                    }
                    case 4:{//新建文件夹
                    int list_4;
                        if((list_4=list_04(&save_c,get_text.text))!=0){//无法进入
                            const char *wrong="Directory_does_not_exist";//目录不存在
                            send_text.beg=10;
                            memcpy(&send_text.text,wrong,strlen(wrong));
                            break;
                        }
                        send_text.beg=14;
                        send_text.beg_list=4;
                        break;
                        break;
                    }
                    case 5:{
                        break;
                    }
                }
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