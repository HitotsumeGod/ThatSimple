#ifndef __TSIMPLE_H__
#define __TSIMPLE_H__

#include <windows.h>

#define SE(a, b) strcmp(a, b)

#define OUTPUT "output.bin"

extern bool binarytobinary(char *buffer);
char *print_help(int argc);

#endif //__TSIMPLE_H__
