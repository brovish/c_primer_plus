#include <stdio.h>
#define ARR_LENGH 5

void print_arr(double ar[], int n, char name[]);
void copy_arr(double s[], double t[], int n);
void copy_ptr(double *s, double *t, int n);
void copy_ptrs(double *s, double *t, double *last);

int main(void)
{
    double source[ARR_LENGH] = {0.1,2.2,3.3,4.4,5.5};
    double target1[ARR_LENGH];
    double target2[ARR_LENGH];
    double target3[ARR_LENGH];
    
    print_arr(source, ARR_LENGH, "source");
    
    copy_arr(source, target1, ARR_LENGH);
    print_arr(target1, ARR_LENGH, "target1");
    
    copy_ptr(target1, target2, ARR_LENGH);
    
    print_arr(target2, ARR_LENGH, "target2");
    
    copy_ptrs(target2, target3, target2 + ARR_LENGH);
    print_arr(target3, ARR_LENGH, "target3");
    
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