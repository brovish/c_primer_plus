#include <stdio.h>
#include <stdlib.h>
#define MAX 255

int main(void)
{
	char fname[MAX];
	FILE *fp;
	long pos;
	long last;
	char ch = 0;
	puts("Enter file name: ");
	scanf("%s", fname);
	
	if ((fp = fopen(fname, "rb")) == NULL)
	{
		fprintf(stderr, "Can't open file %s.\n", fname);
		exit(EXIT_FAILURE);
	}
	
	fseek(fp, 0L, SEEK_END);
	last = ftell(fp);
	rewind(fp);
	
	printf("Enter position: (max: %ld) ", last);
	
	while (scanf("%ld", &pos) == 1 && pos >= 0 && pos <= last)
	{
		fseek(fp, pos, SEEK_SET);
		while ((ch = getc(fp)) != EOF)
		{
			fputc(ch, stdout);
			if (ch == '\n')
				break;
		}
		rewind(fp);
		printf("Enter position: (max: %ld) ", last);
	}
	
	return 0;
}