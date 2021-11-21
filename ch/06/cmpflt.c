#include <stdio.h>
#include <math.h>
int main(void)
{
    const double ANSWER = 3.14159;
    double responce;
    
    printf("What is the value of PI?\n");
    scanf("%lf", &responce);

    while (fabs(responce - ANSWER) > 0.0001)
    {
    
	printf("Try again!\n");
	scanf("%lf", &responce);
    }
    
    printf("Close enought!\n");
    
    return 0;
}