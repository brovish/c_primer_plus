#include <stdio.h>

int imin(int num1, int num2);
int main(void)
{
    int num1,num2;
    printf("Enter a pair of integers (q to quit):\n");
    
    while (scanf("%d %d", &num1, &num2) == 2)
    {
	printf("%d\n", imin(num1, num2));
    }
    
    return 0;
}

int imin(int num1, int num2)
{
    return (num1 < num2) ? num1 : num2;
}