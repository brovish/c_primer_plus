#include <stdio.h>
#include <string.h>
#define SIZE 40
#define WORDS "beast"

char * s_gets(char *, int);

int main(void)
{
	const char *orig = WORDS;
	char copy[SIZE] = "Be the best than you can be.";
	char *ps;
	
	puts(orig);
	puts(copy);
	
	ps = strcpy(copy + 7, orig);
	puts(copy);
	puts(ps);

	return 0;
}
