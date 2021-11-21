#include <stdio.h>
int main(void)
{
    
    int i = 1;
    float n;
    printf("Watch out! Here comes a bunch of fractions!\n");
    while(i<30)
    {
	n = (float) 1/i;
	printf(" %2.2f %d\n", n, i);
	i++;
    }
    printf("That's all folks!\n");
    return 0;
}