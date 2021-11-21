#include <stdio.h>
#include <stdlib.h>
#define EVEN_GT(X,Y) ((X % 2 == 0) && (X > Y) ? 1 : 0)
int main(int argc, char *argv[])
{
	int x, y;
	x = atoi(argv[1]);
	y = atoi(argv[2]);
	
	printf("EVEN_GT(%d, %d)=%d\n", x, y, EVEN_GT(x, y));
	
	return 0;
}