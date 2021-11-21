#include <stdio.h>
#define MAXLEN 50

struct funds {
	char bank[MAXLEN];
	double bankfund;
	char save[MAXLEN];
	double savefund;
};

double sum(struct funds moolah);
struct funds modify(struct funds moolah);

int main(void)
{

	struct funds stan = {
		"Garlic-Melon Bank",
		4032.27,
		"Lucky's Saving and Loan",
		8543.94
	};
	
	printf("Stan now has a total %.2f.\n", 
		sum(stan));
	
	stan = modify(stan);
	
	printf("And now Stan has a total %.2f.\n", 
		sum(stan));
		
	return 0;
	
}

struct funds modify(struct funds moolah)
{
	moolah.bankfund /= 3;
	return moolah;
	//printf("%.f %.f\n", ptr->bankfund, moolah.bankfund);
}

double sum(const struct funds moolah)
{
	return (moolah.bankfund + moolah.savefund);
}