#include <stdio.h>
#include <string.h>
#include "tsimple.h"

BYTE masks[] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 };
int buflen = 0;

bool binarytobinary(char *buf)
{
	FILE *output;
	BYTE bytebuf[strlen(buf)];
	BYTE chomp;

	memset(bytebuf, 0, sizeof(bytebuf));
	if ((output = fopen(OUTPUT, "wb")) == NULL) {
		perror("fopen err");
		return false;
	}
	buflen = 0;
	chomp = 0x00;
	for (int i = 0, ind = 0, octet = 7; i < strlen(buf); i++) {
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
		else if (buf[i] != ' ' && buf[i] != '\t' && buf[i] != '\n') {
			fprintf(stderr, "%s%02X%c\n", "Bad character detected: '0x", buf[i], '\'');
			return false;
		}
	}
	fwrite(bytebuf, buflen, 1, output);
	fclose(output);
	return true;
}
