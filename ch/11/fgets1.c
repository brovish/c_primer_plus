#include <stdio.h>
#define STRLEN 14
int main(void)
{
	char words[STRLEN];
	
	puts("Enter a string, please:");
	fgets(words, STRLEN, stdin);
	printf("Your string twice (puts(), fputs()):\n");
	puts(words);
	fputs(words, stdout);
	
	puts("Enter another string, please:");
	
	fgets(words, STRLEN, stdin);
	printf("Your string twice (puts(), fputs()):\n");
	puts(words);
	fputs(words, stdout);
	
	puts("Done.");
	
	
	return 0;
}