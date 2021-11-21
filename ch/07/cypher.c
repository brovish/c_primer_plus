#include <stdio.h>
#define SPACE ' '
int main(void)
{
    char ch;
    int i = 1;
    //ch = getchar();
    
    while ((ch = getchar()) != '\n')
    {
	//i++;
	if (ch == SPACE)
	    putchar(ch);
	else
	    putchar(ch+i);
    }
    
    putchar(ch);
    
    return 0;
}