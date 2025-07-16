#ifndef __TSIMPLE_H__
#define __TSIMPLE_H__

#include <stdbool.h>
#include <stdint.h>

#define OUTPUT "output.bin"

extern bool binarytobinary(char *buffer, size_t siz);
extern bool hextobinary(char *buffer, size_t siz);
char *print_help(int argc);

#endif //__TSIMPLE_H__
