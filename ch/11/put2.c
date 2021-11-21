#include <stdio.h>

int put2(const char *);

int main(void)
{
	put2("Put me please!");
	puts("Put me again with new line,");
	
	int count = put2("Put this againt with no new line,");
	printf("count of puting chars:%d\n", count);
	
	return 0;
}

int put2(const char *string)
{
	int count = 0;
	
	while (*string)
	{
		putchar(*string++);
		count++;
	}
	
	return count;
}