#include <stdio.h>
#include <math.h>
#define ELEMENTS 10

double * transform(const double *, double *, int, double (*fp)(double)); 
void init_source(double * source, int num);
void print_arr(double * arr, int num);
double multiple(double val);
double minus10(double val);

int main(void)
{
	int num = ELEMENTS;
	
	double target[num];
	double source[num];
	init_source(source, num);
	
	print_arr(source, num);
	
	double * ptr;
	
	double (*fp)(double);
	
	fp = sin;
	ptr = transform(source, target, num, fp);
	print_arr(ptr, num);
	
	fp = sqrt;
	ptr = transform(source, target, num, fp);
	print_arr(ptr, num);
		
	fp = multiple;
	ptr = transform(source, target, num, fp);
	print_arr(ptr, num);
	
	fp = minus10;
	ptr = transform(source, target, num, fp);
	print_arr(ptr, num);
	
	
	return 0;
}

double * transform(const double * source, 
	double * target, int num, double (*fp)(double))
{
	for (int i = 0; i < num; i++)
	{
		target[i] = (*fp)(source[i]);
	}
	
	return target;
}

void print_arr(double * arr, int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("arr[%d]=%.2f\n", i, arr[i]);
	}
}

double multiple(double val)
{
	return val*val;
}

double minus10(double val)
{
	return val-10;
}

void init_source(double * source, int num)
{
	for (int i = 0; i < num; i++)
	{
		source[i] = (double) (i + 15);
		//printf("%f\n", source[i]);
	} 
}