/*代码清单5-5 接受一个异常的连接*/
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

int main(int argc, char *argv[])
{
    if(argc <= 2)
    {
        printf("usage:%s ip_address port_number\n", basename(argv[0]));
        return 1;
    }

    const char *ip = argv[1];
    int port = atoi(argv[2]);
    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &address.sin_addr);
    address.sin_port = htons(port);
    int sock = socket(PF_INET, SOCK_STREAM, 0);
    assert(sock >= 0);

    int ret = bind(sock, (struct sockaddr*)&address, sizeof(address));
    assert(ret != -1);

    ret = listen(sock, 5);
    assert(ret != -1);

    //暂停20秒来等待客户端连接操作和相关操作（掉线或者退出）完成
    sleep(20);
    struct sockaddr_in client;
    socklen_t client_addrlength = sizeof(client);
    //accept只是从监听队列中取出连接，而不论连接处于何种状态
    //更不关系任何网络状况的变化
    //因此即使客户端连接后掉线或者退出，accept依然可以返回正确值
    int connfd = accept(sock, (struct sockaddr*)&client, &client_addrlength);
    if(connfd < 0)
        printf("errno is:%d\n", errno);
    else 
    {
        //接受连接成功打印客户端的IP地址和端口号
        char remote[INET_ADDRSTRLEN];
        printf("connected with ip:%s and port:%d\n", inet_ntop(AF_INET, &client.sin_addr, remote, INET_ADDRSTRLEN), ntohs(client.sin_port));
        close(connfd);
    }

    close(sock);
    return 0;
}