#include <stdio.h>
#define LIM 80
char * s_gets(char *, int);
char * s_gets2(char *, int);

int main(void)
{
	char words[LIM];
	s_gets(words, LIM);
	puts(words);
	
	char words2[LIM];
	s_gets2(words2, LIM);
	puts(words2);
	
	return 0;
}

char * s_gets2(char * st, int n)
{
	char * ret_val;
	char *ptr;
	ret_val = fgets(st, n, stdin);
	ptr = ret_val;
	if (ret_val)
	{
		while (*ptr != '\n' && *ptr != '\0')
			++ptr;
		if (*ptr == '\n')
			*ptr = '\0';
		else 
			while (getchar() != '\n')
				continue;	
	}
	
	return ret_val;

}

char * s_gets(char * st, int n)
{
	char * ret_val;
	int i = 0;
	ret_val = fgets(st, n, stdin);
	
	if (ret_val)
	{
		while (st[i] != '\n' && st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else 
			while (getchar() != '\n')
				continue;	
	}
	
	return ret_val;

}