#include <stdio.h>

double fn1(double, double);
double fn2(double, double);
double fn3(double, double);
double fn4(double, double);

int main(void)
{
	
	double (*arr[4])(double, double);
	arr[0] = fn1;
	arr[1] = fn2;
	arr[2] = fn3;
	arr[3] = fn4;
	
	printf("%f\n", arr[0](10.0, 2.5));
	printf("%f\n", arr[1](10.0, 2.5));
	printf("%f\n", arr[2](10.0, 2.5));
	printf("%f\n", arr[3](10.0, 2.5));
	
	typedef double (*ptype)(double, double);
	ptype arr2[4] = {fn1, fn2, fn3, fn4};
	
	printf("%f\n", (*arr2[0])(10.0, 2.5));
	printf("%f\n", (*arr2[1])(10.0, 2.5));
	printf("%f\n", (*arr2[2])(10.0, 2.5));
	printf("%f\n", (*arr2[3])(10.0, 2.5));
		
	return 0;
}

double fn1(double d1, double d2)
{
	return d1 + d2;
}

double fn2(double d1, double d2)
{
	return d1 / d2;
}

double fn3(double d1, double d2)
{
	return d1 * d2;
}

double fn4(double d1, double d2)
{
	return d1 - d2;
}
