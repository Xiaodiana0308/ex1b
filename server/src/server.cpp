#include"./../inc/Server.h"

int server(class get_server get_serv,struct name_password *npd,int iname)
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
                            memcpy(&save_c.name,get_text.name,strlen(get_text.name));
                            memcpy(&save_c.password,get_text.password,strlen(get_text.password));//整个连接过程中有效
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
                send_text.beg=3;
                if((iret=send(clientfd,&send_text,sizeof(struct packet),0))<=0){
                    printf("iret=%d\n",iret);
                    perror("send");
                    close(listenfd);
                    close(clientfd);
                    return -1;
                }
                close(listenfd);
                close(clientfd);
                return iname;//直接关闭连接
            }
            case 30:{//删除
                printf("收到删除请求\n");
                list_dele(&save_c);
                memset(&save_c,'\0',sizeof(save_c));//及时清空
                iname=iname;//仍然为空
                send_text.beg=30;
                break;
            }
            case 4:{//目录操作模式
                printf("当前路径=%s\n",save_c.filename);
                // printf("name=%s\n",save_c.name);
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
                                sprintf(fn_c1,"%s%s<%d>  ",fn_c2,fn.filen[i],fn.typen[i]);//给1接上：  文件名<文件类型>,
                                i++;
                            }
                            memcpy(&send_text.text,fn_c1,sizeof(fn_c1));
                            // printf("%s\n",send_text.text);
                        }
                        send_text.beg=14;
                        send_text.beg_list=1;
                        break;
                    }
                    case 2:{//进入目录
                        printf("收到进入目录请求\n");
                        int list_2;
                        if((list_2=list_02(&save_c,get_text.text))!=0){//无法进入
                            const char *wrong="Directory_does_not_exist";//目录不存在
                            send_text.beg=10;
                            memcpy(&send_text.text,wrong,strlen(wrong));
                            break;
                        }
                        send_text.beg=14;
                        send_text.beg_list=2;
                        memcpy(&send_text.text,save_c.filename,sizeof(save_c.filename));
                        break;
                    }
                    case 3:{//返回上一目录
                        printf("收到返回上一目录请求\n");
                        int list_3;
                        if((list_3=list_03(&save_c))!=0){//无法进入
                            const char *wrong="Unable_to_access_unauthorized_space";//无法访问未授权的空间
                            send_text.beg=10;
                            memcpy(&send_text.text,wrong,strlen(wrong));
                            break;
                        }
                        send_text.beg=14;
                        send_text.beg_list=3;
                        memcpy(&send_text.text,save_c.filename,sizeof(save_c.filename));
                        break;
                    }
                    case 4:{//新建文件夹
                        printf("收到新建文件夹请求\n");
                        int list_4;
                        if((list_4=list_04(&save_c,get_text.text))!=0){//目录已经存在
                            const char *wrong="Directory_already_exists";//目录已经存在
                            send_text.beg=10;
                            memcpy(&send_text.text,wrong,strlen(wrong));
                            break;
                        }
                        send_text.beg=14;
                        send_text.beg_list=4;
                        memcpy(&send_text.text,save_c.filename,sizeof(save_c.filename));
                        break;
                    }
                    case 5:{//删除文件夹或目录
                        printf("收到删除文件夹或目录请求\n");
                        int list_5;
                        if((list_5=list_05(&save_c,get_text.text))!=0){//要删除的目录不存在
                            const char *wrong="The_directory_to_delete_does_not_exist";//目录已经存在
                            send_text.beg=10;
                            memcpy(&send_text.text,wrong,strlen(wrong));
                            break;
                        }
                        send_text.beg=14;
                        send_text.beg_list=5;
                        memcpy(&send_text.text,save_c.filename,sizeof(save_c.filename));
                        break;
                    }
                }
                break;
            }
            case 5:{//客户端下载模式
                printf("客户端下载模式:\n");
                char name_l[50]={0};//临时存储文件名
                memcpy(&name_l,get_text.text,strlen(get_text.text));//文件名必然不大
                char filepath[700]={0};
                sprintf(filepath,"%s/aes256_%s",save_c.filename,name_l);//建立完整路径
                secure_enc(save_c,name_l);
                ifstream readfile;//读文件指针
                readfile.open(filepath,ios::binary | ios::in);//二进制形式打开
                if(!readfile.is_open()){
                    const char *wrong="The_file_cannot_be_downloaded:file_does_not_exist";//无法下载该文件:文件不存在
                    send_text.beg=10;
                    memcpy(&send_text.text,wrong,strlen(wrong));
                    break;//跳出
                }
                //成功打开文件
                readfile.seekg(0,ios::end);//定位到文件末尾
                //第一个发送包封装
                send_text.beg=25;
                send_text.ack=0;
                send_text.seq=0;
                send_text.max=readfile.tellg();//函数用于返回文件大小

                readfile.seekg(0,ios::beg);//定位到文件开头
                //首次发送（包含大小信息）
                if((iret=send(clientfd,&send_text,sizeof(struct packet),0))<=0){
                    printf("iret=%d\n",iret);
                    perror("send");
                    close(listenfd);
                    close(clientfd);
                    return -1;
                }
                while(1)//接收-发送循环
                {
                    memset(&send_text,'\0',sizeof(send_text));
                    memset(&get_text,'\0',sizeof(get_text));//初始化数据包
                    //接收返回确认
                    if((iret=recv(clientfd,&get_text,sizeof(get_text),0))<=0){
                        printf("iret=%d\n",iret);
                        perror("recv");
                        close(listenfd);
                        close(clientfd);
                        return -1;
                    }
                    //接收包解析
                    if(get_text.beg==25){
                        readfile.seekg(get_text.ack,ios::beg);//定位文件指针，从确认位置开始
                        int i=0;
                        while((!readfile.eof())&&(i<1000))
                        {
                            readfile.read(&send_text.text[i],sizeof(char));//每次只读一个
                            i++;
                        }
                        if(readfile.eof()){//最后一次，上传完成
                            readfile.close();
                            send_text.text[i-1]='\0';//由于eof会多判断一位，因此需要将上一位置0
                            send_text.beg=15;//完成报头
                            send_text.seq=i;
                            send_text.ack=0;
                            send_text.max=0;
                            secure_del(save_c,name_l);
                        }
                        else {//上传继续
                            send_text.beg=25;//继续报头
                            send_text.seq=sizeof(send_text.text);
                            send_text.ack=0;
                            send_text.max=0;
                        }
                        //发送
                        if((iret=send(clientfd,&send_text,sizeof(struct packet),0))<=0){
                            printf("iret=%d\n",iret);
                            perror("send");
                            close(listenfd);
                            close(clientfd);
                            return -1;
                        }
                    }
                    else if(get_text.beg==15){//对方返回确认
                        memset(&send_text,'\0',sizeof(send_text));
                        send_text.beg=15;
                        break;
                    }
                }
                break;
            }
            case 6:{//客户端上传模式
                printf("客户端上传模式:\n");
                char filepath[500]={0};
                char name_l[50]={0};//临时存储文件名
                memcpy(&name_l,get_text.text,sizeof(get_text.text));
                int ack=0;//确认接收数据包用
                int max=get_text.max;//写入文件大小
                sprintf(filepath,"%s/aes256_%s",save_c.filename,get_text.text);//建立完整路径
                printf("文件大小=%d字节，文件名=%s\n",get_text.max,get_text.text);
                
                ofstream writefile;
                writefile.open(filepath,ios::binary);
                if(!writefile.is_open()){
                    const char *wrong="The_file_cannot_be_uploaded";//无法上传该文件
                    send_text.beg=10;
                    memcpy(&send_text.text,wrong,strlen(wrong));
                    break;//跳出
                }
                writefile.seekp(0,ios::beg);//定位到文件开头
                const char *inform0="File_upload_start";//文件传输开始
                //发送包封装
                send_text.beg=26;
                send_text.ack=get_text.seq;
                send_text.seq=0;
                send_text.max=0;
                memcpy(&send_text.text,inform0,strlen(inform0));
                while(1)//发送-接收循环
                {
                    //发送数据包
                    if((iret=send(clientfd,&send_text,sizeof(struct packet),0))<=0){
                        printf("iret=%d\n",iret);
                        perror("send");
                        close(listenfd);
                        close(clientfd);
                        writefile.close();
                        return -1;
                    }
                    memset(&send_text,'\0',sizeof(send_text));
                    memset(&get_text,'\0',sizeof(get_text));
                    //接收数据包
                    if((iret=recv(clientfd,&get_text,sizeof(get_text),0))<=0){
                        printf("iret=%d\n",iret);
                        perror("recv");
                        close(listenfd);
                        close(clientfd);
                        writefile.close();
                        return -1;
                    }
                    //写入文件
                    int i=0;
                    writefile.seekp(ack,ios::beg);//文件指针定位，上一个ack
                    while(i<get_text.seq)
                    {
                        writefile.write(&get_text.text[i],sizeof(char));;
                        i++;
                    }
                    const char *inform="Percentage_of_files_transferred:";//返回文件存储进度信息
                    float fini=((float)ack/(float)max)*100;
                    ack=ack+get_text.seq;
                    // printf("接收数据大小=%d\n,累计=%d",get_text.seq,ack);
                    //发送包打包
                    sprintf(send_text.text,"%s %f %%",inform,fini);
                    send_text.ack=ack;
                    send_text.seq=0;
                    send_text.max=0;
                    if(get_text.beg==16){
                        printf("上传文件完成\n");
                        send_text.beg=16;
                        writefile.close();
                        secure_dec(save_c,name_l);
                        break;//最后一次传输回复交由统一发送
                    }
                    else send_text.beg=26;
                }
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
    //关闭socket
    close(listenfd);
    close(clientfd);
    return iname;
}