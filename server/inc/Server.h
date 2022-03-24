#ifndef Server
#define Server

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <assert.h>
#include"./Stru.h"
#include"./Method.h"

int server(class get_server get_serv,struct name_password *npd);//通信函数

#endif
