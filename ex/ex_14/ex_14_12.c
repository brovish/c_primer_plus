#include <stdio.h>
#include <ctype.h>
char * test(char * st);


int main(void)
{
	char * (*fp)(char *) = test; 
	char temp[10] = "Enter";
	printf("%s\n", temp);
	(*fp)(temp);
	printf("%s\n", temp);
	
	return 0;
}

char * test(char * st)
{
	while (*st)
	{
		*st=toupper(*st);
		st++;
	}
	return st;
}

