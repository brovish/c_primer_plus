#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 255

char * s_gets(char * str, int len, FILE *fp);

int main(int argc, char **argv)
{
	
	FILE *fp;
	char str[MAX];
	char * ptr = str;
	
	if (argc < 3)
	{
		fprintf(stderr, "Usage: %s [searh string] [file name]\n", 
			*argv);
		exit(EXIT_FAILURE);
	}
		
	if ((fp = fopen(*(argv+2), "r")) == NULL)
	{
		fprintf(stderr, "Can't open file %s.\n", *(argv+2));
		exit(EXIT_FAILURE);
	}
	
	while ((ptr = s_gets(str, MAX, fp)) != 0)
	{
		//printf("%s", ptr);
		if (strstr(ptr, *(argv+1)))
			fputs(ptr, stdout);
	}
	
	return 0;
}

char * s_gets(char * str, int len, FILE *fp)
{
	char * ret_val;
	ret_val = fgets(str, len, fp);
	return ret_val;	

}