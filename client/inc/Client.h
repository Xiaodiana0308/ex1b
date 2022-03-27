#ifndef Client
#define Client

#include <iostream>
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
#include"Man.h"

int client(class input_client in_clie);//通信函数

#endif
