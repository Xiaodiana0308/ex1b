#include <iostream>
#include"./inc/Server.h"
#include"./inc/Stru.h"
#include"./inc/Sett.h"


int main()
{
    class get_server get_serv;
    struct name_password npd;
    memset(&get_serv,'\0',sizeof(get_serv));
    memset(&npd,'\0',sizeof(npd));
    sett(&get_serv);
    int living=0;//判断结束连接后是否继续打开端口
    int iname=0;//注册次序,不会重置
    while(living==0)
    {
        if((iname=server(get_serv,&npd,iname))!=-1){
            iname++;
            living=living_sett(living);
            sleep(20);
        }
        else break;
    }
    
    return 0;
} 
