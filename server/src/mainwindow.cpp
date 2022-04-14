#include"./../inc/Mainwindow.h"

mainwindow::mainwindow(QWidget *parent) :QMainWindow(parent)
{
    //窗口设置
    this->resize(1200,700);
    this->setWindowTitle("安全文件传输服务端v.1.0");

    this->QLa0=new QLabel(this);
    this->QPu0=new QPushButton(this);
    this->QPu1=new QPushButton(this);
    this->QLin1=new QLineEdit(this);
    this->QLa0->setObjectName(QStringLiteral("Qtitle"));
    this->QPu0->setObjectName(QStringLiteral("but0"));
    this->QPu1->setObjectName(QStringLiteral("but1"));
    this->QLin1->setObjectName(QStringLiteral("Qport"));
    this->QLa0->setText("安全文件传输服务端");
    this->QPu0->setText("启动");
    this->QPu1->setText("关闭");
    this->QLin1->setPlaceholderText("启用端口号");
    this->QLin1->setClearButtonEnabled(true);
    this->QLa0->setGeometry(QRect(400,50,400,50));
    this->QPu0->setGeometry(QRect(250,600,100,50));
    this->QPu1->setGeometry(QRect(500,600,100,50));
    this->QLin1->setGeometry(QRect(160,110,150,40));
    memset(&get_serv,'\0',sizeof(get_serv));
    memset(&npd,'\0',sizeof(npd));

    QObject::connect(this->QPu0,&QPushButton::clicked,this,&mainwindow::QPu0_slots);
    QObject::connect(this->QPu1,&QPushButton::clicked,this,&mainwindow::close);
}

void mainwindow::QPu0_slots()
{
    this->QPu0->setEnabled(false);
    memset(&get_serv,'\0',sizeof(get_serv));
    //读取端口号
    QByteArray ba;//转化QString对象
    QString Qlis;//目录
    char *p=NULL;
    Qlis=this->QLin1->text();
    ba= Qlis.toLatin1();
    if(strlen(ba.data())==0){
        QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("端口号不可为空"), QMessageBox::Yes, QMessageBox::Yes);
        return;
    }
    p=ba.data();
    char ip[20]="192.168.1.1";//没啥用
    memcpy(this->get_serv.ip_1,ip,sizeof(ip));
    this->get_serv.port_1=atoi(p);
    if((iname=server(this->get_serv,&this->npd,this->iname))!=-1){
        iname++;
        sleep(5);
        this->QPu0->setEnabled(true);

    }
    else return;
}
