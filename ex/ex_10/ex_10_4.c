#include <stdio.h>
int main(void)
{
    int *ptr;
    int torf[2][2] = {{12, 11},{13,14}};
    printf("int torf[2][2] = {{12, 11},{13,14}};\n");
    ptr = torf[0];
    printf("*ptr=%d;*(ptr+2)=%d\n", 
	*ptr, *(ptr+2));
    
    printf("*ptr=%p;*(ptr+2)=%p\n", 
	ptr, (ptr+2));
    
    return 0;
}