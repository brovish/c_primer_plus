#include <stdio.h>
int main(void)
{
    long num;
    long sum = 0L;
    int status;
    
    printf("Please enter an integer to be summed ");
    printf("(q to quit): ");
    
    while ((status = scanf("%ld", &num) == 1)
    {
	sum = sum + num;
	printf("Please enter an integer to be summed ");
        printf("(q to quit): ");
    }
    
    printf("Those integer sum to %ld\n.", sum);
    
    return 0;
}