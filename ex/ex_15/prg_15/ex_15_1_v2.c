#include <stdio.h>
#include <stdbool.h>
#define ON '1'
#define OFF '0'

int cnv_char_to_int(char * st);
bool is_valid(char * st);

int main(void)
{
	char * pbin = "00011000";
	printf("input is %s\n",
		 is_valid(pbin) ? "is valid" : "not valid");
	printf("%s=%d\n", pbin, cnv_char_to_int(pbin));
}

bool is_valid(char * st)
{
	bool valid = false;
	
	while (*st)
	{
		if (*st == ON || *st == OFF)
		{
			valid = true;
		}
		st++;
	}
	
	return valid;
}

int cnv_char_to_int(char * st)
{
	int val = 0;

 	while (*st)
 	{
 		//printf("2*%d+(%d)=%d\n"
 		//, 2 * val , (*st - '0'), 2 * val + (*st - '0'));
 		val = 2 * val + (*st++ - '0');
  	}
        
    	return val;
}

