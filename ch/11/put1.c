#include <stdio.h>
void put1(const char *);

int main(void)
{
	put1("Put me please!");
	puts("Put me please! again with new line.");
	
	puts("Done");
	
	return 0;
}

void put1(const char *string)
{
	while (*string)
		putchar(*string++);	
}