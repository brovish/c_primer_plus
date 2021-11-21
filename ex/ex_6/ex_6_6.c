#include <stdio.h>
#define LENGTH 8
#define HEIGHT 4
int main(void)
{

    const char ch = '$';
    char arr[LENGTH];
    int i, j;
    
    for (i = 0; i < LENGTH; i++)
    {
	arr[i] = ch;
    }
    
    for (i = 0; i < HEIGHT; i++)
    {
	for (j = 0; j < LENGTH; j++)
	{
	    printf("%c", arr[i]);
	}
	printf("\n");
    }

    return 0;
}