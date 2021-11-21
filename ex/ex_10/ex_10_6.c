#include <stdio.h>
int main(void)
{
    int grid[30][100] = {};
    
    printf("grid[22][56]=%p\n", &grid[22][56]);
    
    printf("grid[22][56]=%p\n", *(grid + 22) + 56);
    
    printf("grid[22][56]=%p\n", (&(**grid)+22));
    
    printf("grid[0][0]=%p\n", &grid[0][0]);
    
    printf("grid[0][0]=%p\n", &(**grid));
    
    printf("grid[0][0]=%p\n", grid);
    
    return 0;
}