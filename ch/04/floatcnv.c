#include <stdio.h>
int main(void)
{

	float n1 = 3.0;
	double n2 = 3.0;

	long n3 = 2000000000;
	long n4 = 1234567890;
	
	int rv;

	printf("%.1e %.1e %.1e %.1e\n", n1, n2, n3, n4);
	printf("%ld %ld\n", n3, n4);
	rv = printf("%ld %ld %ld %ld\n", n1, n2, n3, n4);

	printf("%d \n", rv);

	return 0;
}
