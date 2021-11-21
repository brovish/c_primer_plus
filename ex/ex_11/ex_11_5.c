#include <stdio.h>
char * pr(char *str);
int main(void)
{
	char *ptr;
	
	ptr = pr("");
	
	return 0;
}

char * pr(char *str)
{
	char *pc;
	pc = str;
	while (*pc)
		putchar(*pc++);
	do {
		putchar(*--pc);
	} while (pc - str);
	puts("");
	return pc;
}