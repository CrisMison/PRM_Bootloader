#ifndef _PL_DRIVERBASE_H_
#define _PL_DRIVERBASE_H_

#define  RM_DisableInt()          // { __set_PRIMASK(1); }	
#define  RM_EnableInt()           // { __set_PRIMASK(0); }	

#define UART_BUFFER_SIZE    256
#define UART_DEVICE         USART1

#define DEVICE_NAME         "STM32F103ZET6"

#define FLASH_NULL          0
#define FLASH_BUILDIN       1
#define FLASH_NOR           2
#define FLASH_NAND          3
#define FLASH_SPINOR        4

typedef struct
{
    char TxBuf[UART_BUFFER_SIZE];
    char RxBuf[UART_BUFFER_SIZE];
    void* puart;
    int TxSendP;
    int TxWriteP;
    int RxWriteP;
    int RxGetP;
    int (*SendData)(char ch);
    void (*RxSingalOn)(void);
    void (*RxSingalOff)(void);
    void (*TxSingalOn)(void);
    void (*TxSingalOff)(void);
    
}uartbuf;

typedef struct
{
    unsigned char mac_0;
    unsigned char mac_1;
    unsigned char mac_2;
    unsigned char mac_3;
    unsigned char mac_4;
    unsigned char mac_5;
}mac_addr;

typedef struct 
{
    unsigned char ipv4_0;
    unsigned char ipv4_1;
    unsigned char ipv4_2;
    unsigned char ipv4_3;
}ipv4_addr;

extern uartbuf uart;
int systick_init(void);
int signal_init(void);
int ethernet_init(void);
int uart_init();


int uart_fputc(char ch);
void signal_free(void);
void signal_busy(void);
void signal_halt(void);
void device_init(void);
unsigned int flash_type(void);
unsigned int flash_size(void);

int sleep_us(int us);
int sleep_ms(int ms);
int sleep_s(int s);

#endif
