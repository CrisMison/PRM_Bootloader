#ifndef _RM_LIBFUC_H_
#define _RM_LIBFUC_H_

void rm_memset(void *p, unsigned int val, unsigned int length);
void rm_strncpy(void* dst, void* src, int len);
int  rm_strlen(void* dst);
#endif