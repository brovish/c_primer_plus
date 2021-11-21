#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	double *ptr;
	int max = 0;
	int number;
	int i = 0;
	
	puts("What is the maximum number of type double entries?");
	if (scanf("%d", &max) != 1)
	{
		printf("Number not correctly entered.\n"
		"Bye!\n");
		exit(EXIT_FAILURE);
	}
	
	ptr = (double *) malloc(max * sizeof(double));
	
	if (ptr == NULL)
	{
		printf("Memory allocation failed.\n"
		"Bye!\n");
		exit(EXIT_FAILURE);
	}
	
	puts("Enter the values (q to exit).");
	
	while (i < max && scanf("%lf", &ptr[i]) == 1)
		++i;
	printf("Here are your %d entries:\n", number = i);
	
	for (i = 0; i <number; i++)
	{
		printf("%7.2f ", ptr[i]);
		if (i % 7 == 6)
			putchar('\n');
	}
	
	if (i % 7 != 0)
		putchar('\n');
	puts("Done.");
	free(ptr);
	
	return 0;
}