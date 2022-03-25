#include"./../inc/Method.h"

int list_mkdir(class get_client *save_c)//创建根目录
{
    const char *datapath="/home/wxq/work/wangluoanquan/ex1b/serverdata";//此为服务端存储根目录
    sprintf((*save_c).filename,"%s/%s",datapath,(*save_c).name);//拼接路径
    const char *path=(*save_c).filename;//char *转为const char *
    int mkdireal;
    umask(0);
    if((mkdireal=mkdir(path,S_IRWXU))!=0){
        perror("mkdir");
        return -1;
    }
    printf("create path:%s\n",(*save_c).filename);
    return 0;
}

int list_00(class get_client *save_c)//进入根目录
{
    const char *datapath="/home/wxq/work/wangluoanquan/ex1b/serverdata";//此为服务端存储根目录
    sprintf((*save_c).filename,"%s/%s",datapath,(*save_c).name);
    return 0;
}

int list_01(class get_client *save_c,struct filename *fn)//获取当前目录下所有文件名
{
    DIR *dir;
    struct dirent *ptr;
    memset(&(*fn),'\0',sizeof(*fn));
    int i=0;
    char *spec1=".";
    char *spec2="..";
    dir=opendir((*save_c).filename);
    while ((ptr=readdir(dir))!=NULL)//如果存在文件就一直读取
    {
        if((strcmp(ptr->d_name,spec1)!=0)&&(strcmp(ptr->d_name,spec2)!=0)){
            memcpy(&(*fn).filen[i],ptr->d_name,sizeof(ptr->d_name));
            (*fn).typen[i]=ptr->d_type;//存入目录结构体
            i++;
        }
        if(i>=50){//50文件最多
            break;
        }
    }
    closedir(dir);
    return 0;
}

int list_02(class get_client *save_c,char *path_in)//进入目录
{
    //判断目录是否存在
    struct filename fn;
    list_01(&(*save_c),&fn);
    if(fn.typen[0]==0){
        return -1;//文件夹为空，不存在目录
    }
    int i=0;
    while(fn.typen[i]!=0)
    {
        if(strcmp(fn.filen[i],path_in)==0){
            //进入目录
            char pathname[500]={0};
            sprintf(pathname,"%s/%s",(*save_c).filename,path_in);
            memset(&(*save_c).filename,'\0',sizeof((*save_c).filename));
            memcpy(&(*save_c).filename,pathname,sizeof(pathname));
            return 0;
        }
        i++;
    }
    return -1;//错误：不存在目录
    
}

int list_03(class get_client *save_c)//返回上一目录
{
    //判断是否可以返回上级目录
    char rootpath[500]={0};//根本目录
    const char *datapath="/home/wxq/work/wangluoanquan/ex1b/serverdata";//此为服务端存储根目录
    sprintf(rootpath,"%s/%s",datapath,(*save_c).name);
    if(strcmp(rootpath,(*save_c).filename)==0){
        return -1;//错误：无法访问上一级目录
    }
    //可以返回
    char newpath[500]={0};//返回的目录
    int j=0;
    for(int i=49;i>=0;i--)//从后往前循环字符串
    {
        if(j==1){
            newpath[i]=(*save_c).filename[i];
        }
        if((*save_c).filename[i]=='/'){//到右边第一个字符串为'/'之后，开始存入
            j=1;
        }

    }
    printf("%s\n",newpath);
    memset(&(*save_c).filename,'\0',sizeof((*save_c).filename));
    memcpy(&(*save_c).filename,newpath,sizeof(newpath));
    return 0;
}

int list_04(class get_client *save_c,char *path_create)//创建文件夹
{
    //判断文件夹是否存在
    struct filename fn;
    list_01(&(*save_c),&fn);
    for(int i=0;i<50;i++)
    {
        if(strcmp(fn.filen[i],path_create)==0){
            return -1;//错误：已存在文件夹
        }
    }
    //不存在，创建文件夹
    char newpath[500]={0};//不改变当前所在路径
    sprintf(newpath,"%s/%s",(*save_c).filename,path_create);//不允许给字符串指针赋值
    int mkdirretval;
    umask(0);
    if((mkdirretval=mkdir(newpath,S_IRWXU))!=0){
        perror("mkdir");
        return -1;//错误：文件夹已经存在
    }
    printf("当前目录=%s\n",(*save_c).filename);
    return 0;
}

int list_05(class get_client *save_c,char *path_dele)//删除目录
{
    //目录是否存在
    struct filename fn;
    list_01(&(*save_c),&fn);
    for(int i=0;i<50;i++)
    {
        if(strcmp(fn.filen[i],path_dele)==0){
            char delpath[500]={0};//不改变当前所在路径
            char order_cd[3]="cd";
            char order_del[7]="rm -rf";
            sprintf(delpath,"%s %s & %s %s",order_cd,(*save_c).filename,order_del,path_dele);//命令：进入并删除文件
            int deleretval;
            if((deleretval=system(delpath))<0){
                perror("system");
                return -1;
            }
            return 0;
        }
    }
    return -1;//错误：不存在文件夹
}