#include <stdio.h>
int main(void)
{
    int count, sum, days;
    
    printf("Please enter number of days to calculate amount of $ [days]:\n");

    scanf("%d", &days);
    count  = 0;
    sum = 0;
    while (count++ < days)
    {
	sum = sum + count*count;
	//debug
	printf("%d\n", count*count);
    }
    
    printf("For %d days you will get $%d.\n", days, sum);
    
    return 0;
}