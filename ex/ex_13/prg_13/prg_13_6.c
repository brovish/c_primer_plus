#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 255
int main(int argc, char **argv)
{
	FILE *in, *out;
	int ch = 0;
	char source[LEN];
	char target[LEN];
	int cnt = 0;
	
	printf("Enter source file name: ");
	scanf("%s", source);
			
	if ((in = fopen(source, "r")) == NULL)
	{
		fprintf(stderr, "Can't open %s filename\n", source);
		exit(EXIT_FAILURE);
	}
	
	printf("Enter target file name: ");
	scanf("%s", target);
	
	if ((out = fopen(target, "w")) == NULL)
	{
		fprintf(stderr, "Can't open %s filename\n", target);
		exit(EXIT_FAILURE);
	}
	
	while ((ch = getc(in)) != EOF)
	{
		if (cnt++ % 3 == 0)
			putc(ch, out);
	}
	
	if (fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr, "Error in closing files.\n");
	
	return 0;
}

