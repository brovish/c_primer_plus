#include <stdio.h>
double power(double n, int p);
int main(void)
{
    double x, xpow;
    int exp;
    
    //printf("Enter a number and the integer power");
    //printf(" to withc the number will be raised.\n");
    
    while ((scanf("%lf %d", &x, &exp))==2)
    {
	xpow = power(x, exp);
	printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
	//printf("Please enter next pair of number or q to quit.\n");
    }
    
    //printf("Hope you enjoyed this power trip. --buy.\n");
    return 0;
}



double power(double n, int p)
{
    if (p > 0)
    {
        return (p==0) ? 1 : ( n<0 && ((p - 1) % 2) == 0 )
    	    ? n*power(n, p - 1) : ( n<0 && ((p - 1) % 2) != 0 ) 
    	    ? -n*power(n, p - 1) : n*power(n, p - 1);
    }
    else 
    {
        return (p==0) ? 1 : ( n<0 && ((p + 1) % 2) == 0 ) || 
        ( n<0 && ((p % 2) == 0 )) ?
    	    1/n*power(-n, p + 1) : 1/n*power(n, p + 1);
    }
    
}