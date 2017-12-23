#include "stdarg.h"
#include "string.h"

#include "rm_print.h"
extern int uart_fputc(char ch);


char itoa_bit(int n)
{
    if(n < 0)
        n = -n;
    if(n < 0 || n > 9)
    {
        __dprintf("[ERR][itoa_bit] dprintf has a calculate Error\n");
        return '0';
    }
    
    return '0' + n;
}

char itoh_bit(int n, char x)
{
    if(n < 0 || n > 15)
    {
        __dprintf("[ERR][itoa_bit] dprintf has a calculate Error\n");
        return '0';
    }
    
    if(n <= 9)
        return '0' + n;
    else
    {
        if(x == 'x')
            return 'a' + n - 10;
        else
            return 'A' + n - 10;
    }
}

long long int npow(int base, int n)
{
    int i = 0;
    long long int sum = 1;
    
    for(i = 0; i < n; i++)
    {
        sum = sum * base;
    }
    
    return sum;
}

/* Calculate the decimical bits of the number */
int dec_bit(long long int n)
{
    int bit = 20;
    if(n < 0)
        n = -n;
    for(bit = 20; bit >= 0; bit--)
    {
        if( n / npow(10, bit) > 0)
        {
            return bit + 1; 
        }
    }
    return bit + 1;
}

/* Calculate the decimical bits of the number */
int udec_bit(unsigned long long int n)
{
    int bit = 20;
    for(bit = 20; bit >= 0; bit--)
    {
        if( n / npow(10, bit) > 0)
            return bit + 1; 
    }
    return bit + 1;
}

/* Calculate the hex bits of the number */
int hex_bit(unsigned long long int n)
{
    int bit = 16;
    for(bit = 16; bit >= 0; bit--)
    {
        if( n / npow(16, bit) > 0)
            return bit + 1; 
    }
    return bit + 1;
}

