#include <stdio.h>
#include <string.h>
#include "tsimple.h"

uint8_t masks[] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 };
int buflen = 0;

bool binarytobinary(char *buf, size_t len)
{
	FILE *output;
	uint8_t bytebuf[len];
	uint8_t chomp;

	memset(bytebuf, 0, sizeof(bytebuf));
	if ((output = fopen(OUTPUT, "wb")) == NULL) {
		perror("fopen err");
		return false;
	}
	buflen = 0;
	chomp = 0x00;
	for (int i = 0, ind = 0, octet = 7; i < len; i++) {
		if (octet == -1) {
			bytebuf[ind++] = chomp;
			chomp = 0x00;
			octet = 7;
			buflen++;
		}
		if (buf[i] == '0')
			octet--;
		else if (buf[i] == '1')
			chomp |= masks[octet--];
	}
	fwrite(bytebuf, buflen, 1, output);
	fclose(output);
	return true;
}

bool hextobinary(char *buf, size_t len) { return true; }
