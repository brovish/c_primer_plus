#include <stdio.h>
int main(void)
{
	float inch;
	printf("inter inch value and press ENTER key:\n");
	scanf("%f", &inch);
	printf("santimeters value: %0.2f\n", inch*2.54);
	getchar();
	return 0;
}
