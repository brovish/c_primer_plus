#include <stdio.h>
#define MAXSIZE 100
void fetch_n(char *, int n);
int main(int argc, char *argv[])
{
	
	int n;
	n = atoi(argv[1]);
	if (argc < 2 || n < 1)
		printf("Usage %s positive numbrer\n", argv[0]);
	else
	{
		char words[MAXSIZE];
		char *ptr = words;
		fetch_n(ptr, n);
		printf("Words: [%s]\nChars to read:[%d]\n"
			, words, n);
	}	
	return 0;
}

void fetch_n(char *str, int n)
{
	char ch;
	int i = 0;
	
	while ((ch = getchar()) != EOF)
	{
		if (i < n)
		{
			str[i] = ch;
		}
		i++;
	}
	str[i] = 0;
}
