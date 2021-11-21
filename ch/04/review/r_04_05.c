#include <stdio.h>
#define BOOK "War and Peace"
int main(void)
{

    float cost = 12.99;
    float percent = 80.0;
    
    printf("This copy of %34s sells for $%.2f.\n", BOOK, cost);
    printf("That is %.0f%% of list.\n", percent);
    
    return 0;
}