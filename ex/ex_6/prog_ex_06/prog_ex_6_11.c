#include <stdio.h>
int main(void)
{
    const int SIZE = 7;

    int arr[SIZE];
    int input, i = 0;
    while (i <= SIZE && (scanf("%d", &input) == 1))
    {
	
	printf("arr[%d]=%d\n", i, input);
	arr[i] = input;
	i++;
    }
    
    for (i = SIZE; i >= 0; i--)
    {
	printf("%d ", arr[i]);
    }
    
    printf("\n");
    
    return 0;
}