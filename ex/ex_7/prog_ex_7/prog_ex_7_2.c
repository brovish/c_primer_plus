#include <stdio.h>
#include <ctype.h>
#define STOP_CHAR '#'
int main(void)
{
    char ch;
    int counter = 0;
    
    while ((ch = getchar()) != STOP_CHAR)
    {
	if (isprint(ch))
	{    
	    if (counter++ % 8 == 0)
		printf("\n");
	    printf(" %3c %3d", ch, ch);
	}
    }
    printf("\n");
    return 0;
}