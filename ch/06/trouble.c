#include <stdio.h>
int main(void)
{
    long num;
    long sum = 0L;
    int status;
    
    printf("Please enter an integer to be summed \n");
    printf("(q to exit): ");
    status = scanf("%ld\n", &num);
    while (status = 1)
    {
	sum = sum + num;
	printf("Please enter the next integer: \n");
	printf("(q to exit): ");
	status = scanf("%ld\n", &num);
    }
    
    printf("Integer sum: %d", sum);
    
    return 0;
}