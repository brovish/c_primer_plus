#include <stdio.h>

void swap(int *, int *);

int main(void)
{
    int x = 5;
    int y = 10;
    printf("originally: x=%d (%p) and y=%d (%p)\n", x, &x , y, &y);
    
    swap(&x, &y);
    
    printf("after swap: x=%d (%p) and y=%d (%p)\n", x, &x , y, &y);
    
    return 0;
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
    
    printf("in swap: x=%d (%p) and y=%d (%p)\n", *x, &x , *y, &y);
}