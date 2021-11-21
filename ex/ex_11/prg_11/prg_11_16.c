#include <stdio.h>
#include <ctype.h>
#include <string.h>
int check_flags(char *str, int argc);
char get_flag(char *str, int argc);
void print_help(char *str);
int main(int argc, char *argv[])
{
		
	char flg = 0;
	
	int chfl = 0;
	chfl = check_flags(argv[1], argc);
	
	//printf("flags ok: %d\n", chfl);
	
	if (chfl)
	{
		flg = get_flag(argv[1], argc);
		//printf("flag is: %c\n", flg);
		if (flg == 'h')
		{	
			print_help(*argv);
			return 0;
		}	
	
		char ch = 0;	
		while (1)
		{
			
			ch = getchar();
			
			if (ch == EOF)
				break;
			
			if (flg == 'u')
				ch = toupper(ch);
			if (flg == 'l')
				ch = tolower(ch);		
			printf("%c", ch);
						
		}
		
	}
	else 
	{
		print_help(*argv);
		return -1;
	}
	
	puts("");
	
	return 0;
	
}

int check_flags(char *str, int argc)
{
	
	return (
		(argc == 1) ||
		((strlen(str) == 2) && (str[0] == '-') 
		&& ((str[1] == 'p') || 
		    (str[1] == 'u') ||
		    (str[1] == 'l') ||
		    (str[1] == 'h'))
		)) ? 1 : 0;
}

char get_flag(char *str, int argc)
{
	
	char ch = 0;
	
	if (argc == 1)
	{
		ch = 'p';
		return ch;
	}
	if (str[1] == 'p')
		ch = 'p';
	if (str[1] == 'l')
		ch = 'l';
	if (str[1] == 'u')
		ch = 'u';
	if (str[1] == 'h')
		ch = 'h';
	
	return ch;
	
}

void print_help(char *str)
{

	printf("Usage: %s \n-p [print input as is]\n"
		"-u [Map input to all uppercase]\n"
		"-l [Map input to all lowercase]\n"
		"-h [Print help]\n"
		"default: -p\n", str);
	
}