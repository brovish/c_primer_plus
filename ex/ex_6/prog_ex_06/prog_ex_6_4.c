#include <stdio.h>

int main(void)
{
    int row, space;
    int ch, ch1; // use "ch1" to make the value of "ch" unchangeable

    printf("Please enter an uppercase letter:\n");
    scanf("%c", &ch);
    ch1 = ch;
    
    for (row = 0; row < ch - 65 + 1; row++)
    {
	for (space = 0; space < ch - 65 - row; space++)
	{
	    //printf("space=%d;row=%d;ch=%c", space, row, ch);
	    printf(" ");
	
	}
	    
	for (ch = 65; ch < 65 + row + 1; ch++)
	{
	    
	    printf("%c", ch);
	
	}
	
	for (ch = 65 + row - 1; ch >= 65; ch--)
	{
	    //printf("row=%d;ch=%c", row, ch);
	    printf("%c", ch);
	}
	
	//printf("space=%d;row=%d;ch=%c", space, row, ch);    
	printf("\n");
	ch = ch1; // set "ch" to its initial value
    }
    
    return 0;
}