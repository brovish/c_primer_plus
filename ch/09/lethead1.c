#include <stdio.h>

#define NAME "MAXSOFT, INC"
#define ADDRESS "101 Lekh Kachinski Street"
#define PLACE "Tbilisi, Georgia"
#define WIDTH 40



int main(void)
{
    void starbar(void);
    
    starbar();
    
    printf("%s\n", NAME);
    printf("%s\n", ADDRESS);
    printf("%s\n", PLACE);
    starbar();
    
    return 0;
}

void starbar()
{
    int i;
    for (i = 0; i < WIDTH; i++)
	putchar('*');
    putchar('\n');
}