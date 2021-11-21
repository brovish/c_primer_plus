#include <stdio.h>

long long fib(long long);

int main(void)
{
    long long num;
    
    while (scanf("%lld", &num) == 1)
    {
	printf("%lld fib:%lld\n", num, fib(num));
    }
    
    
    return 0;
}

long long fib(long long num)
{
    //long long f;
    if (num > 2)
    {
	return fib(num-1) + fib(num-2);
    else 
	return 1;
}