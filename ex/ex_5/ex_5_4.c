#include <stdio.h>

int main(void)
{
    float cm, inches, feet;
    
    printf("Please enter height in centimeters [cm]\n");
    printf("Enter value <= 0 to exit:\n");
    scanf("%f", &cm);
    
    while (cm > 0)
    {
	//divide the length value by 30.48
        feet = cm / 30.48;
	//divide the length value by 2.54
	inches = cm / 2.54;
    	printf("%.1f cm = %1.f feet, %.2f inches\n", cm, feet, inches);

	printf("Please enter height in centimeters [cm]\n");
        printf("Enter value <= 0 to exit:\n");
        scanf("%f", &cm);
    }
    
    printf("bye\n");
    return 0;
}