/* two_func.c --a program using two functions */
#include <stdio.h>
void butler(void); /* ANSI/ISO C function prototyping*/
int main (void)
{
	printf("I will summon the butler function\n");
	butler();
	printf("Yes. Bring me some tea and writeable DVD's\n");

	return 0;
}

void butler(void)
{
	printf("You rang, sir?\n");

}
