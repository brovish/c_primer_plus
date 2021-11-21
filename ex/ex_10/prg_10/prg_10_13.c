#include <stdio.h>
#define ROWS 3
#define COLS 5

void printf_2arr(double arr[][COLS], int rows, int cols);

double avgrow_arr(double arr[], int rows);
void avgrow_2arr(double arr[][COLS], int rows, int cols);

double avgallrow_2arr(double arr[][COLS], int rows, int cols);
void printf_avgallrow_2arr(double arr[][COLS], int rows, int cols);

double larges_2arr(double arr[][COLS], int rows, int cols);
void printf_larges_2arr(double arr[][COLS], int rows, int cols);

int main(void) {

    double arr[ROWS][COLS];

    double val; int r = 0; int c = 0;

    printf("Enter 3 rows with 5 double values in each:\n");

    for (; r < ROWS; r++)
    {
        for (c = 0; c < COLS; c++)
        {
            scanf("%lf", &val);
            arr[r][c] = val;
        }
    }

    printf_2arr(arr, ROWS, COLS);
    avgrow_2arr(arr, ROWS, COLS);
    printf_avgallrow_2arr(arr, ROWS, COLS);
    printf_larges_2arr(arr, ROWS, COLS);
    
    return 0;
}

double larges_2arr(double arr[][COLS], int rows, int cols)
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

void printf_larges_2arr(double arr[][COLS], int rows, int cols)
{
    printf("Larges value is: %.2lf\n", 
	larges_2arr(arr, rows, cols));
}


void printf_avgallrow_2arr(double arr[][COLS], int rows, int cols)
{
    printf("Average of all values: %.2lf\n",
	avgallrow_2arr(arr, rows, cols));
}

double avgallrow_2arr(double arr[][COLS], int rows, int cols)
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

void avgrow_2arr(double arr[][COLS], int rows, int cols)
{
    double avgrow;
    int r = 0;
    for (; r < rows; r++)
    {
        avgrow = avgrow_arr(arr[r], cols);
          printf("Average for %d row: %.2lf\n",
          r + 1, avgrow);
    }
}

double avgrow_arr(double arr[], int rows)
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

void printf_2arr(double arr[][COLS], int rows, int cols)
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