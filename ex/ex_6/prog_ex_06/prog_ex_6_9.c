#include <stdio.h>
float calc(float num1, float num2);
int main(void)
{
    float num1, num2;
    printf("Enter to floating point numbers: [number1 number2]:\n");
    printf("enter q to exit\n");
    
    while((scanf("%f %f", &num1, &num2))==2)
    {
	printf("%.2f-%.2f/%.2f*%.2f=%.5f", 
	    num1, num2, num1, num2,
	     calc(num1, num2));
	
	printf("\nEnter to floating point numbers: [number1 number2]:\n");
        printf("enter q to exit\n");
	
	scanf("%f %f", &num1, &num2);
    }
    
    return 0;
}

float calc(float num1, float num2)
{
    return (num1-num2)/(num1*num2);
}