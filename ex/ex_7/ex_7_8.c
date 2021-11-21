#include <stdio.h>
int main(void)
{
    int age = 20;
    
    while (age++ <= 65)
    {
	if ((age % 20) == 0)
	    printf("You are %d. Here is raise.\n", age);
	if (age == 65)
	    printf("You are %d. Here is gold watch.\n", age);
    }
    
    return 0;
}