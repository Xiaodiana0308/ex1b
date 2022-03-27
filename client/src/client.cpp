#include"./../inc/Client.h"

int client(class input_client in_clie)
{
    int sockfd;//客户端socket
    if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1){
        perror("socket");
        return -1;
    }
    struct sockaddr_in servaddr;//服务端地址结构体
    memset(&servaddr,0,sizeof(servaddr));
    struct hostent *h;//预留只知道域名的情况
    h=gethostbyname(in_clie.ip_1);//直接获得服务端网络相关信息
    servaddr.sin_port=htons(in_clie.port_1);//端口信息
    servaddr.sin_family=AF_INET;//协议族
    memcpy(&servaddr.sin_addr,h->h_addr,h->h_length);//地址

    //连接建立
    if(connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr))!=0){//connect[本机socket，对方网络地址(sockaddr *),地址大小]
        perror("connect");
        close(sockfd);
        return -1;
    }
    else printf("连接建立\n");

    struct packet text_out;//传输数据包
    struct packet text_get;//接收数据包
    int iret;//返回数据长度
    in_clie.beg=0;//报头置0
    text_get.beg=0;

    //数据交互
    while(in_clie.beg!=3)//不为3时不关闭连接
    {
        if(text_get.beg!=25){//确保不处于传输模式
            if(text_get.beg!=26){
                man0(&in_clie);//用户选择功能，修改beg值
            }
            else in_clie.beg=26;
        }
        else in_clie.beg=25;
        memset(&text_out,'\0',sizeof(struct packet));
        memset(&text_get,'\0',sizeof(struct packet));//初始化数据包
        text_out.lock=in_clie.permit;//将权限赋值给报头[数据包权限仅在此修改]
        //不同类型包的封装。
        switch(in_clie.beg){
            case 1:{//注册模式
                printf("01模式\n");
                man_01(&in_clie);//用户输入新账号密码

                text_out.beg=in_clie.beg;
                text_out.ack=0;
                text_out.seq=0;
                text_out.max=0;
                memcpy(&text_out.name,in_clie.name,sizeof(in_clie.name));
                memcpy(&text_out.password,in_clie.password,sizeof(in_clie.password));
                memset(&in_clie,'\0',sizeof(in_clie));//及时清空

                break;
            }
            case 2:{//登录模式
            if(in_clie.permit==1){
                printf("已经登录，请退出后重新登录\n");
                continue;
            }
                printf("02模式\n");
                man_02(&in_clie);//用户登录

                text_out.beg=in_clie.beg;
                text_out.ack=0;
                text_out.seq=0;
                text_out.max=0;
                memcpy(&text_out.name,in_clie.name,sizeof(in_clie.name));
                memcpy(&text_out.password,in_clie.password,sizeof(in_clie.password));
                break;
            }
            case 4:{//目录操作模式
                if(in_clie.permit!=1){
                    printf("请登录\n");
                    continue;//跳到下一轮
                }
                printf("04模式\n");
                man_03(&in_clie);

                if((in_clie.beg_list!=1)&&(in_clie.beg_list!=3)){//既不是获得目录，也不是返回上一级目录
                    man_030(&text_out);
                }
                text_out.beg=in_clie.beg;
                text_out.ack=0;
                text_out.seq=0;
                text_out.max=0;
                text_out.beg_list=in_clie.beg_list;
                break;

            }
            case 5:{//下载模式
                if(in_clie.permit!=1){
                    printf("请登录\n");
                    continue;//跳到下一轮
                }
                break;
            }
            case 6:{//上传模式
                if(in_clie.permit!=1){
                    printf("请登录\n");
                    continue;//跳到下一轮
                }
                FILE *fp;//文件指针
                man_06(&in_clie);//读取文件名和全路径
                if((fp=fopen(in_clie.send_filepath,"r"))==NULL){
                    printf("无法找到文件\n");
                    break;//跳出循环
                }
                //成功打开文件
                fseek(fp,0,SEEK_END);//定位到文件末尾

                //第一个发送包封装
                text_out.beg=in_clie.beg;
                text_out.ack=0;
                text_out.seq=0;
                text_out.max=ftell(fp);//函数用于返回文件大小
                memcpy(&text_out.text,in_clie.send_filename,strlen(in_clie.send_filename));
                fseek(fp, 0, SEEK_SET);//文件指针指向文件头部

                if((iret=send(sockfd,&text_out,sizeof(struct packet),0))<=0){//首次发送
                    printf("iret=%d\n",iret);
                    perror("send");
                    close(sockfd);
                    return -1;
                }
                while(1)//接收-发送循环
                {
                    memset(&text_out,'\0',sizeof(struct packet));
                    memset(&text_get,'\0',sizeof(struct packet));//初始化数据包
                    if((iret=recv(sockfd,&text_get,sizeof(text_get),0))<=0){//接收返回确认
                        printf("iret=%d\n",iret);
                        perror("recv");
                        close(sockfd);
                        return -1;
                    }
                    //接收包解析
                    printf("%s\n",text_get.text);
                    if(text_get.beg==26){
                        fseek(fp,text_get.ack+1,SEEK_SET);//定位文件指针，从确认位置+1开始
                        //确保每次读取范围
                        int i=0;
                        int c;//临时存储字符串
                        c=getc(fp);//先读一次
                        while((!feof(fp))&&(i<998))
                        {
                            text_out.text[i]=c;//存入发送包
                            c=getc(fp);//读取文件字符并后移文件指针
                            i++;
                        }
                        // int i=0;
                        // while((!feof(fp))&&(i<1000))
                        // {
                        //     text_out.text[i]=getc(fp);//存入发送包,读取文件字符并后移文件指针
                        //     i++;
                        // }
                        if(feof(fp)){//上传完成
                            fclose(fp);
                            text_out.text[i]='\0';
                            text_out.text[i+1]='\0';
                            text_out.beg=16;//完成报头
                            text_out.seq=strlen(text_out.text);
                            text_out.ack=0;
                            text_out.max=0;
                            break;//最后一次发送交由统一发送方发送
                        }
                        else {//上传继续
                            text_out.text[i]=c;
                            text_out.text[i+1]='\0';
                            text_out.beg=26;//继续报头
                            text_out.seq=strlen(text_out.text);
                            text_out.ack=0;
                            text_out.max=0;
                            //发送
                            if((iret=send(sockfd,&text_out,sizeof(struct packet),0))<=0){
                                printf("iret=%d\n",iret);
                                perror("send");
                                close(sockfd);
                                return -1;
                            }
                        }
                    }
                    else {//正常情况下不会收到其他请求的报文
                        printf("数据 发送异常，中断\n");
                        break;
                    }   
                }
                break;
            }
            case 3:{
                printf("03模式\n");//关闭连接
                text_out.beg=in_clie.beg;
                if((iret=send(sockfd,&text_out,sizeof(struct packet),0))<=0){
                    printf("iret=%d\n",iret);
                    perror("send");
                    close(sockfd);
                    return -1;
                }
                close(sockfd);
                return 0;
                break;
            }
            default:{
                printf("请重新输入指令\n");
                break;
            }
        }
        //数据包发送
        if((iret=send(sockfd,&text_out,sizeof(struct packet),0))<=0){
            printf("iret=%d\n",iret);
            perror("send");
            close(sockfd);
            return -1;
        }
        //数据包接收
        if((iret=recv(sockfd,&text_get,sizeof(text_get),0))<=0){
            printf("iret=%d\n",iret);
            perror("recv");
            close(sockfd);
            return -1;
        }
        switch (text_get.beg)
        {
            case 10:{//异常模式响应
                printf("异常或关闭，原因：");
                printf("%s\n",text_get.text,50);
                break;
            }
            case 11:{//注册成功响应
                printf("注册成功，请重新登录\n");
                break;
            }
            case 12:{//登录成功响应
                printf("登录成功\n");
                printf("当前所在目录：%s\n",text_get.text);
                in_clie.permit=1;//权限仅在此赋予
                break;
            }
            case 14:{//远程目录成功响应
                switch (text_get.beg_list)
                {
                    case 1:{//成功获得目录
                        if(strlen(text_get.text)!=0){
                            char *ft;//文件名or类型
                            char *filen;
                            int typen;
                            ft=strtok(text_get.text," ");
                            int i=0;
                            while(ft)
                            {
                                filen=ft;
                                ft=strtok(NULL," ");
                                typen=atoi(ft);
                                printf("文件名：%s，文件类型：%d\n",filen,typen);
                                ft=strtok(NULL," ");
                                i++;
                            }
                        }
                        else printf("当前目录为空\n");
                        break;
                    }
                    case 2:{//成功进入目录
                        printf("成功进入目录\n");
                        break;
                    }
                    case 3:{//成功返回上一目录
                        printf("成功返回上一目录\n");
                        break;
                    }
                    case 4:{//成功新建文件夹
                        printf("成功新建文件夹\n");
                        break;
                    }
                    case 5:{//成功删除文件夹
                        printf("成功删除文件夹\n");
                        break;
                    }
                }
            }
            case 15:{//下载文件完毕响应
                printf("成功发送文件\n");
                break;
            }
            case 16:{//上传文件完毕响应
                break;
            }
            default:{
                printf("请重新输入指令\n");
                break;
            }
        }

    }
    close(sockfd);
    return 0; 
}