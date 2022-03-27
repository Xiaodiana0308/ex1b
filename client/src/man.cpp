#include"./../inc/Man.h"

int man(class input_client *clie)
{
    const char ip[20]="10.203.165.226";
    int port=5005;
    memcpy(&(*clie).ip_1,ip,strlen(ip));
    (*clie).port_1=port;
    return 0;
}

int man0(class input_client *clie)
{
    int beg;
    printf("请输入模式:\n");
    fflush(stdin);
    scanf("%d",&beg);
    (*clie).beg=beg;
    return 0;
}

int man_01(class input_client *clie)
{
    printf("注册模式\n");
    char name[15];
    char password[15];
    printf("请输入账号：\n");
    fflush(stdin);
    scanf("%s",name,15);
    printf("请输入密码：\n");
    fflush(stdin);
    scanf("%s",password,15);
    memcpy(&(*clie).name,name,strlen(name));
    mempcpy(&(*clie).password,password,strlen(password));
    return 0;
}

int man_02(class input_client *clie)
{
    printf("登录模式\n");
    char name[15];
    char password[15];
    printf("请输入账号：\n");
    fflush(stdin);
    scanf("%s",name,15);
    printf("请输入密码：\n");
    fflush(stdin);
    scanf("%s",password,15);
    memcpy(&(*clie).name,name,strlen(name));
    mempcpy(&(*clie).password,password,strlen(password));
    return 0;
}

int man_03(class input_client *clie)
{
    printf("目录模式\n");
    int a;
    printf("请输入目录操作：\n");
    fflush(stdin);
    scanf("%d",&a,1);
    (*clie).beg_list=a;
    return 0;
}

int man_030(class packet *clie_text)
{
    printf("请输入文件名：\n");
    fflush(stdin);
    scanf("%s",&(*clie_text).text);
    return 0;
}

int man_06(class input_client *clie)//第一次读取文件
{
    char path[450]={0};
    printf("请输入上传文件所在路径：(带斜杠)\n");
    fflush(stdin);
    scanf("%s",path);
    printf("请输入上传文件名：\n");
    fflush(stdin);
    scanf("%s",&(*clie).send_filename);
    sprintf((*clie).send_filepath,"%s%s",path,(*clie).send_filename);
    return 0;
}