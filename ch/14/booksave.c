#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;	
};

char * s_gets(char *, int);

int main(void)
{
	
	struct book library[MAXBKS];
	int cnt = 0;
	int idx, filecount;
	FILE *fp;
	int size = sizeof(struct book);
	
	if ((fp = fopen("book.dat", "a+b")) == NULL)
	{
		fprintf(stderr, "Can't open file \"book.dat\"\n.");
		exit(1);
	}
	
	rewind(fp);
	
	while (cnt < MAXBKS && fread(&library[cnt], size, 1, fp) == 1)
	{
		if (cnt == 0)
			puts("Current content of \"book.data\":");
		printf("%s by %s: $%.2f\n", library[cnt].title, 
			library[cnt].author, library[cnt].value);
		cnt++;
	}
	
	filecount = cnt;
	if (cnt == MAXBKS)
	{
		fputs("The \"book.dat\" file is full.\n", stderr);
		exit(2);
	}	
	
	puts("Please add new book titles.");
	puts("Press [enter] at the start of a line to stop.");
	
	while (cnt < MAXBKS && s_gets(library[cnt].title, MAXTITL) != NULL
		&& library[cnt].title[0] != 0)
	{
		puts("Enter the author.");
		s_gets(library[cnt].author, MAXAUTL);
		puts("Now enter the price.");
		scanf("%f", &library[cnt++].value);
		while (getchar() != '\n')
			continue;
		if (cnt < MAXBKS)
			puts("Enter next title.");
	}
	
	if (cnt > 0)
	{
		puts("Here is the list of your books:");
		for (idx = 0; idx < cnt; idx++)
			printf("%s by %s: $%.2f.", 
				library[idx].title, 
				library[idx].author, 
				library[idx].value);
		fwrite(&library[filecount], size, cnt - filecount, fp);
	}
	else puts("No books? Bad.");
	fclose(fp);
	puts("Buy.");
	
	return 0;
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