#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 81

char * s_gets(char *, int);
char showmenu(void);
void eatline(void);
void show(void (*fp)(char *), char  *str);
void ToUpper(char *);
void ToLower(char *);
void Transpose(char *);
void Dummy(char *);

int main (void)
{
	char line[LEN];
	char copy[LEN];
	char choice;
	void (*fp)(char *);
	
	puts("Enter a string (empty line to quit):");
	while (s_gets(line, LEN) != NULL && line[0] != 0)
	{
		while ((choice = showmenu()) != 'n')
		{
			switch (choice)
			{
				case 'u' : fp = ToUpper; break;
				case 'l' : fp = ToLower; break;
				case 't' : fp = Transpose; break;
				case 'o' : fp = Dummy; break;
			}
			strcpy(copy, line);
			show(fp, copy);
		}
		puts("Enter a string (empty line to quit):");
	}
	
	puts("Bye!");
	
	return 0;
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;
	
	ret_val = fgets(st, n, stdin);
	
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = 0;
		else eatline();
	}
	return ret_val;
}

char showmenu(void)
{
	char ans;
	puts("Enter menu choice:");
	puts("u) uppercase	   l) lowercase");
	puts("t) transposed case o) original case");
	puts("n) next string");
	ans = tolower(getchar());
	eatline();
	while (strchr("ulton", ans) == NULL)
	{
		puts("Please enter a, u, l, t, o or n:");
		ans = tolower(getchar());
		eatline();
	}
	
	
	return ans;
}

void eatline(void)
{
	while (getchar() != '\n')
		continue;
}

void show(void (*fp)(char *), char  *str)
{
	(*fp)(str);
	puts(str);
}

void ToUpper(char * st)
{
	while (*st)
	{
		*st = toupper(*st);
		st++;
	}
}

void ToLower(char * st)
{
	while (*st)
	{
		*st = tolower(*st);
		st++;
	}
}

void Transpose(char * st)
{
	while (*st)
	{
		if (islower(*st))
			*st = toupper(*st);
		else if (isupper(*st))
			*st = tolower(*st);
		st++;
	}
}

void Dummy(char * st){}
