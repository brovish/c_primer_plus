#include <stdio.h>
#include <string.h>
int main(void)
{
	typedef struct lens {
		float foclen;
		float fstop;
		char brand[30];
	} LENS;
	
	LENS arr[10];
	arr[2].foclen = 500.0f; 
	arr[2].fstop = 2.0f;
	strcpy(arr[2].brand, "Remarkartar");
	
	printf("%s %f %f\n", arr[2].brand, arr[2].foclen, arr[2].fstop);
	return 0;
}