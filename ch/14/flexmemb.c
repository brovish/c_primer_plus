#include <stdio.h>
#include <stdlib.h>

struct flex {
	size_t count;
	double average;
	double scores[];
};

void showFlex(const struct flex * fl);

int main(void)
{
	
	struct flex *pf1, *pf2;
	int n = 5;
	int tot = 0;
	int i;
	
	pf1 = malloc(sizeof(struct flex) + n * sizeof(double));
	
	pf1->count = n;
	
	for (i = 0; i < n; i++)
	{
		pf1->scores[i] = 20.0 - i;
		tot += pf1->scores[i];
	}
	
	pf1->average = tot/n;
		
	showFlex(pf1);	
	
	tot = 0;
	n = 19;
	
	pf2 = malloc(sizeof(struct flex) + n * sizeof(double));
	
	pf2->count = n;
	
	for (i = 0; i < n; i++)
	{
		pf2->scores[i] = 20.0 - i;
		tot += pf2->scores[i];
	}
	
	pf2->average = tot/n;
		
	showFlex(pf2);
	
	free(pf1);
	free(pf2);
		
	return 0;
}

void showFlex(const struct flex * fl)
{
	int i;
	printf("Score : ");
	for (i = 0; i < fl->count; i++)
		printf("%g ", fl->scores[i]);
	printf("\nAverage: %g\n", fl->average);
}