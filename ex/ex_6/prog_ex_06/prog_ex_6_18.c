#include <stdio.h>
int main(void)
{
    /*The first week one friend dropped out 
	and the remaining number of friends doubled.
    The second week two friends dropped out 
	and the remaining number of friends doubled*/
    
    int dn = 150;
    int i;
    int ic = 5;
    //int j = 0;
    
    for (i = 1; ic <= dn ; i++)
    {
    	ic = ic - i;
	ic*=2;
	if (ic >= dn) break;
	printf("Week number:%2d; friends count: %2d\n", i, ic);
    }
    
    return 0;
}