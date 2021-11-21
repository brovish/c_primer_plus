#include <stdio.h>
#include <ctype.h>
#include <string.h>

long atoi2(char *str);

int main(int argc, char *argv[])
{
	
	if (argc < 2)
	{
                printf("Usage: %s [some string]\n",
                        *argv);
        	return -1;
	}
	
	long isint;
	char *ptr;
	ptr = argv[1];
	
	printf("ptr=%s\n", ptr);
	
	isint = atoi2(ptr);
	
	printf("string \"%s\" is %s number.\n"
	"string %s is number %lu\n", 
		ptr, isint ? "" : "not",
		ptr, isint);
	
	return 0;
}

long atoi2(char *str)
{
	int len;
	len = strlen(str);
	int isdigits = 1;
	long total = 0;	
	for (int i = 0; i < len; i++)
	{
		
		//printf("str[%d]=%c;\n", i , str[i]);
		
		if (!isdigit(str[i]))
		{
			isdigits = 0;
			break;
		}
		
		total = (total << 3) + (total << 1) + str[i] - '0';
		
		
		//printf("str[%d]=%c;total=%d;i=%d;\n"
		//	, i , str[i], total, i);	
	}
		
	return isdigits ? total : isdigits;
	
}