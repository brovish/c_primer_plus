#include <stdio.h>
int main(int argc, char *argv[])
{
	int count;
	
	printf("The program has %d arguments\n", 
		argc - 1);
	
	for (count = 1; count < argc;count++)
		printf("argument %d = %s\n", 
			count, argv[count]);
	return 0;
}