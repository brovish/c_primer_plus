#include <stdio.h>
//#include <stdbool.h>
#include <ctype.h>
#define STOP_CHAR '#'
int main(void)
{
    
    char ch;
    int c_spaces = 0;
    int c_newline = 0;
    int c_chars = 0;
    int c_all_others = 0;
    //bool in_word = true;
    
    while ((ch = getchar()) != STOP_CHAR)
    {
	
	
	if (ch == ' ')
	    c_spaces++;
	else if (ch == '\n')
	    c_newline++;
	else if (isalpha(ch))
	    c_chars++;
	else c_all_others++;
	
    }
    
    printf("count of spaces: %d\n", c_spaces);
    printf("count of newlines: %d\n", c_newline);
    printf("count of chars: %d\n", c_chars);
    printf("count of all_others: %d\n", c_all_others);
    
    return 0;
}