#include <stdio.h>
int main(void)
{
    const int SIZE = 7;
    double arr1[SIZE];
    double arr2[SIZE];
    int i;
    double input, sum = 0;
        
    for (i=0;i<=SIZE;i++)
    {
	scanf("%lf", &input);
	arr1[i] = input;
	sum = sum + arr1[i];
	arr2[i] = sum;
	printf("%5.2lf ", arr1[i]);
    }
    
    /*for (i=0;i<=SIZE;i++)
    {
	printf("%lf ", arr1[i]);
    }*/
    printf("\n");
    for (i=0;i<=SIZE;i++)
    {
	printf("%5.2lf ", arr2[i]);
    }
    printf("\n");
    return 0;
}