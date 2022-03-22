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
    server(get_serv,&npd);
    return 0;
} 
