/*Using if else statements, write a program that 
reads input up to #, replaces each period
with an exclamation mark, replaces each exclamation 
mark initially present with two exclamation marks, 
and reports at the end the number of substitutions it has made.*/
#include <stdio.h>
#define STOP_CHAR '#'
int main(void)
{
    
    char ch;
    int count = 0;
    
    while ((ch = getchar()) != STOP_CHAR)
    {
	if (ch == '.')
	{
	    ch = '!';
	    //putchar('!');
	    count++;
	} else if	 (ch == '!')
	{
	    putchar('!');
	    count++;
	}
	putchar(ch);
	
    }
    printf("Total number of substitions: %d", count);
    return 0;
}