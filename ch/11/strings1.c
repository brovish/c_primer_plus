#include <stdio.h>
#define MSG "I am a symbolic string constant."
#define MAX_LENTGH 81
int main(void)
{
	
	char words[MAX_LENTGH] = "I am a string in array.";
	const char *pt1 = "Something is pointing at me";
	
	puts("Here are some strings:");
	puts(MSG);
	puts(words);
	puts(pt1);
	words[8] = 'p';
	puts(words);
	
	return 0;
}