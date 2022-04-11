#include"./../inc/Mainwindow.h"

mainwindow::mainwindow(QWidget *parent) :QMainWindow(parent)
{
    //窗口设置
    this->resize(1200,700);
    this->setWindowTitle("安全文件传输客户端v.1.0");
    //申请空间
    this->QLa0=new QLabel(this);
    this->QLa1=new QLabel(this);
    this->QLa2=new QLabel(this);
    this->QLa3=new QLabel(this);
    this->QLa4=new QLabel(this);
    this->QLa5=new QLabel(this);

    this->QLin1=new QLineEdit(this);
    this->QLin2=new QLineEdit(this);
    this->QLin3=new QLineEdit(this);
    this->QLin4=new QLineEdit(this);
    this->QLin5=new QLineEdit(this);
    this->QLin6=new QLineEdit(this);

    this->QPu0=new QPushButton(this);
    this->QPu1=new QPushButton(this);
    this->QPu2=new QPushButton(this);
    this->QPu3=new QPushButton(this);
    this->QPu4=new QPushButton(this);
    this->QPu5=new QPushButton(this);
    this->QPu6=new QPushButton(this);
    this->QPu7=new QPushButton(this);
    this->QPu8=new QPushButton(this);
    this->QPu9=new QPushButton(this);

    //外部访问名
    this->QLa0->setObjectName(QStringLiteral("Qtitle"));
    this->QLa1->setObjectName(QStringLiteral("Qip"));
    this->QLa2->setObjectName(QStringLiteral("Qport"));
    this->QLa3->setObjectName(QStringLiteral("Qusrname"));
    this->QLa4->setObjectName(QStringLiteral("Qpassword"));
    this->QLa5->setObjectName(QStringLiteral("text_out"));

    this->QLin1->setObjectName(QStringLiteral("Qip_in"));
    this->QLin2->setObjectName(QStringLiteral("Qport_in"));
    this->QLin3->setObjectName(QStringLiteral("Qusrname_in"));
    this->QLin4->setObjectName(QStringLiteral("Qpassword_in"));
    this->QLin5->setObjectName(QStringLiteral("text_in"));
    this->QLin6->setObjectName(QStringLiteral("text_in_file"));

    this->QPu0->setObjectName(QStringLiteral("but0"));
    this->QPu1->setObjectName(QStringLiteral("but1"));
    this->QPu2->setObjectName(QStringLiteral("but2"));
    this->QPu3->setObjectName(QStringLiteral("but3"));
    this->QPu4->setObjectName(QStringLiteral("but4"));
    this->QPu5->setObjectName(QStringLiteral("but5"));
    this->QPu6->setObjectName(QStringLiteral("but6"));
    this->QPu7->setObjectName(QStringLiteral("but7"));
    this->QPu8->setObjectName(QStringLiteral("but8"));
    this->QPu9->setObjectName(QStringLiteral("but9"));

    //显示内容设置
    this->QLa0->setText("安全文件传输客户端");
    QFont font;
    font.setPointSize(24);
    this->QLa0->setFont(font);
    this->QLa1->setText("IP地址");
    this->QLa2->setText("端口号");
    this->QLa3->setText("用户名");
    this->QLa4->setText("密码");
    this->QLa5->setText("输出框...");

    this->QPu0->setText("注册");
    this->QPu1->setText("登录");
    this->QPu2->setText("注销");
    this->QPu3->setText("查看当前目录");
    this->QPu4->setText("进入目录");
    this->QPu5->setText("返回上一级目录");
    this->QPu6->setText("新建文件夹");
    this->QPu7->setText("删除文件夹");
    this->QPu8->setText("下载文件");
    this->QPu9->setText("上传文件");

    this->QLin4->setEchoMode(QLineEdit::PasswordEchoOnEdit);//设置密码不显示
    this->QLa5->setWordWrap(true);//设置输出自动换行
    //设置输入框提示词
    this->QLin1->setPlaceholderText("___.___.___.___");
    this->QLin2->setPlaceholderText("_ _ _ _");
    this->QLin3->setPlaceholderText("usename");
    this->QLin4->setPlaceholderText("password");
    this->QLin5->setPlaceholderText("...");
    this->QLin6->setPlaceholderText("上传/下载 文件名");
    //设置一键清除
    this->QLin1->setClearButtonEnabled(true);
    this->QLin2->setClearButtonEnabled(true);
    this->QLin3->setClearButtonEnabled(true);
    this->QLin4->setClearButtonEnabled(true);
    this->QLin5->setClearButtonEnabled(true);
    this->QLin6->setClearButtonEnabled(true);
    //设置初始不可用按钮
    this->QPu3->setEnabled(false);
    this->QPu4->setEnabled(false);
    this->QPu5->setEnabled(false);
    this->QPu6->setEnabled(false);
    this->QPu7->setEnabled(false);
    this->QPu8->setEnabled(false);
    this->QPu9->setEnabled(false);

    //位置
    this->QLa0->setGeometry(QRect(400,50,400,50));
    this->QLa1->setGeometry(QRect(100,100,90,40));
    this->QLa2->setGeometry(QRect(100,150,90,40));
    this->QLa3->setGeometry(QRect(400,100,90,40));
    this->QLa4->setGeometry(QRect(400,150,90,40));
    this->QLa5->setGeometry(QRect(100,200,700,100));

    this->QLin1->setGeometry(QRect(160,110,150,40));
    this->QLin2->setGeometry(QRect(160,160,150,40));
    this->QLin3->setGeometry(QRect(450,110,150,40));
    this->QLin4->setGeometry(QRect(450,160,150,40));
    this->QLin5->setGeometry(QRect(100,350,300,50));
    this->QLin6->setGeometry(QRect(500,350,150,50));

    this->QPu0->setGeometry(QRect(250,600,100,50));
    this->QPu1->setGeometry(QRect(500,600,100,50));
    this->QPu2->setGeometry(QRect(750,600,100,50));
    this->QPu3->setGeometry(QRect(900,100,250,40));
    this->QPu4->setGeometry(QRect(900,150,250,40));
    this->QPu5->setGeometry(QRect(900,200,250,40));
    this->QPu6->setGeometry(QRect(900,250,250,40));
    this->QPu7->setGeometry(QRect(900,300,250,40));
    this->QPu8->setGeometry(QRect(900,350,250,40));
    this->QPu9->setGeometry(QRect(900,400,250,40));
    //信号绑定
    QObject::connect(this->QPu0,&QPushButton::clicked,this,&mainwindow::QPu0_slots);
    QObject::connect(this->QPu1,&QPushButton::clicked,this,&mainwindow::QPu1_slots);
    QObject::connect(this->QPu2,&QPushButton::clicked,this,&mainwindow::QPu2_slots);
    QObject::connect(this->QPu3,&QPushButton::clicked,this,&mainwindow::QPu3_slots);
    QObject::connect(this->QPu4,&QPushButton::clicked,this,&mainwindow::QPu4_slots);
    QObject::connect(this->QPu5,&QPushButton::clicked,this,&mainwindow::QPu5_slots);
    QObject::connect(this->QPu6,&QPushButton::clicked,this,&mainwindow::QPu6_slots);
    QObject::connect(this->QPu7,&QPushButton::clicked,this,&mainwindow::QPu7_slots);
    QObject::connect(this->QPu8,&QPushButton::clicked,this,&mainwindow::QPu8_slots);
    QObject::connect(this->QPu9,&QPushButton::clicked,this,&mainwindow::QPu9_slots);

}

