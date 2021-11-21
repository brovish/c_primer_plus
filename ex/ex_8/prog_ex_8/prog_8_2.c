#include <stdio.h>
int main(void)
{
    
    int ch;
    int line_counter = 0;
    //int ch_code;
    
    //while (scanf("%c", &ch) != EOF)
    while ((ch = getchar()) != EOF)
    {
	//if (ch < 0)
	if (line_counter % 10 == 0)
	    printf("\n");
	
	switch (ch)
	{
	case'\n':
	    printf("\\n%d\n", ch);
	    break;
	case'\t':
	    printf("\\t%d ", ch);
	    break;
	default:
	    if (ch < 32)
		printf("^%c%d", ch + 'A' + 64, ch);
	    else 
		printf("%c%d", ch, ch);
	    break;
	}
	line_counter++;
    }
    printf("\n");
    return 0;
}