#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXLEN 255

char * s_gets(char *str, FILE *fp, int len);

int main(void)
{
	char source[MAXLEN];
	char target[MAXLEN];
	int ch;
	
	
	FILE *fs, *ft;
	
	printf("Enter source file: ");
	scanf("%s", source);
	
	if ((fs = fopen(source, "r")) == NULL)
	{
		fprintf(stderr, "Can't open source %s\n", source);
		exit(EXIT_FAILURE);
	}
	
	printf("Enter destination file: ");
	scanf("%s", target);
	
	//printf("target=%s;source=%s\n", target, source);
	
	if ((ft = fopen(target, "w")) == NULL)
	{
		fprintf(stderr, "Can't open target %s\n", target);
		exit(EXIT_FAILURE);
	}
	
	if (strcmp(source, target) == 0)
	{
		fprintf(stderr, "Can't copy source file %s to itself.\n" ,
			source);
		exit(EXIT_FAILURE);		
	}
	
	while ((ch = getc(fs)) != EOF)
	{
		fprintf(ft, "%c", toupper(ch));
		//printf("ch = %c", ch);
	}
	
	if (fclose(fs) != 0 || fclose(ft) != 0)
		fprintf(stderr, "Error in closing files\n");
	
	return 0;
}

char * s_gets(char *str, FILE *fp, int len)
{
	char * ret_val;
	char * find;
	ret_val = fgets(str, len, fp);
	if (ret_val)
	{
		find = strchr(str, '\n');
		if (find)
			*find = 0;
	}
	
	return ret_val;
}