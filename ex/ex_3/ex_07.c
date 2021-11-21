#include <stdio.h>
int main(void)
{
printf("Please enter your height in santimeters: \n");
float sm;
scanf("%f",&sm);
printf("Height in inches: %.2f\n", sm/2.54);
return 0;
}
