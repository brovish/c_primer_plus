#include <stdio.h>
void binprintf(int v);
int main(void)
{
	char ch;
	printf("Please enter char: \n");
	scanf("%c", &ch);
	printf("Char: %c Code: %d\n", ch, ch);
	binprintf(ch);
	return 0;
}

void binprintf(int v)
{
    unsigned int mask=1<<((sizeof(int)<<3)-1);
    while(mask) {
        printf("%d", (v&mask ? 1 : 0));
        mask >>= 1;
    }
    printf("\n");
}

