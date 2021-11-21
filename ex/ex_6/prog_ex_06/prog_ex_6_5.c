#include <stdio.h>
#define ROWS 5
#define CHARS 9
int main(void)
{
    int i, j;
    int row;
    char leters[CHARS];
    printf("Enter uppercase letter: \n");
    //scanf("%c", &ch);
    //60--95
    
    for (row = 0; row < ROWS; row++)
    {
	for (i = 0; i <= row; i++)
	{
	    for (j = 0; j <=i ; j++)
	    {
		printf("*");
	    }
	}
	printf("\n");
    }
    
    printf("\n");
    
    return 0;
}