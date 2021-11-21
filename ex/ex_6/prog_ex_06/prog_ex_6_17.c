#include <stdio.h>
int main(void)
{

    int a_sum = 1000000;
    const int p_year = 8;
    int y_draw = 100000;
    int y_psum = 0;
    int i = 0;
    
    while (a_sum>0)
    {
	a_sum -=y_draw;
	//printf("a_sum1:%d\n", a_sum);
	y_psum = (a_sum * p_year) / 100;
	a_sum += y_psum;
	if (a_sum <= 0) break;
	//printf("y_psum:%d\n", y_psum);
	//printf("a_sum2:%d\n", a_sum);
	i++;
    } 

    printf("%d\n", i);
    
    return 0;
}