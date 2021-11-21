#include <stdio.h>

void large_of(double *x, double *y);
int main(void)
{
    double x, y;
    while (scanf("%lf %lf", &x, &y) == 2)
    {
	printf("%lf (%p) | %lf (%p)\n", x, &x, y, &y);
	large_of(&x, &y);
	printf("%lf (%p) | %lf (%p)\n", x, &x, y, &y);
    }
    
    return 0;
}

void large_of(double *x, double *y)
{
    if (*x>*y)
	*y=*x;
    else 
	*x=*y;
}