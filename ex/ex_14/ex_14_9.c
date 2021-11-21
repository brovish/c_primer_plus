#include <stdio.h>
int main(void)
{
	typedef struct car {
		char name[100];
		int hpower;
		int mpg;
		float wheelbase;
		int year;
	} machine;
	
	machine man = {"BMW", 150, 25, 29.54, 1954};
	
	printf("%s\nPOWER=%d\nMPG=%d\nWHEELBASE=%.2f\nYEAR=%d\n", 
	man.name, man.hpower, man.mpg, man.wheelbase, man.year);
	
	return 0;
}