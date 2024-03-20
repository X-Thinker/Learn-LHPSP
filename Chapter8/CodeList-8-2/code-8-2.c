/*代码清单8-2 带状态转移的有限状态机*/
STATE_MACHINE()
{
    State cur_State = type_A;
    while(cur_State != type_C)
    {
        Package _pack = getNewPackage();
        switch(cur_State)
        {
        case type_A:
            process_package_state_A(_pack);
            cur_State = type_B;
            break;
        case type_B:
            process_package_state_B(_pack);
            cur_State = type_C;
            break;
        }
    }
}