#include <stdio.h>
#include <stdbool.h>
int main(void)
{
    unsigned long num;
    unsigned long div;
    bool isPrime;
    
    printf("Please enter number for analisys;");
    printf(" enter q to exit.\n");

    while ((scanf("%lu", &num)) == 1)
    {
	for (div = 2, isPrime = true; (div*div) < num; div++)
	{
	    if (num%div==0)
	    {
	        if (div * div != num)
		    printf("%lu is divisible by %lu and %lu\n", num, div, num/div);
	        else
		    printf("%lu is divisible by %lu\n", num, div);
		isPrime = false;
	    }
	    
        }
        if (isPrime)
	    printf("%lu is prime\n", num);
        
        printf("Please enter number for analisys;");
	printf(" enter q to exit.\n");

    }
    return 0;
}