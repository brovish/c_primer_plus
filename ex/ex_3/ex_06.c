#include <stdio.h>
int main(void)
{
printf("Please enter amount of water in quarts: \n");
float q;
scanf("%f",&q);
float f_count = 3.0E-23;
float t_grams = 950.0 * q;
printf("There is %f molecules of water in %.2f quarts \n",
		t_grams/f_count, q);
return 0;
}
