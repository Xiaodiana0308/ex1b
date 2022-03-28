#ifndef Man
#define Man
#include <iostream>
#include <string.h>
#include"Stru.h"
/*
    客户端操作交互函数
*/
int man(class input_client *clie);//用户行为：输入ip、端口

int man0(class input_client *clie);//用户行为：客户端功能选择

int man_01(class input_client *clie);//用户行为：注册专用函数

int man_02(class input_client *clie);//用户行为：登录专用函数

int man_03(class input_client *clie);//用户行为：目录操作专用函数

int man_030(class packet *clie_text);//目录操作下文件夹名字输入函数

int man_05(class input_client *clie);//用户行为：下载文件输入函数

int man_050();//用户行为：判定是否接收文件

int man_06(class input_client *clie);//用户行为：上传文件输入函数

#endif