void mainwindow::QPu0_slots()//连接并注册信号
{
    user_if=0;
    QByteArray ba;//转化QString对象
    memset(&(this->in_clie1),'\0',sizeof(this->in_clie1));
    in_clie1.permit=0;//初始化访问权限
    QString Qip,Qport,Qnam,Qpaw;//存储ip，端口号，用户名，密码
    Qip=this->QLin1->text();
    Qport=this->QLin2->text();
    Qnam=this->QLin3->text();
    Qpaw=this->QLin4->text();
    char *p=NULL;//引导QString指针
    //ip:Q-char
    ba= Qip.toLatin1();
    p=ba.data();
    memcpy(&(this->in_clie1).ip_1,p,strlen(p));
    //port:Q-int
    this->in_clie1.port_1=Qport.toInt();
    //name:Q-char
    ba= Qnam.toLatin1();
    p=ba.data();
    memcpy(&(this->in_clie1).name,p,strlen(p));
    //password:Q-char
    ba= Qpaw.toLatin1();
    p=ba.data();
    memcpy(&(this->in_clie1).password,p,strlen(p));
    if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1){
        perror("socket");
        QMessageBox::critical(NULL, QStringLiteral("错误"), QStringLiteral("socket建立失败"), QMessageBox::Yes, QMessageBox::Yes);// 添加提示
        return;
    }
    memset(&servaddr,0,sizeof(servaddr));
    h=gethostbyname(this->in_clie1.ip_1);//直接获得服务端网络相关信息
    servaddr.sin_port=htons(in_clie1.port_1);//端口信息
    servaddr.sin_family=AF_INET;//协议族
    memcpy(&servaddr.sin_addr,h->h_addr,h->h_length);//地址
    //连接建立
    if(::connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr))!=0){//connect[本机socket，对方网络地址(sockaddr *),地址大小]
        perror("connect");
        QMessageBox::critical(NULL, QStringLiteral("错误"), QStringLiteral("ip或端口错误"), QMessageBox::Yes, QMessageBox::Yes);// 添加提示
        ::close(sockfd);
        return;
    }
    else QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("成功建立连接"), QMessageBox::Yes, QMessageBox::Yes);// 添加提示;
    //相关设置
    memset(&(this->text_out),'\0',sizeof(struct packet));
    this->in_clie1.beg=1;
    client();
    if(user_if==0){
        ::close(sockfd);
    }
    this->QLin3->clear();
    this->QLin4->clear();
    this->QLin5->clear();
}

