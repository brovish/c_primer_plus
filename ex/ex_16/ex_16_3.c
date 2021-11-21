#include <stdio.h>
#define MIN(X,Y) ((X<Y)?(X):(Y))
int main(void)
{
	int x, y;
	x = 5; y = 6;
	int min = MIN(x, y);
	
	printf("x=%d;y=%d;minimum=%d\n", x, y, min);
	
	return 0;
}