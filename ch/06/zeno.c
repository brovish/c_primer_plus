#include <stdio.h>
int main(void)
{

    int t_cn;
    long double time, power_of_2;
    int limit;
    
    printf("Enter the number of terms that you want:\n");
    scanf("%d", &limit);
    
    for (time = 0, power_of_2 =1,t_cn = 1;
    t_cn <= limit; t_cn++, power_of_2 *= 2.0)
    {
	time += 1.0/power_of_2;
	printf("time = %Lf when terms = %d.\n",
	    time, t_cn);
    }
    
    return 0;
}