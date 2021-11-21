#include <stdio.h>
#include <time.h>
#include <stdbool.h>

void pause(double);

int main(void)
{

	double sec;
	int rv = 1;
	
	puts("Enter pause lenght in seconds: (q to quit)");
	
	while (true)
	{
		rv = scanf("%lf", &sec);
		if (rv)
		{	
			fprintf(stdout, "pause for %.2f seconds..", sec); 
			pause(sec);
			puts("Enter next pause: (q to quit)");
		}
		else break;
		
	}
		
	return 0;
}

void pause(double sec)
{
	clock_t start = clock();
	clock_t current;
	do 
	{
		current = clock();
	} while (((double)(current-start)/CLOCKS_PER_SEC) < sec);
	puts("done.");
}