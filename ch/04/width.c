#include <stdio.h>
#define PAGES 9530000
int main(void)
{
	
	printf("*%d*\n", PAGES);
	printf("*%2d*\n", PAGES);
	printf("*%10d*\n", PAGES);
	printf("*%+-10d*\n", PAGES);
	printf("*%+10d*\n", PAGES);

	return 0;
}
