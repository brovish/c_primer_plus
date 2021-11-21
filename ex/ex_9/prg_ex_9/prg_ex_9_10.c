#include <stdio.h>
void base_n(int num, int base);
int main(void)
{
    unsigned long num;
    int base;
    
    printf("Enter an integer number and base (range from 2 to 10) (q to exit):\n");
    
    while ((scanf("%lu %d", &num, &base)) == 2)
    {
	
	if (base > 1 && base <= 10)
	{
	    printf("%d'nary equivalent of %lu is ", base, num);
	    base_n(num, base);
	    printf("\n");
	}
    }
    
    return 0;
}

void base_n(int num, int base)
{
    int r, q;
    r = num % base;
    q = num / base;
    if (q>0)
    {
	num = q;
	base_n(q, base);
    }
    printf("%d", r);
}
