#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define QUIT 'q'

#define ID_MASK     0xFF
#define SIZE_MASK   0x7F00
#define LEFT        0x00000
#define CENTER      0x08000
#define RIGHT       0x10000
#define ALIGN_MASK  0x18000
#define REGULAR     0x00000
#define BOLD        0x20000
#define ITALIC      0x40000
#define UNDERLINE   0x80000
#define STYLE_MASK  0xE0000
#define SIZE_SHIFT  8

typedef unsigned long font;

void eat_line(void);
char get_menu_choose_main(void);
char get_menu_choose_al(void);
void menu(void);
void font_print(const font);

void enter_fid(font *);
void enter_alignment(font * f);
void enter_fsize(font *);
void toogle_bold(font *);
void toogle_italic(font *);
void toogle_underline(font *);

int main(void)
{
	font f = 1 | (12 << SIZE_SHIFT) | LEFT;
	char ch = 0;
	
	font_print(f);
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
		font_print(f);
	}
	
	return 0;
}

void enter_alignment(font * f)
{
	
	printf("Select alignment:\n");
	printf("l) left c) center r) right\n");
	char ch = get_menu_choose_al();
	
	switch (ch)
	{
		case 'l' : 
			*f &= ~ALIGN_MASK;
			*f |= LEFT;
			break;
		case 'c' :
			*f &= ~ALIGN_MASK;
			*f |= CENTER;	 
			break;
		case 'r' :
			*f &= ~ALIGN_MASK;
			*f |= RIGHT; 
			break;
	}        	
}

void enter_fid(font * f)
{
	printf("Enter font id: (0-255): ");
	unsigned int fid;

        while (scanf("%ud", &fid) != 1 || !(fid >= 0 && fid <= 255))
        { 
               puts("Please enter value between 0 and 255");
               eat_line();
        }
        eat_line();
        *f &= ~ID_MASK;
        *f |= fid & ID_MASK;
}

void enter_fsize(font * f)
{
	printf("Enter size: (0-127): ");
	unsigned int fsize;

        while (scanf("%ud", &fsize) != 1 || !(fsize >= 0 && fsize <= 127))
        { 
               puts("Please enter value between 0 and 127");
               eat_line();
        }
        eat_line();
        
        //printf("%lu\n", (*f & SIZE_MASK) >> SIZE_SHIFT);
        *f &= ~SIZE_MASK;
	*f |= (fsize << SIZE_SHIFT) & SIZE_MASK;
	
	//printf("%lu\n", (*f & SIZE_MASK) >> SIZE_SHIFT);
}

void toogle_bold(font * f)
{
	*f ^= BOLD;
}

void toogle_italic(font * f)
{
	*f ^= ITALIC;
}

void toogle_underline(font * f)
{
	*f ^= UNDERLINE;
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

void font_print(const font f)
{
	printf("\nID SIZE ALIGNMENT 	B  I  U\n");
	printf("%4lu %4lu", f & ID_MASK, (f & SIZE_MASK) >> SIZE_SHIFT);
    	switch (f & ALIGN_MASK)
    	{
        	case LEFT   : printf("%7s", "left"); break;
        	case RIGHT  : printf("%7s", "right"); break;
        	case CENTER : printf("%7s", "center"); break;
        	default     : printf("%7s", "unknown"); break;
    	}
   	 printf("%8s %3s %3s\n\n", (f & BOLD) == BOLD ? "on" : "off",
           	(f & ITALIC) == ITALIC ? "on" : "off",
           	(f & UNDERLINE) == UNDERLINE ? "on" : "off");
}

void menu(void)
{
	printf("f) change font s) change size   a) change alignment\n");
	printf("b) toggle bold i) toggle italic u) toogle underline\n");
	printf("q) quit\n");
}