#include <stdio.h>
#include <ctype.h>
#define STOP '#'
int main(void)
{
    char ch;
    
    printf("Give a letter of the alphabet, and I will give ");
    printf("an animal name\nbegging with that letter.\n");
    
    while ((ch = getchar()) != STOP)
    {
	if (ch == '\n')
	    continue;
	if (islower(ch))
	{   
	    switch (ch)
	    {
		case 'a' :
		    printf("argali, a wild sheep of Asia\n");
		    break;
		case 'b' :
		    printf("babirusa, a wild pig of Maly\n");
		    break;
		case 'c' :
		    printf("coati, racconlike mammal\n");
		    break;
		case 'd' :
		    printf("desman, aquatic, molelike critter\n");
		    break;
		case 'e' :
		    printf("echidna, the spiny anteater\n");
		    break;
		case 'f' :
		    printf("fisher, brownish marten\n");
		    break;
		default :
		    printf("That's a stumper!\n");
	    }
	}
	else
	    printf("I recognize only lowercase letters.\n");
	while (getchar() != '\n')
	    continue;
	printf("Please enter another letter or a #.\n");
    }
    
    printf("Done buy.\n");
    
    return 0;
}
