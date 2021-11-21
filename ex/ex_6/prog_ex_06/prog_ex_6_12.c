#include <stdio.h>
int main(void)
{
    int limit, i;
    float div, sum1 = 0, sum2 = 0;
    scanf("%d",&limit);
    //1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ...
    //1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ...
    
    for (i = 1; i < limit + 1; i++)
    {
	div = i;
	//printf("sum=%f;div=%f;1.0/%f=%f\n", sum1, div, div, 1.0/div);
	sum1 = sum1 + 1.0/div;
	if (i%2==0)
	{
	    sum2 = sum2 - 1.0/div;
	} else 
	{
	    sum2 = sum2 + 1.0/div;
	}
    }
    
    printf("sum1=%f;sum2:%f\n", sum1, sum2);
    
    return 0;
}