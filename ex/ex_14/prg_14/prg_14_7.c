#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 20

struct book {
        char title[MAXTITL];
        char author[MAXAUTL];
        float value;
};

char * s_gets(char *, int);
void toLower(char * st);
void eat_line(void);

int main(void)
{

        struct book library[MAXBKS];
        struct book actual_lib[MAXBKS];
        int cnt = 0;
        
        int cnt_actual = 0;
        int idx = 0;
        FILE *fp;
        int size = sizeof(struct book);

        if (access("book.dat", F_OK) == 0)
        {
       		//puts("file exists");
       		if ((fp = fopen("book.dat", "r+b")) == NULL)
        	{
                	fprintf(stderr, "Can't open file \"book.dat\"\n.");
                	exit(1);
        	}
        }
       	else
       	{
       		if ((fp = fopen("book.dat", "a+b")) == NULL)
        	{
                	fprintf(stderr, "Can't open file \"book.dat\"\n.");
                	exit(1);
        	}
        	rewind(fp);
        	
       	} 
        
	char answer[10];		
	
	while (cnt < MAXBKS && fread(&library[cnt], size, 1, fp) == 1)
        {
                if (cnt == 0)
                        puts("Current content of \"book.data\":");
                printf("%d) %s by %s: $%.2f.\n", 
                	cnt + 1, library[cnt].title,
                	library[cnt].author, library[cnt].value);
               	cnt++;
        }
	
	cnt = 0; rewind(fp);
		
        while (cnt < MAXBKS && fread(&library[cnt], size, 1, fp) == 1)
        {
                printf("%s by %s: $%.2f.\nDelete or change this book? \"yes\" to delete \"change\" to change (empty line to keep current book): ", library[cnt].title,
                        library[cnt].author, library[cnt].value);
              
                s_gets(answer, 10);
                toLower(answer);
                
                //printf("char %c\n", answer[0]);
                
                if (answer[0] == '\0')
                {
                	actual_lib[cnt_actual++] = library[cnt];
                	continue;
                	
                }	
                //eat_line();	
                if (strcmp(answer, "change") == 0)
                {
                     	
                	puts("Enter the title.");
                     	s_gets(actual_lib[cnt_actual].title, MAXTITL);
        		puts("Enter the author.");
                	s_gets(actual_lib[cnt_actual].author, MAXAUTL);
			puts("Now enter the price.");
			scanf("%f", &actual_lib[cnt_actual++].value);
			eat_line();
                	actual_lib[cnt_actual++] = library[cnt];
                }
        	cnt++;
        }
	
	fclose(fp);
        
        //filecount = cnt_actual;
        
        if (cnt_actual == MAXBKS)
        {
                fputs("The \"book.dat\" file is full.\n", stderr);
                exit(2);
        }
	
	if ((fp = fopen("book.dat", "w+b")) == NULL)
        {
               	fprintf(stderr, "Can't open file \"book.dat\"\n.");
               	exit(1);
        }
	
	
        puts("Please add new book titles.");
        puts("Press [enter] at the start of a line to stop.");
	
	
	while (cnt_actual < MAXBKS && s_gets(actual_lib[cnt_actual].title, MAXTITL) != NULL
		&& actual_lib[cnt_actual].title[0] != '\0')
	{
		puts("Now enter the author.");
		s_gets(actual_lib[cnt_actual].author, MAXAUTL);
		puts("Now enter the value.");
		scanf("%f", &actual_lib[cnt_actual++].value);
		eat_line();
		if (cnt_actual < MAXBKS)
			puts("Enter the text title.");
	}
		
	//printf("cnt=%d\n", cnt);
        //rewind(fp);
        if (cnt_actual > 0)
        {
                puts("Here is the list of your books:");
                for (idx = 0; idx < cnt_actual; idx++)
                        printf("%d) %s by %s: $%.2f.\n",
                                idx + 1,
                                actual_lib[idx].title,
                                actual_lib[idx].author,
                                actual_lib[idx].value);
                fwrite(&actual_lib[0], size, cnt_actual, fp);
        }
        else puts("No books? Bad.");
        fclose(fp);
        puts("Buy.");

        return 0;
}

void eat_line(void)
{
	while (getchar() != '\n')
		continue;
}

void toLower(char * st)
{
	while (*st)
	{
		*st = tolower(*st);
		st++;
	}	
}

char * s_gets(char * st, int n)
{
        char *ret_val;
        char *find;
        ret_val = fgets(st, n, stdin);
        if (ret_val)
        {
                find = strchr(st, '\n');
                if (find)
                        *find = 0;
                else
                        while (getchar() != '\n')
                                continue;
        }

        return ret_val;
}