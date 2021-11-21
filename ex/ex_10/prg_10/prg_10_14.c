#include <stdio.h>

void printf_2arr(int rows, int cols, double arr[rows][cols]);

double avgrow_arr(int rows, double arr[rows]);
void avgrow_2arr(int rows, int cols, double arr[rows][cols]);

double avgallrow_2arr(int rows, int cols, double arr[rows][cols]);
void printf_avgallrow_2arr(int rows, int cols, double arr[rows][cols]);

double larges_2arr(int rows, int cols, double arr[rows][cols]);
void printf_larges_2arr(int rows, int cols, double arr[rows][cols]);

int main(void)
{
    
    int rows = 3; int cols = 5;
    double arr[rows][cols];
    double val;
    int r = 0; int c = 0;
    
    printf("Enter 3 rows with 5 double values in each:\n");

    for (; r < rows; r++)
    {
        for (c = 0; c < cols; c++)
        {
            scanf("%lf", &val);
            arr[r][c] = val;
        }
    }

    printf_2arr(rows, cols, arr);
    avgrow_2arr(rows, cols, arr);
    printf_avgallrow_2arr(rows, cols, arr);
    printf_larges_2arr(rows, cols, arr);
    
    return 0;
}

double larges_2arr(int rows, int cols, double arr[rows][cols])
{
    double larr = **arr;
    int r = 0; int c = 0;
    for (; r < rows; r++)
    {
	for (c = 0; c < cols; c++)
	{
	    if (larr < arr[r][c])
		larr = arr[r][c];
	}
    }
    return larr;
}

void printf_larges_2arr(int rows, int cols, double arr[rows][cols])
{
    printf("Larges value is: %.2lf\n", 
	larges_2arr(rows, cols, arr));
}


void printf_avgallrow_2arr(int rows, int cols, double arr[rows][cols])
{
    printf("Average of all values: %.2lf\n",
	avgallrow_2arr(rows, cols, arr));
}

double avgallrow_2arr(int rows, int cols, double arr[rows][cols])
{
    double sum_allrow = 0;
    int r = 0; int c = 0; int tc = 0;
    for (; r < rows; r++)
    {
	for (c = 0; c < cols; c++, tc++)
	{
	    sum_allrow += arr[r][c];
	}
    }
    //printf("%d\n", tc);
    return sum_allrow / tc;
}

void avgrow_2arr(int rows, int cols, double arr[rows][cols])
{
    double avgrow;
    int r = 0;
    for (; r < rows; r++)
    {
	avgrow = avgrow_arr(cols, arr[r]);
    	printf("Average for %d row: %.2lf\n",
    	    r + 1, avgrow);
    }
}

double avgrow_arr(int rows, double arr[rows])
{
    int r = 0;
    double sumrow = 0;
    for (; r < rows; r++)
    {
	//printf("%lf\n", arr[r]);
	sumrow += arr[r];
    }
    //printf("%lf\n", sumrow);
    return sumrow/rows;
}

void printf_2arr(int rows, int cols, double arr[rows][cols])
{
    int r = 0; int c = 0;
    for (; r < rows; r++)
    {
	for (c = 0; c < cols; c++)
	{
	    printf("arr[%d][%d]=%5.2lf   ", r, c, arr[r][c]);
	}
	printf("\n");
    }
}