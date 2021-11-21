#include <stdio.h>
#include <stdalign.h>
int main(void)
{
	
	double dx;
	char ca;
	char cx;
	double dz;
	char cb;
	char alignas(double) cz;
	
	printf("char alignment:\t %zd\n", alignof(char));
	printf("double alignment:\t%zd\n", alignof(double));
	printf("&dx:\t\t %p\n", &dx);
	printf("&ca:\t\t %p\n", &ca);
	printf("&cx:\t\t %p\n", &cx);
	printf("&dz:\t\t %p\n", &dz);
	printf("&cb:\t\t %p\n", &cb);
	printf("&cz:\t\t %p\n", &cz);
	
	return 0;
}