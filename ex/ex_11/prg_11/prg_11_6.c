#include <stdio.h>
#include <string.h>
#define LIM 100
int is_within(char * str, char ch);
char * s_gets(char *str, int n);

int main(void)
{
	char words[LIM];
	char ch;
	
	
	printf("Enter searh char (# to exit):\n");
	
	while ((ch = getchar()) != EOF && ch != '#')
	{
		while (getchar() != '\n')
			continue;
			
		printf("Enter searh string:\n");	
		
		s_gets(words, LIM);
		printf("input string:[%s]\n", words);
		if (is_within(words, ch))
			printf("[%c] char is in input string:[%s]\n", ch, words);
		else
		{
			printf("no [%c] char in input string:[%s]\n", ch, words);
		}
		
		printf("Enter searh char (# to exit):\n");
	}
		
	//puts(words);
	
	return 0;
}

int is_within(char * str, char ch)
{
	while(*str)
	{
		
		if (*str == ch)
		{	
			return 1;
		}
		str++;
	}
	return 0;
}

char * s_gets(char *str, int n)
{
	
	fgets(str, n, stdin);
	char *find;
	find = strchr(str, '\n');
	if (*find)
		*find = 0;
	return str;	
}