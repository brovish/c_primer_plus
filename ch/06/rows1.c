#include <stdio.h>
#define ROWS 6
#define CHARS 10
int main(void)
{
    int rows;
    char ch;
    
    for (rows=0;rows< ROWS;rows++)
    {
    	for (ch='A';ch < ('A' + CHARS); ch++)
	{
	    printf("%c", ch);
	}
	printf("\n");
    }
    
    return 0;
}