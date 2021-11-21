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
    }
    
    return 0;
}


void chline(char ch, int i, int j)
{
    for (; i <= j; i++)
    {
        printf("%c\t", ch);
    }
}