#include <stdio.h>

#define REPR(X) printf(""#X"=%d\n", (X))

int main(void)
{
	
	REPR(12*4);
	return 0;
}