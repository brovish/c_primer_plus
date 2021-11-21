#include <stdio.h>

void trots_1(double ar[]);
void trots_2(int rows, double ar[rows]);
void clops_1(short ar[][30]);
void clops_2(int rows, int cols, short ar[rows][cols]);
void shots_1(long ar[][10][3]);
void shots_2(int r, int c, int s, long ar[r][c][s]);

int main(void)
{
    double trots[20];
    short clops[10][30];
    long shots[5][10][3];
    
    trots_1(trots);
    trots_2(20, trots);
    
    clops_1(clops);
    clops_2(10, 20, clops);
    
    shots_1(shots);
    shots_2(5, 10, 3, shots);
    
    return 0;
}

void trots_1(double ar[])
{
    printf("1\n");
}
void trots_2(int rows, double ar[rows])
{
    printf("2\n");
}
void clops_1(short ar[][30])
{
    printf("3\n");
}
void clops_2(int rows, int cols, short ar[rows][cols])
{
    printf("4\n");
}
void shots_1(long ar[][10][3])
{
    printf("5\n");
}
void shots_2(int r, int c, int s, long ar[r][c][s])
{
    printf("6\n");
}
