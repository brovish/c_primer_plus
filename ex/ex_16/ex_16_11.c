#include <stdio.h>
#include <stdbool.h>

#define ISBOOL(X) _Generic((X),\
		_Bool : puts("boolean"), \
		default: puts("not boolean"))

int main(void)
{
	
	int a = 2;
	ISBOOL(a);
	
	bool y = true;
	ISBOOL(y);
	
	return 0;
}