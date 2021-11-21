#include <stdio.h>
int main(void)
{
	char alert = '\007';
	char alert2 = '\07';
	char alert3 = '\7';
	char beep = 7;
	printf("\a");
	printf("%c", &alert);
	printf("%c", &alert2);
	printf("%c", &alert3);
	printf("%c", &beep);
	return 0;
}
