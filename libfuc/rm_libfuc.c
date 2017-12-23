#include "rm_libfuc.h"

void rm_memset(void *s, unsigned int val, unsigned int length)
{
    char *p = (char*)s;
    unsigned int i = 0;
    for(i = 0; i < length; i++)
    {
        *(p + i) = val;
    }
}

void rm_strncpy(void* dst, void* src, int len)
{
    int i = 0;
    char *p = (char*)dst;
    char *s = (char*)src;
    do
    {
        *p = *s;
        p++; s++; i++;
    }while(i <= len && *s != '\0');
}

int rm_strlen(void* dst)
{
    int i = 0;
    char *p = (char*)dst;
    
    while(*p != '\0')
    {
        i++; p++;
    }
    
    return i;
}