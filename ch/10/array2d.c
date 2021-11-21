#include <stdio.h>
#define ROWS 3
#define COLS 4
void sum_rows(int ar[][COLS], int rows);
void sum_cols(int [][COLS], int);
int sum2d(int (*ar)[COLS], int rows);

int main(void)
{
    int junk[ROWS][COLS] = {
	{2,4,6,8},
	{3,5,7,9},
	{12,10,8,6}
    };
    
    printf("{2,4,6,8}\n{3,5,7,9}\n"
	"{12,10,8,6}\n");
    
    sum_rows(junk, ROWS);
    sum_cols(junk, ROWS);
    
    printf("Sum of all elements = %d\n", sum2d(junk, ROWS));
    
    return 0;
}

void sum_rows(int ar[][COLS], int rows)
{
    int r,c,tot;
    for (r=0;r<rows;r++)
    {
	tot = 0;
	for (c=0;c<COLS;c++)
	{
	    tot+=ar[r][c];
	}
	printf("row %d: sum = %d\n", r+1, tot);
    }
}

void sum_cols(int ar[][COLS], int rows)
{
    int r, c, tot;
    for (c=0;c<COLS;c++)
    {
	tot=0;
	for (r=0;r<rows;r++)
	{
	    tot+=ar[r][c];
	}
	printf("col %d: sum = %d\n", c+1, tot);
    }
}

int sum2d(int (*ar)[COLS], int rows)
{
    int r,c,tot = 0;
    for (r=0;r<rows;r++)
    {
	for(c=0;c<COLS;c++)
	{
	    tot+=ar[r][c];
	}
    }
    return tot;
}