void mainwindow::QPu1_slots()//登录
{
    memset(&(this->in_clie1),'\0',sizeof(this->in_clie1));
    QByteArray ba;//转化QString对象
    QString Qnam,Qpaw;//用户名，密码
    Qnam=this->QLin3->text();
    Qpaw=this->QLin4->text();
    char *p=NULL;//引导QString指针
    //name:Q-char
    ba= Qnam.toLatin1();
    p=ba.data();
    memcpy(&(this->in_clie1).name,p,strlen(p));
    //password:Q-char
    ba= Qpaw.toLatin1();
    p=ba.data();
    memcpy(&(this->in_clie1).password,p,strlen(p));
    this->in_clie1.beg=2;
    memset(&(this->text_out),'\0',sizeof(struct packet));
    client();
    if(this->in_clie1.permit==1){
        this->QPu3->setEnabled(true);
        this->QPu4->setEnabled(true);
        this->QPu5->setEnabled(true);
        this->QPu6->setEnabled(true);
        this->QPu7->setEnabled(true);
        this->QPu8->setEnabled(true);
        this->QPu9->setEnabled(true);
    }
    this->QLin3->clear();
    this->QLin4->clear();
    this->QLin5->clear();
    this->QLa5->clear();
}

void mainwindow::QPu3_slots()//查看当前目录
{
    this->in_clie1.beg=4;
    this->in_clie1.beg_list=1;
    memset(&(this->text_out),'\0',sizeof(struct packet));
    client();
    this->QLin5->clear();
}

void mainwindow::QPu4_slots()//进入目录
{
    QByteArray ba;//转化QString对象
    QString Qlis;//目录
    char *p=NULL;
    Qlis=this->QLin5->text();//读取文件夹
    ba= Qlis.toLatin1();
    if(strlen(ba.data())==0){
        QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("文件名不可为空"), QMessageBox::Yes, QMessageBox::Yes);
        return;
    }
    p=ba.data();
    memset(&(this->text_out),'\0',sizeof(struct packet));
    memcpy(&(this->text_out.text),p,strlen(p));
    this->in_clie1.beg=4;
    this->in_clie1.beg_list=2;
    client();
    this->QLin5->clear();
    this->QLa5->clear();
}

