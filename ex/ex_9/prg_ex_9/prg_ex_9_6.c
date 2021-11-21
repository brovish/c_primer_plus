#include <stdio.h>
void reversed(double *x, double *y, double *z);
int main(void)
{
    double x, y, z;
    while (scanf("%lf %lf %lf", &x, &y, &z) == 3)
    {
	//printf("%lf %lf %lf\n", x, y, z);
	reversed(&x,&y,&z);
	if (!(x <= y && y <= z))
	{
	    printf("err!\t");
	    printf("%.0lf %.0lf %.0lf\n", x, y, z);
	}
    }
    return 0;
}

void reversed(double *x, double *y, double *z)
{
    double t;
    if(*x < *y && *x < *z && *y < *z)
	;
    if(*x < *y && *x < *z && *y > *z)
    {
	t = *z;
	*z = *y;
	*y = t;
    }
    
    if(*y < *x && *y < *z && *x < *z)
    {
	t = *x;
	*x = *y;
	*y = t;
    }
    
    if(*y < *x && *y < *z && *x > *z)
    {
	t = *x;
	*x = *y;
	*y = t;
	t = *y;
	*y = *z;
	*z  = t;
    }

    if(*z < *x && *z < *y && *x > *y)
    {
	t = *x;
	*x = *z;
	*z = t;
    }
    
    if(*z < *x && *z < *y && *x < *y)
    {
	t = *x;
	*x = *z;
	*z = t;
	t = *z;
	*z = *y;
	*y = t;
    }
    
    if (*x == *y && *z < *x)
    {
	*x = *z;
	*z = *y;
    }
    
    if (*y == *z && *x > *y)
    {
	*z = *x;
	*x = *y;
    }
    
    if (*x == *z && *y > *x)
    {
	*z = *y;
	*y = *x;
    }
    
    if (*x == *z && *y < *x)
    {
	*x = *y;
	*y = *z;
    }
    
}