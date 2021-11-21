#include <stdio.h>
#include "stdhelpers.h"
int main(void)
{
	float x, y;
	double a, b;
	a = 2.44;
	b = 4.23;
 	x = 5;
 	y = 25;
 	//printf("%.2f\n", (double)(1/(double)(y)));
	printf("HARM_MEAN(%.2f, %.2f) = %.2f\n", x, y, HARM_MEAN(x, y));
	printf("HARM_MEAN(%.2f, %.2f) = %.2f\n", a, b, HARM_MEAN(a, b));
	return 0;
}