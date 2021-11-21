#include <stdio.h>
#include <stdlib.h>
#define DAYS_IN_WEEK 7;
int main(void)
{
    int days, weeks, r_days;
    system("clear");
    
    printf("Convert number of days to number of weeks and days\n");
    printf("Please enter numbere of days: [days]\n");
    printf("or enter 0 or negative number to stop\n");
    
    scanf("%d" ,&days);
    
    while(days > 0)
    {
	weeks = days / DAYS_IN_WEEK;
	r_days = days % DAYS_IN_WEEK;
	
	if (days == r_days) 
	{
    	    r_days = 0;
        }
	printf("%d days, %d weeks, %d days\n", days, weeks, r_days);
	
	scanf("%d" ,&days);
    
	printf("Convert number of days to number of weeks and days\n");
	printf("Please enter numbere of days: [days]\n");
	printf("or enter 0 or negative number to stop\n");
	
	system("clear");
    }
    
    return 0;
}