void __dprintf(const char *format, ...)
{
    int zero_set = 0;
    int num_bit = 0;
    int num_long = 0;
    va_list arg;
    va_start(arg, format);
    while(*format)
    {
        char ret = *format;
        zero_set = 0;
        num_bit = 0;
        num_long = 0;
        if(ret == '%')
        {
SWITCHER:
            switch(*++format)
            {
                case 'c':
                {
                    char ch = va_arg(arg, int);
                    if(ch == '\n' || ch == '\r')
                    {
                        uart_fputc('\r');
                        uart_fputc('\n');
                    }
                    else
                        uart_fputc(ch);
                    break;
                }
                case 's':
                {
                    char *ch = va_arg(arg,char *);
                    while(*ch)
                    {
                        if(*ch == '\n' && *(ch - 1) != '\r')
                        {
                            uart_fputc('\r');
                        }
                        uart_fputc(*ch++);
                    }
                    break;
                }
                case '0':
                {
                    if(zero_set == 1 && num_bit == 0)
                        break;
                    if(num_bit == 0)
                        zero_set = 1;
                    else
                    {
                        num_bit = num_bit * 10 + 0;
                    }
                    goto SWITCHER;
                }
                case '1':
                {
                    num_bit = num_bit * 10 + 1;
                    goto SWITCHER;
                }
                case '2':
                {
                    num_bit = num_bit * 10 + 2;
                    goto SWITCHER;
                }
                case '3':
                {
                    num_bit = num_bit * 10 + 3;
                    goto SWITCHER;
                }
                case '4':
                {
                    num_bit = num_bit * 10 + 4;    
                    goto SWITCHER;
                }
                case '5':
                {
                    num_bit = num_bit * 10 + 5;
                    goto SWITCHER;
                }
                case '6':
                {
                    num_bit = num_bit * 10 + 6;
                    goto SWITCHER;
                }
                case '7':
                {
                    num_bit = num_bit * 10 + 7;
                    goto SWITCHER;
                }
                case '8':
                {
                    num_bit = num_bit * 10 + 8;
                    goto SWITCHER;
                }
                case '9':
                {
                    num_bit = num_bit * 10 + 9;
                    goto SWITCHER;
                }
                case 'l':
                {
                    num_long++;
                    if(num_long > 2)
                        break;
                    goto SWITCHER;
                }
                case 'd':
                {
                    if(num_long == 2)
                    {
                        long long int n = va_arg(arg, long long int);
                        int n_bit = dec_bit(n);
                        if(n == 0)
                        {
                            uart_fputc('0');
                            break;
                        }
                        if(n < 0)
                        {
                            uart_fputc('-');
                            if(num_bit > 0)
                                num_bit--;
                        }
                        while(num_bit > n_bit)
                        {
                            if(zero_set == 1)
                                uart_fputc('0');
                            else
                                uart_fputc(' ');
                            
                            num_bit--;
                        }
                        
                        for(; n_bit > 0; n_bit--)
                        {
                            char ch;
                            int c = n / npow(10, n_bit - 1);
                            n -= c * npow(10, n_bit - 1);
                            if(c < 0) c = -c;
                            if(c > 9 || c < 0)
                            {
                                __dprintf("[ERR][dprintf] dprintf has a calculate Error\n");
                                c = 0;
                            }
                            ch = itoa_bit(c);
                            uart_fputc(ch);
                        }
                    }
                    else if(num_long == 1)
                    {
                        long int n = va_arg(arg, long int);
                        int n_bit = dec_bit(n);
                        if(n == 0)
                        {
                            uart_fputc('0');
                            break;
                        }
                        if(n < 0)
                        {
                            uart_fputc('-');
                            if(num_bit > 0)
                                num_bit--;
                        }
                        while(num_bit > n_bit)
                        {
                            if(zero_set == 1)
                                uart_fputc('0');
                            else
                                uart_fputc(' ');
                            
                            num_bit--;
                        }
                        
                        for(; n_bit > 0; n_bit--)
                        {
                            char ch;
                            int c = n / npow(10, n_bit - 1);
                            n -= c * npow(10, n_bit - 1);
                            if(c < 0) c = -c;
                            if(c > 9 || c < 0)
                            {
                                c = 0;
                            }
                            ch = itoa_bit(c);
                            uart_fputc(ch);
                        }
                    }
                    else
                    {
                        int n = va_arg(arg, int);
                        int n_bit = dec_bit(n);
                        if(n == 0)
                        {
                            uart_fputc('0');
                            break;
                        }
                        if(n < 0)
                        {
                            uart_fputc('-');
                            if(num_bit > 0)
                                num_bit--;
                        }
                        while(num_bit > n_bit)
                        {
                            if(zero_set == 1)
                                uart_fputc('0');
                            else
                                uart_fputc(' ');
                            
                            num_bit--;
                        }
                        for(; n_bit > 0; n_bit--)
                        {
                            char ch;
                            int c = n / npow(10, n_bit - 1);
                            n -= c * npow(10, n_bit - 1);
                            if(c < 0) c = -c;
                            if(c > 9 || c < 0)
                            {
                                __dprintf("[ERR][dprintf] dprintf has a calculate Error\n");
                                c = 0;
                            }
                            ch = itoa_bit(c);
                            uart_fputc(ch);
                        }
                    }
                    break;
                }
                case 'u':
                {
                    if(num_long == 2)
                    {
                        unsigned long long int n = va_arg(arg, unsigned long long int);
                        int n_bit = udec_bit(n);
                        if(n == 0)
                        {
                            uart_fputc('0');
                            break;
                        }
                        while(num_bit > n_bit)
                        {
                            if(zero_set == 1)
                                uart_fputc('0');
                            else
                                uart_fputc(' ');
                            
                            num_bit--;
                        }
                        
                        for(; n_bit > 0; n_bit--)
                        {
                            char ch;
                            int c = n / npow(10, n_bit - 1);
                            n -= c * npow(10, n_bit - 1);
                            if(c < 0) c = -c;
                            if(c > 9 || c < 0)
                            {
                                __dprintf("[ERR][dprintf] dprintf has a calculate Error\n");
                                c = 0;
                            }
                            ch = itoa_bit(c);
                            uart_fputc(ch);
                        }
                    }
                    else if(num_long == 1)
                    {
                        unsigned long int n = va_arg(arg, unsigned long int);
                        int n_bit = udec_bit(n);
                        if(n == 0)
                        {
                            uart_fputc('0');
                            break;
                        }
                        while(num_bit > n_bit)
                        {
                            if(zero_set == 1)
                                uart_fputc('0');
                            else
                                uart_fputc(' ');
                            
                            num_bit--;
                        }
                        
                        for(; n_bit > 0; n_bit--)
                        {
                            char ch;
                            int c = n / npow(10, n_bit - 1);
                            n -= c * npow(10, n_bit - 1);
                            if(c < 0) c = -c;
                            if(c > 9 || c < 0)
                            {
                                __dprintf("[ERR][dprintf] dprintf has a calculate Error\n");
                                c = 0;
                            }
                            ch = itoa_bit(c);
                            uart_fputc(ch);
                        }
                    }
                    else
                    {
                        unsigned int n = va_arg(arg, unsigned int);
                        int n_bit = udec_bit(n);
                        if(n == 0)
                        {
                            uart_fputc('0');
                            break;
                        }
                        while(num_bit > n_bit)
                        {
                            if(zero_set == 1)
                                uart_fputc('0');
                            else
                                uart_fputc(' ');
                            
                            num_bit--;
                        }
                        
                        for(; n_bit > 0; n_bit--)
                        {
                            char ch;
                            int c = n / npow(10, n_bit - 1);
                            n -= c * npow(10, n_bit - 1);
                            if(c < 0) c = -c;
                            if(c > 9 || c < 0)
                            {
                                __dprintf("[ERR][dprintf] dprintf has a calculate Error\n");
                                c = 0;
                            }
                            ch = itoa_bit(c);
                            uart_fputc(ch);
                        }
                    }
                    break;
                }
                case 'x':
                {
                    if(num_long == 2)
                    {
                        unsigned long long int n = va_arg(arg, unsigned long long int);
                        int n_bit = hex_bit(n);
                        if(n == 0)
                        {
                            uart_fputc('0');
                            break;
                        }
                        while(num_bit > n_bit)
                        {
                            if(zero_set == 1)
                                uart_fputc('0');
                            else
                                uart_fputc(' ');
                            
                            num_bit--;
                        }
                        
                        for(; n_bit > 0; n_bit--)
                        {
                            char ch;
                            int c = n / npow(16, n_bit - 1);
                            n -= c * npow(16, n_bit - 1);
                            if(c < 0) c = -c;
                            if(c > 15 || c < 0)
                            {
                                __dprintf("[ERR][dprintf] dprintf has a calculate Error\n");
                                c = 0;
                            }
                            ch = itoh_bit(c, 'x');
                            uart_fputc(ch);
                        }
                    }
                    else if(num_long == 1)
                    {
                        unsigned long int n = va_arg(arg, unsigned long int);
                        int n_bit = hex_bit(n);
                        if(n == 0)
                        {
                            uart_fputc('0');
                            break;
                        }
                        while(num_bit > n_bit)
                        {
                            if(zero_set == 1)
                                uart_fputc('0');
                            else
                                uart_fputc(' ');
                            
                            num_bit--;
                        }
                        
                        for(; n_bit > 0; n_bit--)
                        {
                            char ch;
                            int c = n / npow(16, n_bit - 1);
                            n -= c * npow(16, n_bit - 1);
                            if(c < 0) c = -c;
                            if(c > 15 || c < 0)
                            {
                                __dprintf("[ERR][dprintf] dprintf has a calculate Error\n");
                                c = 0;
                            }
                            ch = itoh_bit(c, 'x');
                            uart_fputc(ch);
                        }
                    }
                    else
                    {
                        unsigned int n = va_arg(arg, unsigned int);
                        int n_bit = hex_bit(n);
                        if(n == 0)
                        {
                            uart_fputc('0');
                            break;
                        }
                        while(num_bit > n_bit)
                        {
                            if(zero_set == 1)
                                uart_fputc('0');
                            else
                                uart_fputc(' ');
                            
                            num_bit--;
                        }
                        
                        for(; n_bit > 0; n_bit--)
                        {
                            char ch;
                            int c = n / npow(16, n_bit - 1);
                            n -= c * npow(16, n_bit - 1);
                            if(c < 0) c = -c;
                            if(c > 15 || c < 0)
                            {
                                __dprintf("[ERR][dprintf] dprintf has a calculate Error\n");
                                c = 0;
                            }
                            ch = itoh_bit(c, 'x');
                            uart_fputc(ch);
                        }
                    }
                    break;
                }
                case 'X':
                {
                    if(num_long == 2)
                    {
                        unsigned long long int n = va_arg(arg, unsigned long long int);
                        int n_bit = hex_bit(n);
                        if(n == 0)
                        {
                            uart_fputc('0');
                            break;
                        }
                        while(num_bit > n_bit)
                        {
                            if(zero_set == 1)
                                uart_fputc('0');
                            else
                                uart_fputc(' ');
                            
                            num_bit--;
                        }
                        
                        for(; n_bit > 0; n_bit--)
                        {
                            char ch;
                            int c = n / npow(16, n_bit - 1);
                            n -= c * npow(16, n_bit - 1);
                            if(c < 0) c = -c;
                            if(c > 15 || c < 0)
                            {
                                __dprintf("[ERR][dprintf] dprintf has a calculate Error\n");
                                c = 0;
                            }
                            ch = itoh_bit(c, 'X');
                            uart_fputc(ch);
                        }
                    }
                    else if(num_long == 1)
                    {
                        unsigned long int n = va_arg(arg, unsigned long int);
                        int n_bit = hex_bit(n);
                        if(n == 0)
                        {
                            uart_fputc('0');
                            break;
                        }
                        while(num_bit > n_bit)
                        {
                            if(zero_set == 1)
                                uart_fputc('0');
                            else
                                uart_fputc(' ');
                            
                            num_bit--;
                        }
                        
                        for(; n_bit > 0; n_bit--)
                        {
                            char ch;
                            int c = n / npow(16, n_bit - 1);
                            n -= c * npow(16, n_bit - 1);
                            if(c < 0) c = -c;
                            if(c > 15 || c < 0)
                            {
                                __dprintf("[ERR][dprintf] dprintf has a calculate Error\n");
                                c = 0;
                            }
                            ch = itoh_bit(c, 'X');
                            uart_fputc(ch);
                        }
                    }
                    else
                    {
                        unsigned int n = va_arg(arg, unsigned int);
                        int n_bit = hex_bit(n);
                        if(n == 0)
                        {
                            uart_fputc('0');
                            break;
                        }
                        while(num_bit > n_bit)
                        {
                            if(zero_set == 1)
                                uart_fputc('0');
                            else
                                uart_fputc(' ');
                            
                            num_bit--;
                        }
                        
                        for(; n_bit > 0; n_bit--)
                        {
                            char ch;
                            int c = n / npow(16, n_bit - 1);
                            n -= c * npow(16, n_bit - 1);
                            if(c < 0) c = -c;
                            if(c > 15 || c < 0)
                            {
                                __dprintf("[ERR][dprintf] dprintf has a calculate Error\n");
                                c = 0;
                            }
                            ch = itoh_bit(c, 'X');
                            uart_fputc(ch);
                        }
                    }
                    break;
                }
                case '%':
                {
                    uart_fputc('%');
                    break;
                }
                default:
                {
                    zero_set = 0;
                    num_bit = 0;
                    num_long = 0;
                    break;
                }
            }
        }
        else
        {
            if(*format == '\n' && *(format - 1) != '\r')
            {
                uart_fputc('\r');
            }
            uart_fputc(*format);
        }
        
        format++;
    }
    va_end(arg);
}