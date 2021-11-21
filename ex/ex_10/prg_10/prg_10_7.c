#include <stdio.h>
#define ROWS 5
#define COLS 5

void print_arr(double ar[], int n, char name[]);
void print_2arr(double ar[][COLS], int rows, int cols, char name[]);
void copy_arr(double s[], double t[], int n);
void copy_ptr(double *s, double *t, int n);
void copy_ptrs(double *s, double *t, double *last);
void copy_2arr(
    double s[][COLS], 
    double t[][COLS],
    int rows, int cols
);

int main(void)
{
    double source[ROWS][COLS] = 
    {
	{0.1,2.2,3.3,4.4,5.5},
	{0.1,2.2,3.3,4.4,5.5},
	{0.1,2.2,3.3,4.4,5.5},
	{0.1,2.2,3.3,4.4,5.5},
	{0.1,2.2,3.3,4.4,5.5},
    };
    
    double target[ROWS][COLS];
    
    print_2arr(source, ROWS, COLS, "source");
    
    copy_2arr(source, target, ROWS, COLS);
    
    print_2arr(target, ROWS, COLS, "target");
    
    return 0;
}

void copy_2arr(
    double s[][COLS], 
    double t[][COLS],
    int rows, int cols
)
{
    int r = 0;
    for (; r < cols; r++)
	copy_ptrs(s[r], t[r], s[r] + rows);
}

void copy_ptrs(double *s, double *t, double *last)
{
    while (s < last)
    {
	//printf("%f\n", *s);
	*t = *s;
	s++;
	t++;
    }
}

void copy_ptr(double *s, double *t, int n)
{
    int r;
    for (r = 0; r < n; s++, t++, r++)
    {
	*t = *s;
	//printf("%f\n", *s);
    }
}

void copy_arr(double s[], double t[], int n)
{
    int r;
    for (r = 0; r < n; r++)
    {
	t[r] = s[r];
    }
}

void print_2arr(double ar[][COLS], int rows, int cols, char name[])
{
    int r = 0; int c = 0;
    
    for (; r < rows; r++)
    {
	for (c = 0; c < cols; c++)
	{
	    printf("%s[%d][%d]=%.2f\n", 
		name, r, c, ar[r][c]);
	}
    }
    putchar('\n');
}

void print_arr(double ar[], int n, char name[])
{
    int r = 0;
    for (; r < n; r++)
	printf("%s[%d]=%.2f\n", name, r, ar[r]);
    putchar('\n');
}