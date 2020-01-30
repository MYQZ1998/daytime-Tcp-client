/*
Get the time of destination server.
Author: MYQZ
Time: 2020/1/29
Linux
IPv4
 */

#include "unp.h"
using namespace std;

int Socket(int family, int type, int protocol);
void Inet_pton(int famliy, char* src, void* dst);
void Connect(int fd, struct sockaddr* addr, unsigned int size);
void Read(int fd, char* recvline, int n);

int main(int argc, char** argv)
{
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr;
    
    if(argc != 2)
        err_quit("usage: a.out <IPaddress>");

    sockfd = Socket(AF_INET, SOCK_STREAM, 0);

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(13);

    Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    Connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

    Read(sockfd, recvline, n);

    exit(0);
}

int Socket(int family, int type, int protocol)
{
    int n;
    if((n = socket(family, type, protocol)) == -1)
        err_sys("socket error");
    return n;
}

void Inet_pton(int family, char* src, void* dst)
{
    if(inet_pton(family, src, dst) <= 0)
        err_quit("inet_pton error for %s", src);
}

void Connect(int fd, struct sockaddr* addr, unsigned int size)
{
    if(connect(fd, addr, size) < 0)
        err_sys("connect error");
}

void Read(int fd, char* recvline, int n)
{
    while((n = read(fd, recvline, MAXLINE)) > 0)
    {
        recvline[n] = 0;
        if(fputs(recvline, stdout) == EOF)
            err_sys("fputs error");
    }
    if(n < 0)
        err_sys("read error");
}