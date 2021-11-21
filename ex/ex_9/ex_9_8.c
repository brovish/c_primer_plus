#include <stdio.h>

int largest(int, int, int);

int main(void)
{
    int x,y,z,l=0;
    scanf("%d %d %d", &x, &y, &z);
    l=largest(x, y, z);
    printf("%d\n", l);
    return 0;
}

int largest(int x, int y, int z)
{
    /*int l = 0;
    if (x>y && x>z)
	l=x;
    else if (y > x && y > z)
	l=y;
    else if (z > x && z > y)
	l=z;*/
    return (x>y && x>z) ? x : (y > x && y > z) ? y : z;
}