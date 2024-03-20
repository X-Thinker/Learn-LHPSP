/*代码清单7-2 切换用户*/
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

static bool switch_to_user(__uid_t user_id, __gid_t gp_id)
{
    /*先确保目标用户不是root*/
    if((user_id == 0) && (gp_id == 0))
        return false;
    /*确保当前用户是合法用户：root或者目标用户*/
    __gid_t gid = getgid();
    __uid_t uid = getuid();
    if(((gid != 0) || (uid != 0)) && ((gid != gp_id) || (uid != user_id)))
        return false;
    /*如果不是root，则已经是目标用户*/
    if(uid != 0)
        return true;
    if((setgid(gp_id) < 0) || (setuid(user_id) < 0))
        return false;

    return true;
}