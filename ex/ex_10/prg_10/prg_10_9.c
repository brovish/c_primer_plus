#include <stdio.h>
#define ROWS 3
#define COLS 5

void print_2arr(int rows, int cols, 
    double ar[rows][cols], char name[]);
void copy_2arr(int rows, 
    int cols, double source[rows][cols],
    double target[rows][cols]);

int main(void)
{
    const int rows = 4;
    const int cols = 6;
    
    double source[rows][cols] = 
    {
	{1.1,2.2,3.3,4.4,5.5,6.6},
	{9.9,8.8,7.7,6.6,5.5,4.4},
	{-9.9,-8.8,-7.7,-6.6,-5.5,-4.4},
	{9.8,8.7,7.6,6.5,5.4,4.3},
    };
    
    double target[rows][cols];
    
    print_2arr(rows, cols, source, "source");
    copy_2arr(rows, cols, source, target);
    print_2arr(rows, cols, target, "target");
    
    return 0;
}

void copy_2arr(int rows, 
    int cols, double s[rows][cols],
    double t[rows][cols])
{
    int r; int c;
    for (r = 0; r < rows; r++)
    {
	for (c = 0; c < cols; c++)
	{
	    t[r][c] = s[r][c];
	}
    }
}


void print_2arr(int rows, int cols, double ar[rows][cols], char name[])
{
    int r = 0; int c = 0;
    for (; r < rows; r++)
    {
	for (c = 0; c < cols; c++)
	{
	    printf("%s[%d][%d]=%.2f\n", 
		name, r+1, c+1, ar[r][c]);
	}
    }
    putchar('\n');
}