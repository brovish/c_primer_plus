#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	
	int i, times;
	
	times = atoi(argv[1]);
	
	if (argc < 2 || (times < 1))
		printf("Usage: %s positive number\n", argv[0]);
	else
		for (i = 0; i < times; i++)
			puts("Hello, good looking!");  
	
	return 0;	
}