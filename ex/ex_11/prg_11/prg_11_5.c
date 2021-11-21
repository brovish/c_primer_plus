#include <stdio.h>
char * strchr2(char * str, char ch);
int main(void)
{
	char words[] = "Mamamia Biden is worst president in history.";
	char ch;
	printf("input string:[%s]\n", words);
	char *ptr;
	
	printf("Enter searh char (q to exit):\n");
	
	while ((ch = getchar()) != EOF && ch != 'q')
	{
		while (getchar() != '\n')
			continue;
		ptr = strchr2(words, ch);
		if (*ptr)
			printf("first [%c] char in input string:[%s]\n", ch, ptr);
		else
		{
			printf("no [%c] char in input string:[%s]\n", ch, words);
		}
	}
		
	//puts(words);
	
	return 0;
}

char * strchr2(char * str, char ch)
{
	while(*str)
	{
		
		if (*str == ch || !*str)
		{	
			return str;
		}
		str++;
	}
	
	return str;
}
