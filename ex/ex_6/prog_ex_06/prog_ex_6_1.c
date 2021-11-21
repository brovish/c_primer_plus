#include <stdio.h>
#define SIZE 26
int main(void)
{
    char arr[SIZE];
    
    int i;
    char ch = 97;
    
    for (i = 1; i <= SIZE; i++)
    {
	arr[i] = ch++;
	printf("arr[%d]=%c\n", i, arr[i]);
    }

    printf("\n");
    return 0;
}