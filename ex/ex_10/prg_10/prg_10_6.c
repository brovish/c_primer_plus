#include <stdio.h>
#define ARR_L 6

void reverse_arr(double ar[], int n);
void print_arr(double *start, double *end);
void reverse_arr2(double ar[], int n);

int main(void)
{
    double ar[ARR_L] = {11.1,2.2,-3.3,0.4,5.5, 100.9};
    
    print_arr(ar, ar + ARR_L);
    reverse_arr(ar, ARR_L);
    print_arr(ar, ar + ARR_L);
    
    reverse_arr2(ar, ARR_L);
    print_arr(ar, ar + ARR_L);
    
    return 0;
}

void reverse_arr2(double ar[], int n)
{
    for (int r = 0; r < n/2; r++)
    {
        double temp = ar[r];
        //printf("temp = %0.2f; ar[%d]=%0.2f\n"
    	//    ,temp, n - 1 - r, ar[n - 1 - r]);
        ar[r] = ar[n - 1 - r];
        ar[n - 1 - r] = temp;
    }
}

void reverse_arr(double ar[], int n)
{
    int rs = (n - 1);
    int r = 0;
    double rarr[n];
    for (; rs >= 0 ; rs--, r++)
    {
	//printf("ar[%d]=%.2f\n", rs, ar[rs]);
	//printf("r=%d;rs=%d\n", r, rs);
	rarr[r] = ar[rs];
    }
    for (r = 0; r < n; r++)
	ar[r] = rarr[r];
    //print_arr(rarr, rarr + n);
}

void print_arr(double *start, double *end)
{
    int r = 0;
    while (start < end)
    {
	printf("ar[%d]=%.2f\n", 
	r, *start);
	start++; r++;
    }
    putchar('\n');
}