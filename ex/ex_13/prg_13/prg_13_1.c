#include <stdio.h>
#include <stdlib.h>
#define MAXLENG 255

int main(int argc, char **argv)
{
	int ch;
	FILE *fp;
	unsigned long count = 0;
	char filename[MAXLENG];
	/*
	int code = 0;
	
	if (argc != 2)
	{
		printf("Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	*/
	
	printf("Enter file name:\n");
	
	scanf("%s", filename);
	//printf("code=%d\n");
	/*
	if (!code)
	{
		printf("Can't read filename.\n");
		exit(EXIT_FAILURE);
	}	
	*/
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	
	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		count++;
	}
	
	fclose(fp);
	
	printf("File %s has %lu characters\n", filename, count);
	
	return 0;
}