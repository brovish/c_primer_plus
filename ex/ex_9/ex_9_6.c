#include <stdio.h>

void alter(int*, int*);

int main(void)
{
    
    int x, y = 0;
    
    scanf("%d %d", &x, &y);
    printf("%d (%p); %d (%p)\n", x, &x, y, &y);
    alter(&x, &y);
    printf("%d (%p); %d (%p)\n", x, &x, y, &y);
    
    return 0;
}


void alter(int* x, int* y)
{
    int z;
    z = *x;
    *x = *x + *y;
    *y = z - *y;
}