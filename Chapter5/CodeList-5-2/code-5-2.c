/*代码清单5-2 不可重入的 inet_ntoa 函数*/
#include <arpa/inet.h>
#include <stdio.h>

int main(void)
{
    struct in_addr addr1;
    addr1.s_addr = 1234;
    struct in_addr addr2;
    addr2.s_addr = 101947160;
    char *szValue1 = inet_ntoa(addr1);
    char *szValue2 = inet_ntoa(addr2);
    //输出结果显示两者地址相同
    //揭示了 inet_ntoa 函数的不可重入性
    printf("address 1:%s\n", szValue1);
    printf("address 2:%s\n", szValue2);
    return 0;
}