#include"./../inc/Man.h"

int man(class input_client *clie)
{
    const char ip[20]="10.203.174.170";
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
    printf("注册模式");
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
    printf("登录模式");
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