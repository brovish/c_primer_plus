#include <stdio.h>
int main(void)
{
    char ch;
    int count = 0;
    const char STOP_CHAR = '#';
    while ((ch = getchar()) != STOP_CHAR)
    {
	switch (ch)
	{
	    case '.' :
	        ch = '!';
	        count++;
	        break;
	    case '!' :
		count++;
	        putchar('!');
		break;
	}
	putchar(ch);
    }
    
    printf("Total number of substitutions %d\n", count);
    
    return 0;
}