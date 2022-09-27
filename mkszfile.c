#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

int main(int argc, char **argv)
{
	size_t size = 0;
	int is_mb = 0;
	int is_gb = 0;
	char *output = NULL;
	char *buffer = NULL;
	FILE *fp = NULL;

	int opt = 0;

	while((opt = getopt(argc, argv, "s:f:m:g:")) != -1) {
		switch(opt) {
			case 's': 
				size = strtol(optarg, NULL, 10);
				break;
			case 'f':
				output = optarg;
				break;
			case 'm':
				is_mb = 1;
				break;
			case 'g':
				is_gb = 1;
				break;				
			default:
				printf("makefile -s [size in bytes] -o [output] \n");
		}
	}

	if(output == NULL || size == 0) {
		printf("makefile -s [size in bytes] -o [output] \n");
		return -1;
	}

	if(is_mb == 1) {
		size = size * 1024 * 1024;
	}
	else if(is_gb == 1) {
		size = size * 1024 * 1024 * 1024;
	}

	buffer = malloc(size + 1);

	if(buffer == NULL) {
		fprintf(stderr, "error alloc\n");
		return -1;
	}


	fp = fopen(output, "w");

	if(fp == NULL) {
		fprintf(stderr, "unable to open file\n");
		return -1;
	}

	memset(buffer, 'a', size);

	fprintf(fp, buffer);

	fclose(fp);
	free(buffer);

	return 0;
}