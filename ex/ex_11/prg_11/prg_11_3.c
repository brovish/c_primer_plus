#include <stdio.h>
#include <ctype.h>
#define MAXSIZE 100
void read_word(char *);
int main(int argc, char *argv[])
{
	
	char words[MAXSIZE];
	char *ptr = words;
	
	read_word(ptr);
	printf("Words: %s\n", words);
		
	return 0;
}

void read_word(char *str)
{
	char ch;
	int i = 0;
	int inword = 0;
	while ((ch = getchar()) != EOF)
	{
		if (!isalnum(ch) && inword)
		{
			*str = 0;
			break;
		}
		
		if (isalnum(ch))
		{
			inword = 1;
			*str = ch;
			++str; 
		}
		i++;
	}
}


