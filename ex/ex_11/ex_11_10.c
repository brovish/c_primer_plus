#include <stdio.h>
int strlen2(char * str);
int main(void)
{
	char words[] = "Max make me happy\n max max    !";
	char *ptr = words;
	printf("%d\n", strlen2(ptr));
	return 0;
}

int strlen2(char * str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}
