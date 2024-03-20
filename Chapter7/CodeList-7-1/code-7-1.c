/*代码清单7-1 测试进程的UID和EUID的区别*/
#include <unistd.h>
#include <stdio.h>

int main()
{
    __uid_t uid = getuid();
    __uid_t euid = geteuid();

    printf("userid is %d, effective userid is %d\n", uid, euid);
    return 0;
}