#include <stdio.h>

void fib_print(long long);
long long fib(long long);

int main(void)
{
    long long num;
    int i;
    
    
    while (scanf("%lld", &num) == 1)
    {
	printf("fib sequence: ");
	for (i=0;i<num;i++)
	{
	    if (i + 1 >= num)
		fib_print(i);
	    else
		fib_print(i);
	}
	printf("%lld", fib(num));
	printf("\n");
    }    
    
    return 0;
}

long long fib(long long num)
{
    return (num > 2) ? fib(num-1) + fib(num-2) : 1;
}

void fib_print(long long num)
{
    
    if (num > 2)
    {
        printf("%lld ", fib(num));
    }
    else 
    {
	printf("%d ", 1);
    }
}