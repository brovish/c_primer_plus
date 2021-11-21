#include <stdio.h>
#define SIZE 5
void show_arr(const double ar[], int n);
void mult_arr(double ar[], int n, double mult);

int main(void)
{
    double arr[SIZE] = {20.0,17.66,8.2,15.3,22.22};
    show_arr(arr, SIZE);
    mult_arr(arr, SIZE, 2.5);
    printf("arr after calling multiply:\n");
    show_arr(arr, SIZE);
    return 0;
}

void show_arr(const double ar[], int n)
{
    
    int i;
    for (i = 0; i < n; i++)
    {
	printf("%8.3f ", ar[i]);
    }
    printf("\n");
}

void mult_arr(double ar[], int n, double mult)
{
    int i;
    for (i = 0; i < n; i++)
    {
	ar[i]*= mult;
    }
}