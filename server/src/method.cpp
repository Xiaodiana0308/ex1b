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
    int i=0;
    char *spec1=".";
    char *spec2="..";
    dir=opendir((*save_c).filename);
    while ((ptr=readdir(dir))!=NULL)//如果存在文件就一直读取
    {
        if((strcmp(ptr->d_name,spec1)!=0)&&(strcmp(ptr->d_name,spec2)!=0)){
            memcpy(&(*fn).filen[i],ptr->d_name,sizeof(ptr->d_name));
            (*fn).typen[i]=ptr->d_type;//存入目录结构体
            printf("文件=%s，类型=%d\n",ptr->d_name,ptr->d_type);
            i++;
        }
        if(i>=50){
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
    for(int i=0;i<50;i++)
    {
        printf("name1=%s,ame2=%s\n",fn.filen[i],path_in);
        if(strcmp(fn.filen[i],path_in)==0){
            //进入目录
            char *pathname;
            sprintf(pathname,"%s/%s",(*save_c).filename,path_in);
            memset(&(*save_c).filename,'\0',sizeof((*save_c).filename));
            memcpy(&(*save_c).filename,pathname,sizeof(pathname));
            return 0;
        }
    }
    return -1;//错误：不存在目录
    
}

int list_03(class get_client *save_c)//返回上一目录
{
    //判断是否可以返回上级目录
    char *rootpath;//根本目录
    const char *datapath="/home/wxq/work/wangluoanquan/ex1b/serverdata";//此为服务端存储根目录
    sprintf(rootpath,"%s/%s",datapath,(*save_c).name);
    if(strcmp(rootpath,(*save_c).filename)==0){
        return -1;//错误：无法访问上一级目录
    }
    //可以返回
    char newpath[50];//返回的目录
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
    sprintf((*save_c).filename,"%s/%s",(*save_c).filename,path_create);
    int mkdirretval;
    umask(0);
    if((mkdirretval=mkdir((*save_c).filename,S_IRWXU))!=0){
        perror("mkdir");
        return -1;//错误：文件夹已经存在
    }
    return 0;
}

int list_05(class get_client *save_c,char *path_dele)//删除目录
{
    //目录是否存在
    
    
    return 0;
}