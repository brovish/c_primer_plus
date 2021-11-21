#include <stdio.h>
int main(void)

{
    int urn[5] = {100,200,300,400,500};
    int *ptr1, *ptr2, *ptr3;
    
    ptr1 = urn;
    ptr2 = &urn[2];
    
    printf("pointer value, dereferenced poiner, poineter address:\n");
    printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n", 
	ptr1, *ptr1, &ptr1);
    
    //pointer addition
    ptr3 = ptr1 + 4;
    printf("\naddind an int it a poiner:\n");
    printf("ptr1 + 4 = %p, *(ptr1 + 3) = %d", 
	ptr1 + 4, *(ptr1 + 3));
    printf("\n");
    
    //increment
    ptr1++;
    printf("values after ptr1++\n");
    printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n", 
	ptr1, *ptr1, &ptr1);
    printf("\n");
    //decrement pointer
    ptr2--;
    printf("values after ptr2--\n");
    printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n", 
	ptr2, *ptr2, &ptr2);
    ++ptr2;
    --ptr1;
    printf("\n");
    printf("Pointers reset to original values:\n");
    printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p,\n ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n",
	ptr1, *ptr1, &ptr1, ptr2, *ptr2, &ptr2);
    printf("\n");
    printf("Substraction one poiter from another:\n");
    printf("ptr1 = %p, ptr2 = %p, ptr2 - ptr1 = %td\n", 
	ptr1, ptr2, ptr2 - ptr1);
    printf("ptr1 = %p, ptr2 = %p, ptr1 - ptr2 = %td\n", 
	ptr1, ptr2, ptr1 - ptr2);
    printf("\n");
    printf("Substracting int from a pointer:\n");
    printf("ptr3 = %p, ptr3 - 2 = %p\n", 
	ptr3, ptr3 -2);
    
    return 0;
}