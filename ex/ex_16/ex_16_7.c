#include <stdio.h>
#define INFO(X) printf("name: "#X";\tvalue: %d;\taddress: %p\n", X, &X)
int main(void)
{
	int x = 5;
	INFO(x);	
}