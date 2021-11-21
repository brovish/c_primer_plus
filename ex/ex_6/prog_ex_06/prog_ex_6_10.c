#include <stdio.h>
int main(void)
{
    
    int sum, i, lower, upper;
    printf("Please enter lower and upper limit (int) "
	"[number1,number2]\n");
    printf("To exit enter upper limit equal or less than lower limit: "
	"[number1 number2]\n");
    
    while ((scanf("%d %d", &lower, &upper))==2 && upper > lower)
    {
	
	for (i = lower, sum = 0; i <= upper; sum = sum + i * i, i++)
	    ;
	printf("The sum of squares from %d %d is %d\n", lower * lower,
	 upper*upper, sum);
	printf("Please enter lower and upper limit (int) "
	    "[number1 number2]\n");
	printf("To exit enter upper limit equal or less than lower limit: "
	    "[number1 number2]\n");
    
	//scanf("%d %d", &lower, &upper);
    }
    
    printf("Done.\n");
    
    return 0;
}