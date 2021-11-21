#include <stdio.h>
int main(void)
{
    /*3 + 4 > 2 && 3 < 2
    x >= y || y > x
    d = 5 + ( 6 > 2 )
    'X' > 'T' ? 10 : 5
    x > y ? y > x : x > y*/
    
    int d;
    int x, y;
    x = 5; y = 4;
    d = 5 + ( 6 > 2 );
        
    printf("%d\n", d);
    
    printf("%d\n", 3 + 4 > 2 && 3 < 2);
    
    printf("%d\n", x > y ? y > x : x > y);
    
    return 0;
    
}