#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void read_word(char *, int);
int main(int argc, char *argv[])
{
	
	int n = atoi(argv[1]);
	if (argc < 2 || n < 1)
		printf("Usage: %s positive number\n", argv[0]);
	else
	{
		char words[n];
		char *ptr = words;
	
		read_word(ptr, n);
		printf("Words:[%s]\nMax chars to read:[%d]\n", words, n);	
	}	
	return 0;
}

void read_word(char *str, int n)
{
	char ch;
	int i = 0;
	int inword = 0;
	while ((ch = getchar()) != EOF)
	{
		
		if ((!isalnum(ch) && inword) || (i >= n))
		{
			*str = 0;
			break;
		}
		
		if (isalnum(ch))
		{
			inword = 1;
			*str = ch;
			++str; 
			i++;
		}
	}
}