void mainwindow::QPu5_slots()//返回上一级目录
{
    memset(&(this->text_out),'\0',sizeof(struct packet));
    this->in_clie1.beg=4;
    this->in_clie1.beg_list=3;
    client();
    this->QLin5->clear();
    this->QLa5->clear();
}

void mainwindow::QPu6_slots()//新建文件夹
{
    QByteArray ba;//转化QString对象
    QString Qlis;//目录
    char *p=NULL;
    Qlis=this->QLin5->text();//读取文件
    ba= Qlis.toLatin1();
    if(strlen(ba.data())==0){
        QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("文件名不可为空"), QMessageBox::Yes, QMessageBox::Yes);
        return;
    }
    p=ba.data();
    memset(&(this->text_out),'\0',sizeof(struct packet));
    memcpy(&(this->text_out.text),p,strlen(p));
    this->in_clie1.beg=4;
    this->in_clie1.beg_list=4;
    client();
    this->QLin5->clear();
    this->QLa5->clear();
}

void mainwindow::QPu7_slots()//删除文件夹
{
    QByteArray ba;//转化QString对象
    QString Qlis;//目录
    char *p=NULL;
    Qlis=this->QLin5->text();//读取文件
    ba= Qlis.toLatin1();
    if(strlen(ba.data())==0){
        QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("文件名不可为空"), QMessageBox::Yes, QMessageBox::Yes);
        return;
    }
    p=ba.data();
    memset(&(this->text_out),'\0',sizeof(struct packet));
    memcpy(&(this->text_out.text),p,strlen(p));
    this->in_clie1.beg=4;
    this->in_clie1.beg_list=5;
    client();
    this->QLin5->clear();
    this->QLa5->clear();
}

void mainwindow::QPu8_slots()//下载文件
{
    QByteArray ba;//转化QString对象
    QString Qlis,Qfile;//目录、文件名
    char *p=NULL;
    Qlis=this->QLin5->text();//读取目录名
    Qfile=this->QLin6->text();//读取文件名
    ba= Qlis.toLatin1();
    if(strlen(ba.data())==0){
        QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("下载路径不可为空"), QMessageBox::Yes, QMessageBox::Yes);
        this->QLin5->setPlaceholderText("在此输入路径(带斜杠/)");
        return;
    }
    p=ba.data();
    memset(&this->in_clie1.send_filepath,'\0',strlen(this->in_clie1.send_filepath));
    memcpy(&this->in_clie1.send_filepath,p,strlen(p));

    ba= Qfile.toLatin1();
    if(strlen(ba.data())==0){
        QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("文件名不可为空"), QMessageBox::Yes, QMessageBox::Yes);
        this->QLin6->setPlaceholderText("在此输入文件名");
        return;
    }
    p=ba.data();
    memset(&(this->in_clie1.send_filename),'\0',strlen(this->in_clie1.send_filename));
    memcpy(&(this->in_clie1.send_filename),p,strlen(p));//文件名

    secure_est(&this->in_clie1);//修改总路径
    memset(&(this->text_out),'\0',sizeof(struct packet));
    this->in_clie1.beg=5;
    client();
    this->QLin5->clear();
    this->QLin6->clear();
    this->QLa5->clear();
}

