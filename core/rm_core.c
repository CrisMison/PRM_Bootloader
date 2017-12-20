#include "rm_print.h"
#include "rm_core.h"
#include "pl_driverbase.h"
#include "rm_type.h"
#include "rm_libfuc.h"

void flash_typestring(int c, char* ch)
{
    char tmp[20] = {0};
    switch(c)
    {
        case FLASH_BUILDIN:
        {
            rm_strncpy(tmp, "Build-In(1)", sizeof(tmp));
            rm_strncpy(ch, tmp, rm_strlen(tmp));
            break;
        }
        case FLASH_NOR:
        {
            rm_strncpy(tmp, "Nor Flash(2)", sizeof(tmp));
            rm_strncpy(ch, tmp, rm_strlen(tmp));
            break;
        }
        case FLASH_NAND:
        {
            rm_strncpy(tmp, "Nand Flash(3)", sizeof(tmp));
            rm_strncpy(ch, tmp, rm_strlen(tmp));
            break;
        }
        case FLASH_SPINOR:
        {
            rm_strncpy(tmp, "SPINor Flash(4)", sizeof(tmp));
            rm_strncpy(ch, tmp, rm_strlen(tmp));
            break;
        }
        default:
        {
            rm_strncpy(tmp, "NULL(0)", sizeof(tmp));
            rm_strncpy(ch, tmp, rm_strlen(tmp));
            break;
        }
    }
}
void rm_version(void)
{
    dprintf("\n\n");
    dprintf("\033[1;32mProject RM Bootloader\033[0m\n");
    dprintf("\033[1;37mVersion %d.%04d (%s)\033[0m\n",RM_MAIN_VERSION, RM_SUB_VERSION, RM_VERSION_CODE);
    dprintf("\n");
}


void rm_detective(void)
{
    char flash_string[20];
    
    flash_typestring(flash_type(), flash_string);
    RM_Ok("Deivce : %s\n", DEVICE_NAME);
    RM_Ok("Flash Size: %d KB, %s\n", flash_size(), flash_string);
}

void rm_setupchk(void)
{
    RM_Ok("SysTick Start...\n");
    RM_Ok("UART Start...\n");
    RM_Ok("System Signal Start...\n");
}