#include <stdio.h>

#define NAME "MAXSOFT, INC"
#define ADDRESS "101 Lekh Kachinski Street"
#define PLACE "Tbilisi, Georgia"
#define WIDTH 40
#define SPACE ' '

void show_n_chars(char ch, int num);
int main(void)
{
    
    int spaces;
    
    show_n_chars('*', WIDTH);
    show_n_chars('\n', 0);
    
    show_n_chars(SPACE, (WIDTH - strlen(NAME))/2);
    printf("%s\n", NAME);
    
    spaces = (WIDTH - strlen(ADDRESS))/2;
    show_n_chars(SPACE, spaces);
    
    printf("%s\n", ADDRESS);
    
    show_n_chars(SPACE, (WIDTH - strlen(PLACE))/2);
    
    printf("%s\n", PLACE);
    
    show_n_chars('*', WIDTH);
    show_n_chars('\n', 0);
    return 0;
}

void show_n_chars(char ch, int num)
{
    int i;
    for (i = 0; i <= num; i++)
	putchar(ch);
}