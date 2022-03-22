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



#endif