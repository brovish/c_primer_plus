#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char ch;
    int chars; int lower; int upper;
    chars = lower = upper = 0;
    
    while (scanf("%c", &ch) != EOF)
    {
	if (ch > 31 && ch < 256)
	{
	    if (islower(ch) )
		lower++;
	    if (isupper(ch))
		upper++;
	    chars++;
	}
    }
    
    printf("Lower case: %d, upper: %d, chars:%d\n",
	lower, upper, chars);
    
    return 0;
}