#include <stdio.h>
#define LOOPS_COUNT 4
int main(void)
{
    const char ch = '$';
    int i, j;
    
    for (i = 1; i <= LOOPS_COUNT; i++)
    {
	for (j = 1; j <= i; j++)
	{
	    printf("%c", ch);
	}
	printf("\n");
    }
    
    return 0;
}