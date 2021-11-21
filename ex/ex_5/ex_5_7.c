#include <stdio.h>
double cube(double d);
int main(void)
{
    double d, s;
    printf("Enter number and this number will be cubed:\n");
    scanf("%lf", &d);
    s = cube(d);
    
    printf("%.2lf*%.2lf*%.2lf=%.2lf\n", d, d, d, s);
    return 0;
}

double cube(double d)
{
    return d * d * d;
}
