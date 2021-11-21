#include <stdio.h>
#include <stdarg.h>
double sum(int, ...);
int main(void)
{
	double s, t;
	s = sum(3, 1.1, 2.5, 13.3);
	t = sum(4, 2.2, 1.1, 2.5, 13.3);
	
	printf("return value for "
		" sum(3, 1.1, 2.5, 13.3) 	%g\n", s);
	
	printf("return value for "
		" sum(4, 2.2, 1.1, 2.5, 13.3) 	%g\n", t);

	return 0;
}

double sum(int n, ...)
{
	va_list ap;
	double tot = 0;
	va_start(ap, n);
	
	for (int i = 0; i < n; i++)
		tot += va_arg(ap, double);
	va_end(ap);
	return tot; 
}