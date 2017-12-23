#include "rm_shell.h"
#include "rm_print.h"
#include "rm_libfuc.h"
#include "pl_driverbase.h"
char rm_getchar(uartbuf *pu)
{
    int ch = 0;
    while(pu->RxGetP == pu->RxWriteP);
    ch = pu->RxBuf[pu->RxGetP];
    if(++pu->RxGetP >= UART_BUFFER_SIZE)
    {
        pu->RxGetP = 0;
    }
    return ch;
}

#ifdef RM_CONSOLE_LINUX 
void rm_shellentry(void)
{
    char ch;
    char shellbuf[SHELL_BUFFER_MAX];
    int  shellbufp = 0;
    int  shellbufl = 0;
    int  head = 1;

    RM_Ok("Console Start...\n");
    dprintf("\n");
    
    while(1)
    {
        if(head == 1)
        {
            dprintf("\033[1;36mRM Bootloader\033[0m# ");
            head = 0;
        }
        ch = rm_getchar(&uart);
        if(ch == 0)
            continue;
        
        switch(ch)
        {
            case '\b':
            {
                if(shellbufp > 0 && shellbufl > 0)
                {
                    for(int p = shellbufp; p <= shellbufl; p++)
                    {
                        shellbuf[p - 1] = shellbuf[p];
                    }
                    shellbufp--;
                    shellbufl--;
                    dprintf("\b%s \b",&shellbuf[shellbufp]);
                    for(int p = 0; p < shellbufl - shellbufp; p++)
                    {
                        dprintf("\b");
                    }
                }
                break;
            }
            case '\r':
            case '\n':
            {
                dprintf("\n");
                rm_memset(shellbuf, 0, SHELL_BUFFER_MAX);
                shellbufp = 0;
                shellbufl = 0;
                head = 1;
                break;
            }
            case 0x1B:      /* Linux Console Control Bit 1 : 0x1B*/
            {
                dprintf("%c",ch);
                ch = rm_getchar(&uart);
                if(ch != 0x5B)      /* Linux Console Control Bit 2 : 0x5B */
                    break;
                
                dprintf("%c",ch);
                ch = rm_getchar(&uart);
                switch(ch)
                {
                    case 0x41:      /* Key Up Arrow (0x1B 0x5B 0x41) */
                    case 0x42:      /* Key Down Arrow (0x1B 0x5B 0x41) */
                        dprintf("%c",0);
                        break;
                    
                    case 0x43:
                    {
                        if(shellbufp < shellbufl)
                        {
                            dprintf("%c",ch);
                            shellbufp++;
                        }
                        break;
                    }
                    case 0x44:
                    {
                        if(shellbufp > 0)
                        {
                            dprintf("%c",ch);
                            shellbufp--;
                        }
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            default:
            {
                if(shellbufp <= SHELL_BUFFER_MAX && shellbufl <= SHELL_BUFFER_MAX)
                {
                    for(int p = shellbufl; p >= shellbufp; p--)
                    {
                        shellbuf[p + 1] = shellbuf[p];
                    }
                    shellbuf[shellbufp] = ch;
                    dprintf("%s",&shellbuf[shellbufp]);
                    shellbufp++;
                    shellbufl++;
                    for(int p = 0; p < shellbufl - shellbufp; p++)
                    {
                        dprintf("\b");
                    }
                }
            }
        }
    }
}
#endif