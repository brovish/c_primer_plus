#include <stdio.h>
int main(void)
{
	
	#ifdef DEBUG
		printf("skip this\n");
	#endif
	return 0;
}