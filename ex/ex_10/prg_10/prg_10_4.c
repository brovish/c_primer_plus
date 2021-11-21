#include <stdio.h>
#define ARR_L 5

int larridx(double ar[], int n);
int ptr_larridx(double *start, double *end);

int main(void)
{
    double ar[ARR_L] = {0.1,4.5,22.0,4.6,2.2};
    
    printf("Largest index: %d\n", larridx(ar, ARR_L));
    printf("Largest index: %d\n", ptr_larridx(ar, ar + ARR_L));
    
    return 0;
}

int ptr_larridx(double *start, double *end)
{
    int r = 0;
    int larridx = 0;
    double larr = *start;
    while (start < end)
    {
	//printf("%f %f\n", *start, *(start + 1));
	if (larr < *start)
	{
	    larridx = r;
	    larr = *start;
	}
	r++;
	start++;
    }
    return larridx;
}

int larridx(double ar[], int n)
{
    int larridx = 0;
    double larr = ar[0];
    int r = 0;
    
    for (; r < n; r++)
    {
	if (larr < ar[r])
	{
	    larr = ar[r];
	    larridx = r;
	}
    }
    
    return larridx;
}