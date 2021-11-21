#include <stdio.h>
int main(void)
{
    int ref[] = {8,4,0,2};
    int *ptr;
    ptr = ref;
    int index;
    
    printf("%p %p\n", ++ptr, ptr+1);
    
    for (index=0;index<4;index++,ptr++)
    {
	printf("%d %d\n", ref[index], *ptr);
    }
    return 0;
}