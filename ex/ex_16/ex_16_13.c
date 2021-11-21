#include <stdio.h>
#include <stdlib.h>

#define NUM 100

int comp(const void *, const void *);

int main(void)
{
	
	int ar[NUM];
	int i = 0;
	
	for (; i < NUM; i++)
	{
		ar[i] = i;	
	}
	
	for (i = 0; i < NUM; i++)
	{
		
		printf("%3d ", ar[i]);
		if (i % 20 == 19)
			putchar('\n');
		
	}
	
	putchar('\n');
	putchar('\n');
	
	qsort(ar, NUM, sizeof(int), comp);
	
	for (i = 0; i < NUM; i++)
	{
		printf("%3d ", ar[i]);
		if (i % 20 == 19)
			putchar('\n');	
	}
	
	putchar('\n');
	
	return 0;
}

int comp(const void * p1, const void * p2)
{
	const int * a1 = (const int *) p1;	
	const int * a2 = (const int *) p2;
	
	if (*a1 > *a2)
		return -1;
	else if (*a1 == *a2)
		return 0;
	else return 1;
}