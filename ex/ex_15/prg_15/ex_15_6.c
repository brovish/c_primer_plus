#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define QUIT 'q'

struct font {
	unsigned int fal : 2;
	bool bold : 1;
	bool underline : 1;
	unsigned int : 4;
	unsigned int fid : 8;
	unsigned int fsize : 7;
	bool italic : 1;
};

const char * alignment[3] = {"left", "center", "right"};
const char * state[2] = {"off", "on"}; 

void eat_line(void);
char get_menu_choose_main(void);
char get_menu_choose_al(void);
void menu(void);
void font_print(const struct font *);

void enter_fid(struct font *);
void enter_alignment(struct font * f);
void enter_fsize(struct font *);
void toogle_bold(struct font *);
void toogle_italic(struct font *);
void toogle_underline(struct font *);

int main(void)
{
	struct font f = {0, 0, 0, 1, 12, 0};
	//printf("sizeof font=%lu\n", sizeof(f));
	char ch = 0;
	
	font_print(&f);
	menu();
	
	while (true)
	{
		ch = get_menu_choose_main();
		switch (ch)
		{
			case 'a' : 
				enter_alignment(&f);
				break;
			case 's' : 
				enter_fsize(&f);
				break;
			case 'f' : 
				enter_fid(&f);
				break;
			case 'b' : 
				toogle_bold(&f);
				break;
			case 'i' : 
				toogle_italic(&f);
				break;
			case 'u' : 
				toogle_underline(&f);
				break;	
		}
		
		if (ch == QUIT)
			break;
		
		menu();
		font_print(&f);
	}
	
	return 0;
}

void enter_alignment(struct font * f)
{
	
	printf("Select alignment:\n");
	printf("l) left c) center r) right\n");
	char ch = get_menu_choose_al();
	
	switch (ch)
	{
		case 'l' : 
			f->fal = 0;		
			break;
		case 'c' : 
			f->fal = 1;
			break;
		case 'r' : 
			f->fal = 2;
			break;
	}        	
}

void enter_fid(struct font * f)
{
	printf("Enter font id: (0-255): ");
	unsigned int fid;

        while (scanf("%ud", &fid) != 1 || !(fid >= 0 && fid <= 255))
        { 
               puts("Please enter value between 0 and 255");
               eat_line();
        }
        eat_line();
        f->fid = fid;	
}

void enter_fsize(struct font * f)
{
	printf("Enter size: (0-127): ");
	unsigned int fsize;

        while (scanf("%ud", &fsize) != 1 || !(fsize >= 0 && fsize <= 127))
        { 
               puts("Please enter value between 0 and 127");
               eat_line();
        }
        eat_line();
        f->fsize = fsize;	
}

void toogle_bold(struct font * f)
{
	if (f->bold)
		f->bold = false;
	else
		f->bold = true;
}

void toogle_italic(struct font * f)
{
	if (f->italic)
		f->italic = false;
	else
		f->italic = true;
}

void toogle_underline(struct font * f)
{
	if (f->underline)
		f->underline = false;
	else
		f->underline = true;
}

char get_menu_choose_al(void)
{
        char ch;
        ch = getchar();
        ch = tolower(ch);
        eat_line();
        while (strchr("lcr", ch) == NULL)
        {
                puts("Please enter l, c or r.");
                ch = tolower(getchar());
                eat_line();
        }

        return ch;

}

char get_menu_choose_main(void)
{
        char ch;
        ch = getchar();
        ch = tolower(ch);
        eat_line();
        while (strchr("asfbiuq", ch) == NULL)
        {
                puts("Please enter a, s, f, b, i, u or q.");
                ch = tolower(getchar());
                eat_line();
        }

        return ch;
}

void eat_line(void)
{
	while (getchar() != '\n')
		continue;
}

void font_print(const struct font * f)
{
	printf("\nID SIZE ALIGNMENT 	B  I  U\n");
	printf("%2d %4d %6s %11s %s %s\n"
	,f->fid, f->fsize, alignment[f->fal], state[f->bold], 
		state[f->italic], state[f->underline]);
}

void menu(void)
{
	printf("f) change font s) change size   a) change alignment\n");
	printf("b) toggle bold i) toggle italic u) toogle underline\n");
	printf("q) quit\n");
}