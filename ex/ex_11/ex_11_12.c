#include <stdio.h>
char * is_space(char *str);
int main (void)
{
	char words[] = "Maxim max";
	puts(words);
	char *ptr;
	ptr = is_space(words);
	if (ptr)
		printf("%s\n", ptr);
	
	char words2[] = "max";
	puts(words2);
	char *ptr2;
	ptr2 = is_space(words2);
	if (ptr2)
		printf("%s\n", ptr2);
	
	return 0;
}

char * is_space(char *str)
{
	while(*str)
	{
		if (*str == ' ')
		return ++str;
		++str;
	}
	
	return 0;
}