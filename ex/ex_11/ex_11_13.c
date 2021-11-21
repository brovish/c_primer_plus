#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 40
#define ANSWER "GRANT"
char * s_gets(char *, int);
int main(void)
{
	char try[SIZE];
	puts("Who is buried in Grant's tomb?");
	
	s_gets(try, SIZE);
	
	while (strcmp(try, ANSWER))
	{
		puts("No, that's wrong. Try againt.");
		s_gets(try, SIZE);
	}
	
	puts("That's right!");
	
	return 0;
}

char * s_gets(char * string, int n)
{
	char *ret_val;
	int i = 0;
	
	ret_val = fgets(string, SIZE, stdin);
	if (ret_val)
	{
		while(string[i] != '\n' && string[i] != '\0')
		{
			string[i] = toupper(string[i]);
			i++;
		}
		if (string[i] == '\n')
			string[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	
	return ret_val;
}