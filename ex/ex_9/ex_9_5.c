#include <stdio.h>
double sum(double,double);
int main(void)
{
    double x, y, z = 0;
    scanf("%lf %lf", &x, &y);
    
    z = sum(x, y);
    
    printf("%lf+%lf=%lf\n", x, y, z);
    
    return 0;
}

double sum(double x, double y)
{
    return x + y;
}