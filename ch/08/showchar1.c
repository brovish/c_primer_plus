#include <stdio.h>
void display(char cr, int lines, int width);
int main(void)
{
    int ch;
    int rows, cols;
    printf("Enter a character and two integers:\n");
    
    while ((ch = getchar()) != 'n')
    {
	scanf("%d %d", &rows, &cols);
	display(ch, rows, cols);
	fseek(stdin,0,SEEK_END);
	printf("Enter another character and two inegers;\n");
	printf("Enter newline to quit.\n");
    }
    printf("Buy.\n");
    
    return 0;
}

void display(char cr, int lines, int width)
{
    int row, col;
    for (row = 1; row <= lines; row++)
    {
	for (col = 1; col <= width; col++)
	{
	    putchar(cr);
	}
	putchar('\n');
    }
}