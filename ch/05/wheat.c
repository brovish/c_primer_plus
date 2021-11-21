#include <stdio.h>
#define SQUARES 100
int main(void)
{

    const double CROP = 2E16;
    double current, total;
    int count = 1;
    total = current = 1.0;
    
    printf("square     qrains       total     ");
    printf("fraction of\n");
    printf("           added        grains    ");
    printf("world total\n");
    
    while (count < SQUARES)
    {
    
	printf("%4d %13.2e %12.2e %12.2e\n", 
	    count, current,  total, total/CROP);
	count = count + 1;
	current = 2.0 * current;
	total = total + current;
    }
    return 0;
}