void mainwindow::QPu9_slots()//上传文件
{
    QByteArray ba;//转化QString对象
    QString Qlis,Qfile;//目录、文件名
    char *p=NULL;
    Qlis=this->QLin5->text();//读取目录名
    Qfile=this->QLin6->text();//读取文件名
    ba= Qlis.toLatin1();
    if(strlen(ba.data())==0){
        QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("上传路径不可为空"), QMessageBox::Yes, QMessageBox::Yes);
        this->QLin5->setPlaceholderText("在此输入路径(带斜杠/)");
        return;
    }
    p=ba.data();
    memset(&this->in_clie1.send_filepath,'\0',strlen(this->in_clie1.send_filepath));
    memcpy(&this->in_clie1.send_filepath,p,strlen(p));

    ba= Qfile.toLatin1();
    if(strlen(ba.data())==0){
        QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("文件名不可为空"), QMessageBox::Yes, QMessageBox::Yes);
        this->QLin6->setPlaceholderText("在此输入文件名");
        return;
    }
    p=ba.data();
    memset(&(this->in_clie1.send_filename),'\0',strlen(this->in_clie1.send_filename));
    memcpy(&(this->in_clie1.send_filename),p,strlen(p));//文件名

    secure_enc(&this->in_clie1);//修改总路径
    memset(&(this->text_out),'\0',sizeof(struct packet));
    this->in_clie1.beg=6;
    client();
    this->QLin5->clear();
    this->QLin6->clear();
    this->QLa5->clear();
}


void mainwindow::QPu2_slots()//退出并关闭连接
{
    this->in_clie1.beg=3;
    client();
    this->QLin5->clear();
    this->QLa5->clear();
    if(this->in_clie1.permit==0){
        this->QPu3->setEnabled(false);
        this->QPu4->setEnabled(false);
        this->QPu5->setEnabled(false);
        this->QPu6->setEnabled(false);
        this->QPu7->setEnabled(false);
        this->QPu8->setEnabled(false);
        this->QPu9->setEnabled(false);
    }
}

