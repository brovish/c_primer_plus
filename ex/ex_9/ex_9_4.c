#include <stdio.h>
int sum(int,int);
int main(void)
{
    int x, y, z = 0;
    scanf("%d %d", &x, &y);
    
    z = sum(x, y);
    
    printf("%d+%d=%d\n", x, y, z);
    
    return 0;
}

int sum(int x, int y)
{
    return x + y;
}