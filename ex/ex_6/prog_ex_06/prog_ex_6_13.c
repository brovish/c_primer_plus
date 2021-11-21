#include <stdio.h>
#define SIZE 7
int main(void)
{
    int arr[SIZE];
    int i, j;
    for (i=0,j=2;i<=SIZE;i++, j*=2)
	arr[i] = j;
    
    i = 0;
    do
    {
	printf("%d ", arr[i]);
	i++;
    } while (i <= SIZE);
    
    printf("\n");
    return 0;
}