#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 100

int main(int argc, char *argv[])
{
	FILE *in, *out;
	char name[LEN];
	int ch;	
	//int count = 0;
	
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename\n", *argv);
		exit(EXIT_FAILURE);
	}
	
	if ((in = fopen(*(argv+1), "r")) == NULL)
	{
		fprintf(stderr, "I couldn't open file \"%s\"\n", *(argv+1));
		exit(EXIT_FAILURE);
	}
	
	strncpy(name, *(argv+1), LEN - 5);
	strcat(name, ".red");
	
	if ((out = fopen(name, "w")) == NULL)
	{
		fprintf(stderr, "Can't create output file.\n");
		exit(EXIT_FAILURE);
	}
	
	while ((ch = getc(in)) != EOF)
		if (isdigit(ch))
			putc(ch, out);
	
	if (fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr, "Error in closing files\n");
	
	return 0;
}