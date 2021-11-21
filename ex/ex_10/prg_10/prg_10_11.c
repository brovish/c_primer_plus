#include <stdio.h>
#define ROWS 3
#define COLS 5

void printf_2arr(int arr[][COLS], int rows, int cols);
void double_2arr(int arr[][COLS], int rows, int cols);

int main(void)
{
    int arr[ROWS][COLS] = 
    {
	{2048, 4096, 8192, 16384, 32768},
	{32, 64, 128, 512, 1024},
	{2, 4, 6, 8, 16}
    };
    
    printf_2arr(arr, ROWS, COLS);
    double_2arr(arr, ROWS, COLS);
    putchar('\n');
    printf_2arr(arr, ROWS, COLS);
    return 0;
}

void double_2arr(int arr[][COLS], int rows, int cols)
{

    int r = 0; int c = 0;
    for (; r < rows; r++)
    {
	for (c = 0; c < cols; c++)
	{
	    arr[r][c] *= 2;
	}
    }
}

void printf_2arr(int arr[][COLS], int rows, int cols)
{
    int r = 0; int c = 0;
    for (; r < rows; r++)
    {
	for (c = 0; c < cols; c++)
	{
	    printf("arr[%d][%d]=%5d ", r, c, arr[r][c]);
	}
	printf("\n");
    }
}