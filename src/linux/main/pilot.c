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
	bool ishex;

	fname = NULL;
	if (argc == 3) {
		if (argv[1][0] != '-' && argv[2][0] != '-') {
			fprintf(stdout, "%s\n", print_help(argc));
			return EXIT_FAILURE;
		}
		if (SE(argv[1], "-bin") == 0) {
			fname = argv[2];
			ishex = false;
		} else if (SE(argv[2], "-bin") == 0) {
			fname = argv[1];
			ishex = false;
		} else if (SE(argv[1], "-hex") == 0) {
			fname = argv[2];
			ishex = true;
		} else if (SE(argv[2], "-hex") == 0) {
			fname = argv[1];
			ishex = true;
		}
	} else if (argc == 2) {
		if (argv[1][0] == '-') {
			fprintf(stdout, "%s\n", print_help(argc));
			return EXIT_FAILURE;
		}
		fname = argv[1];
		ishex = true;
	} else {
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
	if (ishex) {
		if (!hextobinary(buffer, strlen(buffer)))
			return EXIT_FAILURE;
	} else {
		if (!binarytobinary(buffer, strlen(buffer)))
			return EXIT_FAILURE;
	}
	free(buffer);
	fclose(input);
	return 0;
}

char *print_help(int argc) {

	return "GYATTT";

}
