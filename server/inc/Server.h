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
#include <fstream>
#include"Stru.h"
#include"Method.h"
#include"Secure.h"

using namespace std;

int server(class get_server get_serv,struct name_password *npd,int iname);//通信函数

#endif
