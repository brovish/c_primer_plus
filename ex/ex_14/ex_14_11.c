#include <stdio.h>
int main(void)
{	
	enum tag {yes, no, maybe};
	
	enum tag t;
	
	for (t = yes; t <= maybe; t++)
		printf("%u\n", t);
		
	return 0;
}