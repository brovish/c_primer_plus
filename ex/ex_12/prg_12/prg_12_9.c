#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SZ 1000
char * s_gets(char *str);
void printarr(char * str);
char * make_arr(void);
void print2arr(char **str, int len);


int main(void)
{
	
	int words;
	int i;
	printf("How many words do you wish to enter? ");
	scanf("%d", &words);
	while (getchar() != '\n')
		continue;
	printf("Enter %d words now:\n", words);
	char **ptrarr = (char **) malloc(words * sizeof(char));
	for (i = 0; i < words; i++)
	{
		
		char *str = (char *) malloc (MAX_SZ * sizeof(char));
		scanf("%s", str);
		ptrarr[i] = str;
	}	
	
	print2arr(ptrarr, i);
	
	free(ptrarr);
	
	return 0;
}

char * make_arr(void)
{
		
	//memset(&str[0], 0, sizeof(str));
	char *str = (char *) malloc (MAX_SZ * sizeof(char));

	s_gets(str);
	
	int len;
	
	len = strlen(str);
	
	char *ptrw;
	ptrw = (char *) malloc (len + 1); 
	int i;
	
	for (i = 0; i < len; i++)
	{
		ptrw[i] = str[i];
	}
	
	ptrw[i] = 0;
	printf("ptrw=%p (%s);str=%p (%s)\n", ptrw, ptrw, 
		str, str);
	return ptrw;
}

char * s_gets(char *str)
{

        fgets(str, MAX_SZ, stdin);
        char *find;
        find = strchr(str, '\n');
        if (*find)
                *find = 0;
        return str;
}

void print2arr(char **str, int len)
{
	printf("Here are your words:\n");
	for (int i = 0; i < len; i++)
		printf("arr[%d]=%s (%p)\n", i, str[i], str[i]);
		
}

void printarr(char * str)
{
	printf("len=%lu;str=%s;\n", strlen(str), str);
		
}

