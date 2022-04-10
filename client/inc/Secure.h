#ifndef Secure
#define Secure

#include<iostream>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <assert.h>
#include <fstream>
#include"Stru.h"

int secure_enc(class input_client *clie);//加密压缩函数[上传用]

int secure_del(class input_client *clie);//删除压缩文件[上传用]

int secure_est(class input_client *clie);//修改接收的文件名，创建未解密的预文件[下载用]

int secure_dec(class input_client *clie);//解密解压缩函数[下载用]


#endif