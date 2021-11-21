#include <stdio.h>

#if __STDC_VERSION__ != 201112L
	#error Not C11
#endif

void why_me(void);

int main(void)
{
	printf("The file is %s.\n", __FILE__);
	printf("The date is %s.\n", __DATE__);
	printf("The time is %s.\n", __TIME__);
	printf("The version is %ld.\n", __STDC_VERSION__);
	printf("The line is %d.\n", __LINE__);
	printf("The function is %s.\n", __func__);
	
	why_me();
	
	return 0;
}

void why_me(void)
{
	printf("This function is %s\n", __func__);
	printf("The line is %d.\n", __LINE__);
}