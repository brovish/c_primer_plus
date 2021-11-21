#include <stdio.h>
int main(void)
{
	const char *mesg = "Dont't be a fool!";
	
	const char *copy;
	
	copy = mesg;
	
	printf("%s\n", copy);
	
	printf("mesg = %s; &mesg = %p; value = %p", 
		mesg, &mesg, mesg);
	printf("\ncopy = %s; &copy = %p; value = %p\n",
		copy, &copy, copy);
	
	
	return 0;
}