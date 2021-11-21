#include <stdio.h>
#include <stdlib.h>
#define DELIM "##################################"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		fprintf(stderr, "Usage %s [list of files]\n", 
			*argv);
		exit(EXIT_FAILURE);
	}
	
	FILE *fp;
	char ch = 0;
	
	int i = 1;
	
	for (; i < argc; i++)
	{
		//printf("i=%d;file=%s\n", i, *(argv+i));
		puts(DELIM);
		
		if ((fp = fopen(*(argv+i), "r")) == NULL)
		{
			fprintf(stderr, "Can't open file %s, skipping it\n", 
				*(argv+i));
			continue;
		}		
		
		fprintf(stdout, "%s contents:\n", *(argv+i));
		while ((ch = getc(fp)) != EOF)
		{
			putchar(ch);
		}
		
		
		if (fclose(fp) != 0)
			fprintf(stderr, "Error closing file %s\n", *(argv+1));		
	}
	
	return 0;
}