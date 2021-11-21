#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFSIZE 4096
#define SLEN 255

void append(FILE *source, FILE *dest);

int main(int argc, char **argv)
{
	
	if (argc < 3)
	{
		fprintf(stderr, "Usage %s [file append] [list of source files]\n", 
			*argv);
		exit(EXIT_FAILURE);
	}
	
	FILE *fa, *fs;
	int files = 0;
	int ch;
	if ((fa = fopen(*(argv + 1), "a+")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", *(argv+1));
		exit(EXIT_FAILURE);
	}
	
	if (setvbuf(fa, NULL, _IOFBF, BUFFSIZE) != 0)
	{
		fputs("Can't create output buffer\n", stderr);
		exit(EXIT_FAILURE);
	}
	
	for (int i = 2; (i < argc) && *(argv+i) != 0; i++)
	{
		if (strcmp(*(argv+1), *(argv+i)) == 0)
			fputs("Can't append file to itself\n", stderr);
		else if ((fs = fopen(*(argv+i), "r")) == NULL)
			fprintf(stderr, "Can't open %s file\n", 
				*(argv+i));
		else
		{
			if (setvbuf(fa, NULL, _IOFBF, BUFFSIZE) != 0)
			{
				fputs("Can't create input buffer\n", stderr);
				exit(EXIT_FAILURE);
				continue;
			}
			append(fs, fa); 
			if (ferror(fs) != 0)
				fprintf(stderr, "Error in reading file %s\n", 
					*(argv+i));
			if (ferror(fa) != 0)
				fprintf(stderr, "Error in reading file %s\n", 
					*(argv+i));
			if (fclose(fs) != 0)
				fprintf(stderr, "Error closing file %s\n", *(argv+i));
			files++;
			printf("File %s appended.\n", *(argv+i));
			puts("Next file (empty line to quit)");			
		}
		
		
	}
	
	printf("Done appending. %d files appended\n", files);
	rewind(fa);
	printf("%s contents:\n", *(argv+1));
	while ((ch = getc(fa)) != EOF)
		putchar(ch);
	
	if (fclose(fa) != 0)
		fprintf(stderr, "Error closing file %s\n", *(argv+1));
	
	return 0;
}


void append(FILE *source, FILE *dest)
{
	size_t bytes;
	static char temp[BUFFSIZE];
	while ((bytes = fread(temp, sizeof(char), BUFFSIZE, source)) > 0)
		fwrite(temp, sizeof(char), bytes, dest);
}