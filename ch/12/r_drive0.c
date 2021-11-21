#include <stdio.h>
extern int rand0(void);
extern void srand1(unsigned int x);
int main(void)
{
	int count;
	unsigned int seed;
	
	printf("Please enter your choise for seed:\n");
	while (scanf("%d", &seed) == 1)
	{	
		srand1(seed);
		for (count = 0; count < 15; count++)
		{
			printf("%d\n", rand0());
		}
		printf("Please enter your choise for seed:\n");
	}	
	puts("Done.");	
	return 0;
}
