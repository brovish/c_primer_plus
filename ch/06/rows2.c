#include <stdio.h>
int main(void)
{
    const int ROWS = 6;
    const int CHARS = 6;
    int rows;
    char ch;
    
    for (rows = 0; rows < ROWS; rows++)
    {
	for (ch = ('A' + rows); ch < ('A' + CHARS); ch++)
	{
	    printf("%c", ch);
	}
	printf("\n");
    }
    
    return 0;
}