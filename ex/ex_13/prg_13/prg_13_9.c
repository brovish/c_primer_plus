#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define MAX 41

int get_num(char *words, char *number, int len, FILE *fp);

int main(void)
{
	
	FILE *fp;
	char words[MAX];
	int num = 1;
	char ch = 0;
	char number[MAX];
	int isfile = 1;
	
	if ((fp = fopen("wordy", "r")) == NULL)
	{	
		if (errno != 2)
		{
			fprintf(stderr, "Can't open \"wordy\" file (errno=%d)\n", errno);
			exit(EXIT_FAILURE);
		}
		isfile = 0;
	}
	
	if (isfile)	
		num = get_num(words, number, MAX, fp) + 1;	
	else
		num = 1;
		
	if (!num)
	{
		fprintf(stderr, "Wrong numeration in \"wordy\" file\n");
		exit(EXIT_FAILURE);
	}
	
	//printf("num=%d\n", num);
	
	if ((fp = fopen("wordy", "a+")) == NULL)
	{
		fprintf(stderr, "Can't open \"wordy\" file\n");
		exit(EXIT_FAILURE);
	}
	
	puts("Enter words to add to the file; press #");
	puts("key at the beginnig of a line to terminate.");
	
	while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
	{
		fprintf(fp, "%d) %s\n", num++, words);
	}
	
	puts("File contents:");
	rewind(fp);
	while ((ch = getc(fp)) != EOF)
		putchar(ch);
	
	puts("Done.");
	
	if (fclose(fp) != 0)
		fprintf(stderr, "Error closing file\n");
	
	return 0;
}

int get_num(char *words, char *number, int len, FILE *fp)
{
	int numloc = 0;
	int i = 0;
	char *find;
	char *ptr = words;
	while ((ptr = fgets(words, MAX, fp)) != NULL)
	{
		//printf("%s", ptr);
		find = strchr(words, ')');
		if (find)
		{
			numloc =  find - ptr;
			for (i = 0; i < numloc; i++, ptr++)
				number[i] = *ptr;
			number[i] = 0;
		
			numloc = (int)strtol(number, NULL, 10);
		}	
	}
	
	if (fclose(fp) != 0)
		fprintf(stderr, "Error closing file\n");
	
	return numloc;
}