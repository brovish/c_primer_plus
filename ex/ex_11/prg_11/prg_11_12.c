#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char ch;
	int inword = 0;
	int wc = 0;
	int uppers = 0;
	int lowers = 0;
	int punc = 0;
	int digits = 0;
	int alnum = 0;
	int digit = 0;
	while (1)
	{
		ch = getchar();
		alnum = isalnum(ch);
		digit = isdigit(ch);
		if (!alnum && inword)
                {
                        inword = 0;
                        wc++;
                }

                if (alnum && !digit)
                        inword = 1;
                if (islower(ch))
                	lowers++;
                if (isupper(ch))
                	uppers++;
                if (ispunct(ch))
                	punc++;	
                if (digit)
                	digits++;
                if (ch == EOF)
                	break;
	}
	
	printf("words=%d;\nuppercase letters=%d;\n"
	"lowercase letter=%d;\npunctuations=%d;\ndigits=%d\n", wc,
		uppers, lowers, punc, digits);
	
	return 0;
}
