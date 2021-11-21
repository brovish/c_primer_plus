#include <stdio.h>
unsigned long rec_fib(unsigned n);
int main(void)
{
    unsigned long num;
    
    printf("Enter number: (q to exit)\n");
    while ((scanf("%lu", &num)) == 1)
    {
	printf("Fibonacci number: ");
	printf("%lu\n", rec_fib(num));
	printf("Enter number: (q to exit)\n");
    }
    
    return 0;
}

unsigned long rec_fib(unsigned n)
{
    if (n > 2)
    {
	//printf("%lu\n",rec_fib(n - 1) + rec_fib(n - 2));
	return rec_fib(n - 1) + rec_fib(n - 2);
    }
    else
    {	
	//printf("%d\n", 1);
	return 1;
    }
}