#ifndef __ump_h
#define __ump_h

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <stdarg.h>     // for va_list
#include <netinet/in.h> // for struct sockaddr_in; inet_pton()
#include <arpa/inet.h>  // for inet_pton()
#include <syslog.h>
#include <time.h>   
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#define MAXLINE 1024

static void err_doit(int errnoflag, int level, const char* fmt, va_list ap);
void err_ret(const char* fmt, ...);
void err_sys(const char* fmt, ...);
void err_dump(const char* fmt, ...);
void err_msg(const char* fmt, ...);
void err_quit(const char* fmt, ...);

#endif