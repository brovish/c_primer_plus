#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show(void (*fp[])(char *), char * st);
void show_menu(void);
char get_menu_choose(void);
void fn1(char * st);
void fn2(char * st);
void fn3(char * st);
void fn4(char * st);

int main(void)
{
	
	int exit = 0;
	char ch;
	void (*fp[4])(char *) = {fn1, fn2, fn3, fn4};
	system("clear");
		
	while (!exit)
	{
		show_menu();
		ch = get_menu_choose();
		switch (ch)
		{
			case 'a':
				show(&fp[0], "fn1");
				break;
			case 'b':
				show(&fp[1], "fn2");
				break;
			case 'c':
				show(&fp[2], "fn3");
				break;
			case 'd':
				show(&fp[3], "fn4");
				break;
			case 'e':
				exit = 1;
				break;
		}
	}
	return 0;
}

char get_menu_choose(void)
{
	char ch;
	ch = getchar();
	while (getchar() != '\n')
		continue;
	if (strchr("abcde", ch) == 0)
	{
		puts("Please enter a, b, c, d or e.");
		ch = getchar();
		while (getchar() != '\n')
			continue;
	}
	return ch;
}

void show(void (*fp[])(char *), char * st)
{
	(*fp)(st);	
}

void fn1(char * st)
{
	printf("%s\n", st);
}

void fn2(char * st)
{
	printf("%s\n", st);
}

void fn3(char * st)
{
	printf("%s\n", st);
}

void fn4(char * st)
{
	printf("%s\n", st);
}

void show_menu(void)
{
	
	puts("Choose from menu:");
	puts("a) fn1");
	puts("b) fn2");
	puts("c) fn3");
	puts("d) fn4");
	puts("e) exit");	
	
}