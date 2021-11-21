#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char ch;
    int isword = 0;
    float avg_chars = 0.0f;
    int count_words = 0;
    int chars_in_word = 0;
    
    while ((scanf("%c", &ch)) != EOF)
    {
	if (!ispunct(ch))
	{
	    if (isalnum(ch))
	    {
		chars_in_word++;
		isword = 1;
	    }
	    
	    if (ch == 32 && isword)
	    {
	        count_words++;
	        isword = 0;
	    }
	}
    }
    
    if (isword)
	count_words++;
    
    if (chars_in_word == 0)
	avg_chars = 0.0f;
    else
        avg_chars = (float) chars_in_word/count_words;
    
    printf("\nsum_chars:%d;words:%d;avg_chars_per_word:%0.2f\n", 
	chars_in_word, count_words, avg_chars);
    
    return 0;
}