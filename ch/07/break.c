#include <stdio.h>
int main(void)
{
    float width, length;
    printf("Enter the lenght of the rectangle:\n");
    
    while ((scanf("%f", &length)) == 1)
    {
	printf("Length = %0.2f:", length);
	printf("Enter it's width:\n");
	if ((scanf("%f", &width)) != 1)
	    break;
	printf("Widht = %0.2f:", width);
	printf("Area = %0.2f:", length * width);
	printf("Enter the length of the rectagle:\n");
    }
    
    printf("Done!\n");
    
    return 0;
}