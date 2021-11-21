#include <stdio.h>

double harm_mean(double x, double y);

int main(void)
{
    
    double x, y;
    
    while (scanf("%lf %lf", &x, &y) == 2)
    {
	printf("harmonic mean of %lf and %lf is %lf\n", 
	    x, y, harm_mean(x, y));
    }
    
    return 0;
}

double harm_mean(double x, double y)
{
    return 2/(1/x + 1/y);
}