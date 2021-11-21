#include <stdio.h>
#define MAXLEN 50

struct funds {
	char bank[MAXLEN];
	double bankfund;
	char save[MAXLEN];
	double savefund;
};

double sum(const struct funds *);
void modify(struct funds *);

int main(void)
{

	struct funds stan = {
		"Garlic-Melon Bank",
		4032.27,
		"Lucky's Saving and Loan",
		8543.94
	};
	
	printf("Stan now has a total %.2f.\n", 
		sum(&stan));
	
	modify(&stan);
	
	printf("And now Stan has a total %.2f.\n", 
		sum(&stan));
		
	return 0;
	
}

void modify(struct funds * money)
{
	money->bankfund /= 3;
}

double sum(const struct funds * money)
{
	return (money->bankfund + money->savefund);
}