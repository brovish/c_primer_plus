#include <stdio.h>

double min(double x, double y);

int main()
{

    double x, y;
    while ((scanf("%lf %lf", &x, &y)) == 2)
    {
	printf("min:%lf\n", min(x,y));
    }
    return 0;
}

double min(double x, double y)
{

    return (x < y) ? x : y;
}