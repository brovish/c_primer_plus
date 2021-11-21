#include <stdio.h>
#define FMT 5280
#define FEET 4
#define POD FEET + FEET
#define SIX 6
#define NEW(X) ((X) + 5)
int main(void)
{
	//a
	int miles = 100;
	int dist = FMT * miles;	
	printf("dist=%d\n", dist);
	
	//b
	int plort = FEET * POD;
	printf("plort=%d\n", plort);
	
	//c
	int nex = SIX;
	printf("nex=%d\n", nex);
	
	//d
	int y = 0;
	int berg = 0; 
	int est = 0; 
	int nilp = 0;
	int lob = 3;
	y = NEW(y);
	berg = NEW(berg) * lob;
	est = NEW(berg) / NEW(y);
	nilp = lob * NEW(-berg);
	
	printf("y=%d;berg=%d;est=%d;nilp=%d\n",
		y, berg, est, nilp);
	
	
	return 0;
}