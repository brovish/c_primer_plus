#include <stdio.h>
int main(void)
{
	char ch = 'A';	
	float f = 2.34E07;
	long l = 6L;
	float fl = 0x5.b6p12;

	int octal = 012;

	int hex = 0x44;

	printf("%c\n", ch);
	printf("%#o\n", octal);
	printf("%#x\n", hex);
	printf("%e\n", f);
	printf("%ld\n", l);
	printf("%fl\n", fl);
	
	return 0;
}
