#include <stdio.h>
int put2(const char *);
void put1(const char *);

int main(void)
{

	put1("If i'd as much money");
	put1(" as I could spend,\n");
	printf("I count %d characters.\n", 
		put2("I never would cry old chairs to mend.")
	      );
	return 0;
}


int put2(const char * string)
{

	int count = 0;
	while (*string)
	{
		putchar(*string++);
		count++;
	}
	putchar('\n');	
	return count;
}

void put1(const char * string)
{

	while (*string)
	{
		putchar(*string++);
	}
}
