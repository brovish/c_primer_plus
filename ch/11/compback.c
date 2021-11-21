#include <stdio.h>
#include <string.h>

int main(void)
{
	printf("strcmp(\"A\", \"A\") is ");
	printf("%d\n", strcmp("A", "A"));
	
	printf("strcmp(\"A\", \"B\") is ");
	printf("%d\n", strcmp("A", "B"));
	
	printf("strcmp(\"B\", \"A\") is ");
	printf("%d\n", strcmp("B", "A"));
	
	printf("strcmp(\"C\", \"A\") is ");
	printf("%d\n", strcmp("C", "B"));
	
	printf("strcmp(\"Z\", \"a\") is ");
	printf("%d\n", strcmp("Z", "a"));
	
	printf("strcmp(\"apple\", \"apples\") is ");
	printf("%d\n", strcmp("apple", "apples"));
	
	return 0;
}