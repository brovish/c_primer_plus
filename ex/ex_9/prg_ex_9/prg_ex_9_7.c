#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define ALPHABET "abcdefghijklmnopqrstuvwxyz"

int char_position(char ch);
bool is_letter(char ch);

int main(void)
{
    char ch;
    
    while ((ch = getchar()) != EOF)
    {
	if (is_letter(ch))
	    printf("letter:%c, number: %d\n", ch, char_position(ch));
	else
	    printf("%c not letter\n", ch);
	if (ch == '\n')
	    ;
    }
    
    return 0;
}


int char_position(char ch)
{
    int i = 0;
    for (;i < sizeof(ALPHABET)/sizeof(ALPHABET[0]);++i)
    {
	if (ALPHABET[i-1]==tolower(ch))
	    return i;
    }
    return -1;
}

bool is_letter(char ch)
{
    return (char_position(ch)>0) ? true : false;
}