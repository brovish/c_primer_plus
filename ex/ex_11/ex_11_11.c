#include <stdio.h>
#include <string.h>
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

char * s_gets(char * st, int n)
{
	/*
	char * ret_val;
	//int i = 0;
	ret_val = fgets(st, n, stdin);
	char *find;
		
	if (ret_val)
	{
		find = strchr(ret_val, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
		
	}
	
	return ret_val;
	*/
	
	fgets(st, n, stdin);
	char *find;
	find = strchr(st, '\n');
		if (find)
			*find = '\0';
	//while (getchar() != '\n')
	//		continue;
		
	return st;
}

char * s_gets2(char * st, int n)
{
	char * ret_val;
	int i = 0;
	ret_val = fgets(st, n, stdin);
		
	if (ret_val)
	{
		while (st[i] != '\0' && st[i] != '\n')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	
	return ret_val;
}