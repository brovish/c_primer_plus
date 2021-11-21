/*
Use a copy function from Programming Exercise 2 to copy the third through fifth
elements of a seven-element array into a three-element array. The function itself need
not be altered; just choose the right actual arguments. (The actual arguments need not be
an array name and array size. They only have to be the address of an array element and a
number of elements to be processed.)
*/

#include <stdio.h>
#define ARR_LENGH 7
#define COPY_ARR_LENGH 3

void print_arr(double ar[], int n, char name[]);
void copy_arr(double s[], double t[], int n);
void copy_ptr(double *s, double *t, int n);
void copy_ptrs(double *s, double *t, double *last);

int main(void)
{
    double source[ARR_LENGH] = {0.1,2.2,3.3,4.4,5.5,2.0,2.3};
    double target1[COPY_ARR_LENGH];

    print_arr(source, ARR_LENGH, "source");
    
    copy_ptrs(source + 2, target1, source + 5);
    
    print_arr(target1, COPY_ARR_LENGH, "target1");
    
    return 0;
}

void copy_ptrs(double *s, double *t, double *last)
{
    while (s < last)
    {
	//printf("%f\n", *s);
	*t = *s;
	s++;
	t++;
    }
}

void copy_ptr(double *s, double *t, int n)
{
    int r;
    for (r = 0; r < n; s++, t++, r++)
    {
	*t = *s;
	//printf("%f\n", *s);
    }
}

void copy_arr(double s[], double t[], int n)
{
    int r;
    for (r = 0; r < n; r++)
    {
	t[r] = s[r];
    }
}

void print_arr(double ar[], int n, char name[])
{
    int r = 0;
    for (; r < n; r++)
	printf("%s[%d]=%.2f\n", name, r, ar[r]);
    putchar('\n');
}