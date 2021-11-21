#include <stdio.h>
#include <time.h>
extern int rand0(void);
extern void srand1(unsigned int x);
int main(void)
{
	int count;
	//unsigned int seed;
	
	//printf("Please enter your choise for seed:\n");
	//while (1)
	{	
		time_t t;
		time(&t);
		printf("t=%ld\n",t);
		printf("time(0)=%ld\n",time(0));
		srand1((unsigned int) time(0));
		for (count = 0; count < 15; count++)
		{
			printf("%d\n", rand0());
		}
		//printf("Please enter your choise for seed:\n");
	}	
	puts("Done.");	
	return 0;
}
