#include <stdio.h>
int main(void)
{
    const char STOP_CHAR = '#';
    char last_char;
    char cur_char;
    int count = 0;
    
    while ((cur_char = getchar()) != STOP_CHAR)
    {
	if (cur_char == 'e')
	{
	    last_char = cur_char;
	}
	if (last_char == 'e' && cur_char == 'i')
	{
	    last_char = cur_char;
	    count++;
	}
    }
    printf("ei occurs %d times.\n", count);
    
    return 0;
}