#include <stdio.h>
#define FUNDLEN 50

double sum(double, double);
void modify(double *);
struct fund {
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};

int main(void)
{
	
	struct fund stan = {
		"Garlic-Melon Bank",
		4032.27,
		"Lucky's Saving and Loans",
		8543.94
	};
	
	printf("Stan has a total of %.2f.\n", 
		sum(stan.bankfund, stan.savefund));
	
	modify(&stan.bankfund);
	
	printf("Now Stan has a total of %.2f.\n", 
		sum(stan.bankfund, stan.savefund));
	
	
	return 0;
}

void modify(double * val)
{
	*val = (double) *val / 3;
}

double sum(double x, double y)
{
	return (x + y);
}