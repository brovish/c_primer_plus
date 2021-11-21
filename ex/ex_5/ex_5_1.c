#include <stdio.h>
#define M_IN_H 60
int main(void)
{
    int hours, r_min, time;
    
    printf("Please enter time in minutes. [minutes]\n");
    printf("Enter 0 or - int to stop.\n");
    
    scanf("%d", &time);
    
    while (time > 0)
    {
	
	hours = time/M_IN_H;
	r_min = time % M_IN_H;
	
	printf("Minutes: %d convert to %d hours, %d minutes\n", time, hours, r_min);
	
	printf("Please enter time in minutes. [minutes]\n");
	printf("Enter 0 or - int to stop.\n");
	scanf("%d", &time);
	
    }
    
    return 0;
}