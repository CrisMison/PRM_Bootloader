#ifndef _RM_PRINT_
#define _RM_PRINT_

extern void uart_init(void);
extern void __dprintf(const char *format, ...);


#define dprintf                     __dprintf
#define RM_Debug(fmt, args...)      do{dprintf("[\033[0;33m  DEBUG  \033[0m] "); dprintf(fmt, ##args);}while(0)
#define RM_Msg(fmt, args...)        do{dprintf("[ MESSAGE ] "); dprintf(fmt, ##args);}while(0)
#define RM_Err(fmt, args...)        do{dprintf("[\033[0;31m FAILED  \033[0m] "); dprintf(fmt, ##args);}while(0)
#define RM_Ok(fmt, args...)         do{dprintf("[\033[0;32m SUCCESS \033[0m] "); dprintf(fmt, ##args);}while(0)
#endif