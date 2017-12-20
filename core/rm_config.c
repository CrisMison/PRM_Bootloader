#include "rm_print.h"
#include "rm_core.h"
#include "rm_shell.h"
#include "rm_print.h"
#include "pl_driverbase.h"
int main()
{

    device_init();
    sleep_s(2);
    rm_version();
    rm_setupchk();
    rm_detective();
    rm_shellentry();
    
    while(1);
}