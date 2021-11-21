#include <stdio.h>
int main(void)
{
    int lower, upper;
    
    printf("Please enter lower and upper limit to calculate\n");
    scanf("%d %d", &lower, &upper);
    
    for (; lower <= upper; lower++)
	printf("%d*%d=%d;%d*%d*%d=%d\n", lower, lower, lower*lower, 
	    lower, lower, lower, lower*lower*lower);
    
    return 0;
}