#include <stdio.h>

int main(void)
{
	typedef struct lens {
		float foclen;
		float fstop;
		char brand[30];
	} LENS;
	
	LENS arr[10] = {{}, {}, {.foclen = 500.0f, 
		.fstop = 2.0f, .brand = "Remarkatar"}};
	printf("%s %f %f\n", arr[2].brand, arr[2].foclen, arr[2].fstop);
	return 0;
}