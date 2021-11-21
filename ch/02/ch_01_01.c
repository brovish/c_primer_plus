#include <stdio.h>
int main(void) /*simple program*/
{
    //comment c99 style
    int num; /*define variable called num*/
    num = 1; /* assign value to variable*/
    printf("I am simple "); /*use printf function*/
    printf("computer\n ");
    printf("My favorite number is %d because it's the first\n", num);
    getchar();
    char z;
    for (z='A'; z<='Z'; z++)
    {
	printf("%s",&z);
    }
    printf("\n");
    
    return 0;
}
