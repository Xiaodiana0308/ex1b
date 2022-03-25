#include"./../inc/Sett.h"

int sett(class get_server *ge_ser)
{
    char ip[20]="192.168.1.1";
    memcpy(&(*ge_ser).ip_1,ip,sizeof(ip));
    short port=5005;
    (*ge_ser).port_1=port;
    return 0;
}

int living_sett(int living)
{
    printf("是否关闭？(1是，0否)\n");
    fflush(stdin);
    scanf("%d",&living);
    return living;
}