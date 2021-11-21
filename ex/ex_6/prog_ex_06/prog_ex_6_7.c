#include <stdio.h>
int main(void)
{
    char word[100];
    //char ch;
    int i;
    printf("Enter word: \n");
    
    scanf("%s", word);
    
    for (i = strlen(word); i >= 0; i--)
	printf("%c", word[i]);
    printf("\n");
    return 0;
    
}