#include <stdio.h>

long long fact(int n);
long long rfact(int n);

int main(void)
{
    
    int num;
    printf("This program calculates factorials.\n");
    printf("Enter a value in the range 0-12 (q quiot):\n");
    
    while ((scanf("%d", &num))==1)
    {
	if (num<0)
	    printf("No negative numbers, please.\n");
	else if (num>20)
	    printf("Keep input under 20.\n");
	else
	{
	    printf("loop: %d factorial = %lld\n"
		, num, fact(num));
	    printf("recursion: %d factorial = %lld\n"
		,num, rfact(num));
	}
	printf("Enter a value in the range 0-12 (q quiot):\n");
    }
    
    printf("Buy!\n");
    
    return 0;
}

long long fact(int n)
{
    long long ans;
    for (ans=1;n>1;n--)
	ans*=n;
    return ans;
}

long long rfact(int n)
{
    long long ans;
    if (n>0)
	ans = n * rfact(n-1);
    else
	ans = 1;
    
    return ans;
}