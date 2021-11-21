#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMIT 256
char * s_gets(char * st, FILE *fp, int n);
int main(int argc, char **argv)
{
	
	char words[LIMIT];
	
	if (argc < 3)
	{
		fprintf(stderr, "Usage %s char file\n", *argv);
		exit(EXIT_FAILURE);
	}
	
	FILE *fp;
	
	if ((fp = fopen(argv[2], "r")) == NULL)
	{
		fprintf(stderr, "Can't open file %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	
	char *ptr;
	
	while ((ptr = s_gets(words, fp, LIMIT)) != NULL)	
	{
		char ch = argv[1][0];
		//printf("%c\n", ch);
		char *find;
				
		find  = strchr(ptr, ch);
		if (find)
			printf("%s\n", ptr);
	}
		
	fclose(fp);
	
	return 0;
	
}

char * s_gets(char * st, FILE *fp, int n)
{
	char * ret_val;
        char * find;
        ret_val = fgets(st, n, fp);
        if (ret_val)
        {
                find = strchr(st, '\n');
                if (find)
                        *find = '\0';
                /*else
                        while (getchar() != '\n')
                                continue;*/
        }

        return ret_val;		
}

