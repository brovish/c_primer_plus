#include <stdio.h>
#define ARR_L 5

int larr(int ar[], int n);
void print_arr(int ar[], int n);

int main(void)
{
    int ar[ARR_L] = {1, 222, -10, 100, 2};
    
    print_arr(ar, ARR_L);
    
    printf("largest:%d\n", larr(ar, ARR_L));
    
    return 0;
}

int larr(int ar[], int n)
{
    int larr = ar[0];
    int r = 0;
    
    for (; r < n; r++)
    {
	if (larr < ar[r])
	    larr = ar[r];
    }
    
    return larr;
}

void print_arr(int ar[], int n)
{
    
    putchar('\n');
    int r = 0;
    
    for (; r < n; r++)
	printf("ar[%d]=%d\n", r, ar[r]);
    putchar('\n');
}