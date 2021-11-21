#include <stdio.h>
#include <ctype.h>
char get_first(void);
int main(void)
{
    char ch;
    ch = get_first();
    putchar(ch);
    return 0;
}


char get_first(void)
{
    int ch = 0;
    int i = 0;
    char chbuf[100];
    int size;
    
    scanf("%s", chbuf);
    
    size = (int)(sizeof(chbuf) / sizeof(chbuf[0]));
    
    //printf("size:%d\n", size);
    
    for (i = 0, ch = 0; i < sizeof (chbuf); i++)
    {
	//printf("%d\n", chbuf[i]);
	if (!isblank(chbuf[i]))
	{
	    ch = chbuf[i];
	    break;
	}
    }
    //printf("%d\n", ch);
    return ch;
}