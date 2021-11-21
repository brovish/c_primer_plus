#include <stdio.h>
int main(void)
{

    int inv1 = 100; 
    //int inv2 = 100;
    float perc1 = 10;
    float perc2 = 5;
    float sum1 = 100, sum2 = 100;
    int i = 0;
    
    do
    {
	sum1 = sum1 + (inv1 * perc1) / 100;
	//base2 = base2 + (sum2 * perc2) / 100;
	sum2 = sum2 + (sum2 * perc2) / 100;
	++i;
	//printf("year=%d;sum1=%5.2f;sum2=%5.2f;\n",i,  sum1, sum2);
	//sum1 = sum1 + inv1;
	//sum2 = sum2 + inv2;
    }
    while (sum1>sum2);
    
    /*
    for (i=1; ;i++)
    {
	if (sum2>sum1)
	{
	    //printf("sum1=%f;sum2=%f\n", sum1, sum2);
	    break;
	}
	sum1 = sum1 + (inv1 * perc1) / 100;
	base2 = base2 + (inv2 * perc2) / 100;
	sum2 = sum2 + (base2 * perc2) / 100;
	printf("year=%d;sum1=%d;sum2=%d;\n",i, sum1, sum2);
    
    }*/
    
    printf("year=%d;sum1=%5.2f;sum2=%5.2f;\n",i, sum1, sum2);
    
    return 0;
}