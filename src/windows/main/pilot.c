#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tsimple.h"

#define SE(a, b) strcmp(a, b)

int main(int argc, char *argv[])
{
	FILE *input;
	char *fname, *buffer;
	long fsize;
	int res;

	fname = NULL;
	if (argc == 2)
		fname = argv[1];
	else {
		fprintf(stdout, "%s\n", print_help(argc));
		return EXIT_FAILURE;
	}
	if ((input = fopen(fname, "rb")) == NULL) {
		perror("fopen err");
		return EXIT_FAILURE;
	}
	fseek(input, 0, SEEK_END);
	if ((buffer = malloc(sizeof(char) * (fsize = ftell(input)))) == NULL) {
		perror("malloc err");
		return EXIT_FAILURE;
	}
	rewind(input);
	if ((res = fread(buffer, 1, fsize, input)) < fsize) {
		if (ferror(input)) {
			perror("fread err");
			return EXIT_FAILURE;
		} else {
			fprintf(stderr, "fread early EOF");
			return EXIT_FAILURE;
		}
	}
	if (!binarytobinary(buffer))
		return EXIT_FAILURE;
	free(buffer);
	fclose(input);
	return 0;
}

char *print_help(int argc) 
{
	return "GYATTT";

}
