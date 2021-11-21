#include <stdio.h>
int main(void)
{
    long num;
    long sum = 0L;
    _Bool input_is_ok;
    
    printf("Please enter an integer to be summed \n");
    printf("(q to exit): ");
    input_is_ok = (scanf("%ld", &num) == 1);
    while (input_is_ok	)
    {
	sum = sum + num;
	printf("Please enter the next integer: \n");
	printf("(q to exit): ");
	input_is_ok = (scanf("%ld", &num) == 1);
    }
    
    printf("Integer sum: %ld\n", sum);
    
    return 0;
}