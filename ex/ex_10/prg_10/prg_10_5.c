#include <stdio.h>
#define ARR_L 5

double larr_dif(double ar[], int n);

int main(void)
{
    
    double ar[ARR_L] = {42.1,2.2,3.3,4.4,5.5};
    printf("Diff: %.2f\n",larr_dif(ar, ARR_L));
    return 0;
}


double larr_dif(double ar[], int n)
{
    int r = 0;
    double larr = ar[0];
    double smarr = ar[0];
    
    for (; r < n; r++)
    {
	if (larr < ar[r])
	    larr = ar[r];
	if (smarr > ar[r])
	    smarr = ar[r];
    }
    printf("largest: %0.2f; smallest: %.2f\n", 
	larr, smarr);
    return (larr - smarr);
}