#include <stdio.h>
int main(void)
{
    //int value;
    double value;
    
    for (value = 36; value > 0.1; value/=2)
    {
	printf("%f\n", value);
    }
    return 0;
}