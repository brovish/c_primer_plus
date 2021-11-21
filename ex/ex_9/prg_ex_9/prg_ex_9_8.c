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
    double pow = 1;
    int i;
    
    if (p == 0)
    {
	printf("Any number to the 0 power is 1\n");
	return 1;
    }

    int num = (p > 0) ? p : -1*p;
    
    for(i = 1; i <= num; i++)
    {
	pow*= n;
    }
    //printf("%lf %lf %d\n", pow, n, p);
    
    if (n==0 && p!=0)
	return 0;
    else if (n>0 && p>0)
	return pow;
    else if (n>0 && p<0)
	return 1/pow;
    else if (n<0 && p>0 && p%2==0)
	return -1*pow;
    else if (n<0 && p>0 && p%2!=0)
	return 1*pow;
    else if (n<0 && p<0 && -1*p%2==0)
	return -1*(1/pow);
    else if (n<0 && p<0 && -1*p%2!=0)
	return 1/pow;
    else return pow;
}