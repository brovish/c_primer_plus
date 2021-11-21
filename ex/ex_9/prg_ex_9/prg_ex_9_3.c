#include <stdio.h>

void chline(char ch, int i, int j);

int main(void)
{
    char ch;
    int i, j;
    
    while ((scanf("%c %d %d", &ch, &i, &j) == 3))
    {
	//printf("%d %d %d\n", ch, i, j);
	//scanf("%*s");
	chline(ch, i, j);
	while ((ch = getchar()) != '\n');
	    ;
	if (ch == EOF)
	    break;
    }
    
    return 0;
}


void chline(char ch, int i, int j)
{
    int x, y;
    for (x = 0; x < i; x++)
    {
	for (y = 0; y < j; y++)
	    printf("%c", ch);
	putchar('\n');
    }
    //putchar('\n');
}