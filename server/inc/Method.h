#ifndef Method
#define Method

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h> 
#include <dirent.h>
#include"Stru.h"

int list_mkdir(class get_client *save_c);//用户注册后自动创建用户文件夹

int list_00(class get_client *save_c);//用户登录后自动进入目录,仅调整用户类字符串

int list_01(class get_client *save_c,struct filename *fn);//获得当前所在目录所有文件

int list_02(class get_client *save_c,char *path_in);//进入path_in所在目录

int list_03(class get_client *save_c);//返回上一级目录

int list_04(class get_client *save_c,char *path_create);//新建path_create文件夹

int list_05(class get_client *save_c,char *path_dele);//删除path_dele文件夹

#endif