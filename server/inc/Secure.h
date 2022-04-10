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

int secure_enc(class get_client clie,char name[50]);//加密压缩，创建加密的预文件

int secure_del(class get_client clie,char name[50]);//删除压缩文件

int secure_dec(class get_client clie,char name[50]);//解密解压缩，并删除预文件


#endif