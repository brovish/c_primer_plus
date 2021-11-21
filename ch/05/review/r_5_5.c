#include <stdio.h>
#define S_TO_M 60
int main(void)
{
    
    int sec = 0, min, left;
    
    printf("This program converts seconds to minutes and ");
    printf("seconds.\n");
    
    printf("Just enter a number of seconds.\n");
    printf("Enter -1 to stop.\n");
    
    while (sec >= 0)
    {
	scanf("%d",&sec);
	min = sec/S_TO_M;
	left = sec%S_TO_M;
	printf("%d is %d min, %d sec.\n", sec, min, left);
	printf("Next input?\n");
    }
    
    printf("Buy!\n");
    
    return 0;
}