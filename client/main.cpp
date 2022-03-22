#include <iostream>
#include"./inc/Client.h"
#include"./inc/Man.h"
#include"./inc/Stru.h"


int main()
{
    class input_client in_clie1;
    memset(&in_clie1,'\0',sizeof(in_clie1));
    in_clie1.permit=0;//初始化访问权限
    man(&in_clie1);
    client(in_clie1);
    return 0;
}