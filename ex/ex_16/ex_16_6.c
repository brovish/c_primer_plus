#include <stdio.h>
const int named = 25;
#define SPACE ' '
#define PS() printf("%c", (SPACE))
#define BIG(X) ((X)+3)
#define SUMSQ(X,Y) printf("("#X"*"#X")+("#Y"*"#Y")=%d\n",((X)*(X))+((Y)*(Y)))
int main(void)
{
	PS();
	PS();
	PS();
	int x = 3;
	int y = 2;
	printf("x=%d\n", x);
	x = BIG(x);
	printf("x=%d\n", x);
	
	printf("x=%d;y=%d\n", x, y);
	SUMSQ(2, 3);
	
	return 0;
}