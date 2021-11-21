#include <stdio.h>
int main(void)
{
	unsigned int y, x = 255;
	int cnt;
	
	printf("Decimal \tshift left by\tresult\n");
	
	for (cnt = 1; cnt < 9; cnt++)
	{
		y = x << cnt;
		printf("%d\t\t%d\t\t%d\n", x, cnt, y);
	}
	
	printf("Decimal \tshift right by\tresult\n");
	
	for (cnt = 1; cnt < 9; cnt++)
	{
		y = x >> cnt;
		printf("%d\t\t%d\t\t%d\n", x, cnt, y);
	}
		
	return 0;
}