void mainwindow::client()//主通信
{
    int iret;//返回数据长度
    memset(&(this->text_get),'\0',sizeof(struct packet));//初始化接收数据包
    text_out.lock=this->in_clie1.permit;//将权限赋值给报头[数据包权限仅在此修改]
    switch(this->in_clie1.beg){
        case 1:{//注册模式
            if(this->in_clie1.permit==1){
                QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("已经登录，请退出后再注册"), QMessageBox::Yes, QMessageBox::Yes);
                return;
            }
            this->text_out.beg=this->in_clie1.beg;
            this->text_out.ack=0;
            this->text_out.seq=0;
            this->text_out.max=0;
            memcpy(&(this->text_out.name),this->in_clie1.name,sizeof(this->in_clie1.name));
            memcpy(&(this->text_out.password),this->in_clie1.password,sizeof(this->in_clie1.password));
            memset(&(this->in_clie1),'\0',sizeof(this->in_clie1));//及时清空
            break;
        }
        case 2:{//登录模式
            if(this->in_clie1.permit==1){
                QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("已经登录，请退出后重新登录"), QMessageBox::Yes, QMessageBox::Yes);
                return;
            }
            this->text_out.beg=this->in_clie1.beg;
            this->text_out.ack=0;
            this->text_out.seq=0;
            this->text_out.max=0;
            memcpy(&text_out.name,this->in_clie1.name,sizeof(this->in_clie1.name));
            memcpy(&text_out.password,this->in_clie1.password,sizeof(this->in_clie1.password));
            break;
        }
        case 4:{//目录操作模式
            this->text_out.beg=this->in_clie1.beg;
            this->text_out.ack=0;
            this->text_out.seq=0;
            this->text_out.max=0;
            this->text_out.beg_list=this->in_clie1.beg_list;
            break;
        }
        case 5:{//下载模式
            //请求下载包封装
            this->text_out.beg=this->in_clie1.beg;
            this->text_out.ack=0;
            this->text_out.seq=0;
            this->text_out.max=0;
            memcpy(&(this->text_out.text),this->in_clie1.send_filename,strlen(this->in_clie1.send_filename));
            //发送下载请求包
            if((iret=send(sockfd,&this->text_out,sizeof(struct packet),0))<=0){//首次发送
                printf("iret=%d\n",iret);
                perror("send");
                ::close(sockfd);
                return;
            }
            if((iret=recv(sockfd,&this->text_get,sizeof(this->text_get),0))<=0){//首次接收
                printf("iret=%d\n",iret);
                perror("recv");
                ::close(sockfd);
                return;
            }
            //首个接收包解析
            if(text_get.beg==10){
                QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("问题:%1\n").arg(this->text_get.text), QMessageBox::Yes, QMessageBox::Yes);
                return;
            }
            //是否下载
            QMessageBox::warning(NULL, QStringLiteral("注意"), QStringLiteral("文件大小为%1kb!").arg((this->text_get.max/1024)), QMessageBox::Yes, QMessageBox::Yes);
            QMessageBox msgBox0;
            msgBox0.setText("提示");
            msgBox0.setInformativeText("是否接收?");
            msgBox0.setStandardButtons(QMessageBox::No | QMessageBox::Yes);
            msgBox0.setDefaultButton(QMessageBox::Yes);
            int ret = msgBox0.exec();
            switch(ret)
            {
                case QMessageBox::No:
                    return;
                case QMessageBox::Yes:
                    break;
                default:
                    return;
            }
            std::ofstream writefile;//写文件指针
            //能否打开
            writefile.open(this->in_clie1.send_full,std::ios::binary);
            if(!writefile.is_open()){
                QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("路径或文件名错误!"), QMessageBox::Yes, QMessageBox::Yes);
                break;//跳出
            }
            this->Qprog = new QProgressBar(this);//进度条对象
            this->Qprog->move(300,450);
            this->Qprog->setOrientation(Qt::Horizontal);  // 水平方向
            this->Qprog->setMinimum(0);  // 最小值
            this->Qprog->setMaximum(101);  // 最大值
            this->Qprog->setValue(0);  // 当前进度
            this->Qprog->show();
            int ack=0;//确认总数
            int max=this->text_get.max;//文件最大值
            //确认下载包封装
            memset(&this->text_out,'\0',sizeof(struct packet));
            const char *inform0="File_upload_start";//文件传输开始
            memcpy(&this->text_out.text,inform0,sizeof(inform0));
            this->text_out.beg=25;
            this->text_out.ack=ack;
            this->text_out.seq=0;
            this->text_out.max=0;
            while(1)//发送-接收循环
            {
                //发送包
                if((iret=send(sockfd,&text_out,sizeof(struct packet),0))<=0){
                    printf("iret=%d\n",iret);
                    perror("send");
                    ::close(sockfd);
                    writefile.close();
                    return;
                }
                memset(&this->text_get,'\0',sizeof(struct packet));
                //接收包
                if((iret=recv(sockfd,&text_get,sizeof(text_get),0))<=0){
                    printf("iret=%d\n",iret);
                    perror("recv");
                    ::close(sockfd);
                    writefile.close();
                    return;
                }
                //接收包解析
                int i=0;
                writefile.seekp(ack,std::ios::beg);//文件指针定位，上一个ack
                while(i<text_get.seq)
                {
                    writefile.write(&this->text_get.text[i],sizeof(char));;
                    i++;
                }
                const char *inform="Percentage_of_files_transferred:";//返回文件存储进度信息
                ack=ack+this->text_get.seq;//更新接收数据量
                float fini=((float)ack/(float)max)*100;
 
                char p[100]={0};
                sprintf(p,"Download remaining %f%%\n",fini);
                this->QLa5->clear();
                this->QLa5->setText(QString(QLatin1String(p)));//显示进度
                this->Qprog->setValue(fini);  // 进度条
                memset(&this->text_out,'\0',sizeof(struct packet));
                sprintf(this->text_out.text,"%s %f %%",inform,fini);
                //发送包封装
                this->text_out.ack=ack;
                this->text_out.seq=0;
                this->text_out.max=0;
                if(this->text_get.beg==15){
                    //文件下载完成就跳出
                    this->Qprog->setValue(101);  // 当前进度
                    this->Qprog->close();
                    this->text_out.beg=15;
                    writefile.close();
                    secure_dec(&this->in_clie1);
                    break;//交由统一发送
                }
                else this->text_out.beg=25;
            }
            break;
        }
        case 6:{//上传模式
            std::ifstream readfile;//读文件指针
            readfile.open(this->in_clie1.send_full,std::ios::binary);//二进制形式打开
            if(!readfile.is_open()){
                QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("本地无法找到该文件"), QMessageBox::Yes, QMessageBox::Yes);
                break;//跳出
            }
            //成功打开文件
            readfile.seekg(0,std::ios::end);//定位到文件末尾
            //第一个发送包封装
            this->text_out.beg=this->in_clie1.beg;
            this->text_out.ack=0;
            this->text_out.seq=0;
            this->text_out.max=readfile.tellg();//函数用于返回文件大小
            memcpy(&this->text_out.text,this->in_clie1.send_filename,strlen(this->in_clie1.send_filename));

            int ack=0;//确认总数
            int max=this->text_out.max;//文件最大值

            this->Qprog = new QProgressBar(this);//定义进度条对象
            this->Qprog->move(300,450);
            this->Qprog->setOrientation(Qt::Horizontal);  // 水平方向
            this->Qprog->setMinimum(0);  // 最小值
            this->Qprog->setMaximum(101);  // 最大值
            this->Qprog->setValue(0);  // 当前进度
            this->Qprog->show();

            readfile.seekg(0,std::ios::beg);//定位到文件开头
            if((iret=send(sockfd,&this->text_out,sizeof(struct packet),0))<=0){//首次发送
                printf("iret=%d\n",iret);
                perror("send");
                ::close(sockfd);
                return;
            }
            while(1)//接收-发送循环
            {
                memset(&this->text_out,'\0',sizeof(struct packet));
                memset(&this->text_get,'\0',sizeof(struct packet));//初始化数据包
                //接收返回确认
                if((iret=recv(sockfd,&this->text_get,sizeof(this->text_get),0))<=0){
                    printf("iret=%d\n",iret);
                    perror("recv");
                    ::close(sockfd);
                    return;
                }
                ack=this->text_get.ack;//更新接收数据量
                float fini=((float)ack/(float)max)*100;
                //接收包解析
                this->QLa5->clear();
                this->QLa5->setText(QString(QLatin1String(this->text_get.text)));//显示进度
                this->Qprog->setValue(fini);  // 当前进度
                if(this->text_get.beg==26){
                    readfile.seekg(this->text_get.ack,std::ios::beg);//定位文件指针，从确认位置开始
                    /*
                        0~99        -seq=100->  
                                                    0~99
                                    <-ack=100-
                        100~199     
                                    -seq=100->  
                                                    100~199
                                    <-ack=200-  
                        200-299
                    */
                    int i=0;
                    while((!readfile.eof())&&(i<1000))
                    {
                        readfile.read(&this->text_out.text[i],sizeof(char));//每次只读一个
                        i++; 
                    }
                    if(readfile.eof()){//最后一次，上传完成
                        readfile.close();
                        this->Qprog->setValue(101);  // 当前进度
                        this->Qprog->close();
                        this->text_out.text[i-1]='\0';//由于eof会多判断一位，因此需要将上一位置0
                        this->text_out.beg=16;//完成报头
                        this->text_out.seq=i;
                        this->text_out.ack=0;
                        this->text_out.max=0;
                        secure_del(&this->in_clie1);
                        break;
                    }
                    else {//上传继续
                        this->text_out.beg=26;//继续报头
                        this->text_out.seq=sizeof(this->text_out.text);
                        this->text_out.ack=0;
                        this->text_out.max=0;
                        //直接发送
                        if((iret=send(sockfd,&this->text_out,sizeof(struct packet),0))<=0){
                            printf("iret=%d\n",iret);
                            perror("send");
                            ::close(sockfd);
                            return;
                        }
                    }
                }
                else {//正常情况下不会收到其他请求的报文
                    printf("%s\n",text_get.text);
                    break;
                }   
            }
            break;
        }
        case 3:{//关闭连接
            if(this->in_clie1.permit==0){
                return;//未连接情况下什么也不干
            }
            //提示框
            QMessageBox msgBox;
            msgBox.setText("提示");
            msgBox.setInformativeText("是否关闭连接?");
            msgBox.setStandardButtons(QMessageBox::No | QMessageBox::Yes);
            msgBox.setDefaultButton(QMessageBox::Yes);
            int ret = msgBox.exec();
            switch(ret)
            {
                case QMessageBox::No:
                    return;
                case QMessageBox::Yes:
                    break;
                default:
                    return;
            }
            this->text_out.beg=this->in_clie1.beg;
            if((iret=send(sockfd,&(this->text_out),sizeof(struct packet),0))<=0){
                printf("iret=%d\n",iret);
                perror("send");
                QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("成功关闭连接"), QMessageBox::Yes, QMessageBox::Yes);// 添加提示;
                ::close(sockfd);
                return;
            }
            ::close(sockfd);
            this->in_clie1.permit==0;
            user_if=0;
            return;
        }
        default:{
            QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("请重新输入指令"), QMessageBox::Yes,QMessageBox::Yes);// 添加提示;
            break;
        }
    }
    //数据包发送
    if((iret=send(sockfd,&(this->text_out),sizeof(struct packet),0))<=0){
        printf("iret=%d\n",iret);
        perror("send");
        ::close(sockfd);
        return;
    }
    //数据包接收
    if((iret=recv(sockfd,&(this->text_get),sizeof(this->text_get),0))<=0){
        printf("iret=%d\n",iret);
        perror("recv");
        ::close(sockfd);
        return;
    }
    switch (this->text_get.beg)
    {
        case 10:{//异常模式响应
            QMessageBox::warning(NULL, QStringLiteral("异常"), QStringLiteral("原因：%1").arg(this->text_get.text), QMessageBox::Yes, QMessageBox::Yes);// 提示;
            return;
            break;
        }
        case 11:{//注册成功响应
            QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("注册成功，请重新登录"), QMessageBox::Yes, QMessageBox::Yes);// 提示;
            user_if=1;
            return;
            break;
        }
        case 12:{//登录成功响应
            QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("登录成功,当前所在目录：\n%1").arg(this->text_get.text), QMessageBox::Yes, QMessageBox::Yes);
            this->in_clie1.permit=1;//权限仅在此赋予[重要]
            return;
            break;
        }
        case 14:{//远程目录成功响应
            switch (this->text_get.beg_list)
            {
                case 1:{//成功获得目录
                    if(strlen(this->text_get.text)!=0){
                        this->QLa5->clear();
                        this->QLa5->setText(QString(QLatin1String(this->text_get.text)));
                    }
                    else QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("当前目录为空\n，当前目录:%1").arg(this->text_get.text), QMessageBox::Yes, QMessageBox::Yes);// 提示
                    return;
                    break;
                }
                case 2:{//成功进入目录
                    QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("成功进入目录\n，当前目录:%1").arg(this->text_get.text), QMessageBox::Yes, QMessageBox::Yes);// 提示
                    return;
                    break;
                }
                case 3:{//成功返回上一目录
                    QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("成功返回上一目录\n，当前目录:%1").arg(this->text_get.text), QMessageBox::Yes, QMessageBox::Yes);// 提示
                    return;
                    break;
                }
                case 4:{//成功新建文件夹
                    QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("成功新建文件夹\n，当前目录:%1").arg(this->text_get.text), QMessageBox::Yes, QMessageBox::Yes);
                    return;
                    break;
                }
                case 5:{//成功删除文件夹
                    QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("成功删除文件夹\n，当前目录:%1").arg(this->text_get.text), QMessageBox::Yes, QMessageBox::Yes);
                    return;
                    break;
                }
            }
        }
        case 15:{//下载文件完毕响应
            QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("下载文件完成"), QMessageBox::Yes, QMessageBox::Yes);
            break;
        }
        case 16:{//上传文件完毕响应
            QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("发送文件完成"), QMessageBox::Yes, QMessageBox::Yes);
            break;
        }
        default:{
            QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("请重新选择功能"), QMessageBox::Yes, QMessageBox::Yes);// 提示;
            break;
        }
    }
}


