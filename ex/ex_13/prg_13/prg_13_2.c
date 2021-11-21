#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CNTL_Z '\032'

int main(int argc, char **argv)
{
	
	
	FILE *fs, *ft;
	long last, cnt;
	char ch = 0;
	
	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s [file source] "
			"[file copy]\n", *argv);
		exit(EXIT_FAILURE);
	}
	
	if (strcmp(argv[1], argv[2]) == 0)
	{
		fprintf(stderr, "Can't copy file to itself.\n");
		exit(EXIT_FAILURE);
	}
	
	if ((fs = fopen(argv[1], "rb")) == NULL)
	{
		fprintf(stderr, "Can't open source file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	
	if ((ft = fopen(argv[2], "wb")) == NULL)
	{
		fprintf(stderr, "Can't open target file %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	
	fseek(fs, 0L, SEEK_END);
	last = ftell(fs);
	rewind(fs);	
	
	for (cnt = 1L; cnt <= last && (ch = getc(fs)) != EOF; cnt++)
	{
		
		fseek(fs, cnt, SEEK_SET);
		if (ch != CNTL_Z && ch != '\r')
		{
			//printf("ch=%c\n", ch);
			fwrite(&ch, sizeof(char), 1, ft);
		}
		
	}
	
	if (fclose(fs) != 0 || fclose(ft) != 0)
		fputs("Can't close files.", stderr);
		
	return 0;
}