#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	
	int ch = 0;
	FILE *fp;
	
	if (argc < 2)
		exit(EXIT_FAILURE);
	
	printf("%s\n", argv[1]);
	
	while ((fp = fopen(argv[1], "r")) == NULL )
		exit(EXIT_FAILURE);
	while ((ch = getc(fp)) != EOF)
	{
		if (isdigit(ch))
		{
			putchar('\n');
			putchar(ch);
		
		}
	}
	fclose(fp);
	
	return 0;
}