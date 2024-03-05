/*代码清单5-1 判断机器字节序*/
#include <stdio.h>

//判断机器字节序
void byteorder()
{
    union 
    {
        //short和char[]共享空间
        //char[0]为低地址端，char[1]为高地址端
        short value;
        char union_byte[sizeof(short)];
    }test;
    //整数高位为 1,低位为 2
    test.value = 0x0102;

    //整数高位放低地址端：大端字节序/网络字节序
    //整数高位放高地址端：小端字节序/主机字节序
    if((test.union_byte[0] == 1) && (test.union_byte[1] == 2))
        printf("big endian\n");
    else if((test.union_byte[0] == 2) && (test.union_byte[1] == 1))
        printf("little endian\n");
    else 
        printf("unknown...\n");
}

int main(void)
{
    byteorder();
    //输出结果为小端字节序
    return 0;
}