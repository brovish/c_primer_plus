#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define EXIT "CTRL+C"
#define LIM 1000
#define MAX_STR 10
#define STOP 5
#define SEP "----------------------------------------------"
void clear(void);
char * s_gets(char *str, int n);
void show_menu(void);
void print_choise(int val);
void print_list(char *str[]);
void sort_list_by_fword(char *str[], int num);
void sort_list_len(char *str[],int num);
int get_len_fword(char *str);
void sort_list(char *str[], int num);
int main(void)
{
	char strings[MAX_STR][LIM];
	int i = 0;
	char *ptr[MAX_STR];
	
	printf("Enter %d target strings (%s to exit):\n"
			,MAX_STR, EXIT);
	while (i < MAX_STR && s_gets(strings[i], LIM) != NULL)
	{
		ptr[i] = strings[i];
		++i;
		if ((MAX_STR - i) != 0)
			printf("Enter %d target strings (%s to exit):\n"
				,MAX_STR -i, EXIT);
		
	}
	
	clear();
	puts("please enter 1, 2, 3, 4, 5 values\n");
	show_menu();
	
	int scanf_r;
	int val;
	int stop = 0; 
		
	while (1)
	{
		scanf_r = scanf("%d", &val);
		while (getchar() != '\n')
			continue;
		if (scanf_r)
		{
			switch(val)
			{
				case 1 :
					print_choise(val);
					print_list(ptr);
					break;
				case 2 :
					print_choise(val);
					sort_list(ptr, i);
					break;
				case 3 :
					print_choise(val);
					sort_list_len(ptr, i);				
					break;
				case 4 :
					print_choise(val);
					sort_list_by_fword(ptr, i);
					break;
				case STOP:
					print_choise(val);
					stop = 1;
					break;
				default : 
					clear();
					puts("please enter 1, 2, 3, 4, 5 values\n");
					show_menu();
					continue;
					
			}
			
			if (stop) 
				break;
			else
			{
				puts("please enter 1, 2, 3, 4, 5 values\n");
				show_menu();
				continue;
			
			}	
		}
		else 
		{
			clear();
			puts("please enter 1, 2, 3, 4, 5 values\n");
			show_menu();
			continue;
		}	
	}
		
	return 0;
}

void sort_list_len(char *str[],int num)
{
	char *temp;
	char *ptr[MAX_STR];
	int i = 0;
	for (; i < num; i++)
		ptr[i] = str[i];	
	
	int top, seek;
	
	for (top = 0; top < num - 1; top++)
		for (seek = top + 1; seek < num; seek++)
		if (strlen(ptr[top]) > strlen(ptr[seek]))
		{
			temp = ptr[top];
			ptr[top] = ptr[seek];
			ptr[seek] = temp;
		}
	print_list(ptr);

}

void sort_list_by_fword(char *str[], int num)
{
	char *temp;
	int i;
	char *ptr[MAX_STR];
	for (i = 0; i < num; i++)
	{
		ptr[i] = str[i];	
	}
	
	int top, seek;
	
	for (top = 0; top < num - 1; top++)
		for (seek = top + 1; seek < num; seek++)
			if (get_len_fword(ptr[top]) 
				> get_len_fword(ptr[seek]))
			{
					temp = ptr[top];
					ptr[top] = ptr[seek];
					ptr[seek] = temp;
			}

			/*
			printf("ptr[%d]=%s;\nptr[%d]=%s;\n", 
				top, ptr[top], seek, ptr[seek]); 
			*/
		
	
	print_list(ptr);
		
}

int get_len_fword(char *str)
{
	char temp[LIM];
	memset(&temp[0], 0, sizeof(temp));
	int i, z, len;
	len = strlen(str);
	int inword = 0;
	
	for (i = 0, z = 0; i < len; i++)
	{
		if (!isalnum(str[i]) && inword)
		{
			temp[z] = 0;
			break;
		}
		if (isalnum(str[i]))
		{
			inword = 1;
			temp[z] = str[i];
			z++;		
		}
	}
	
	//printf("temp=%s;strlen(temp)=%lu;\n", temp, strlen(temp));
	
	return strlen(temp);
}

void sort_list(char *str[], int num)
{
	char *temp;
	char *ptr[MAX_STR];
	int i = 0;
	for (; i < num; i++)
		ptr[i] = str[i];	
	
	int top, seek;
	
	for (top = 0; top < num - 1; top++)
		for (seek = top + 1; seek < num; seek++)
		if (strcmp(ptr[top],ptr[seek]) > 0)
		{
			temp = ptr[top];
			ptr[top] = ptr[seek];
			ptr[seek] = temp;
		}
	print_list(ptr);
		
}

void print_list(char *str[])
{
	int i;
	puts(SEP);
	for (i =0; i < MAX_STR; i++)
		printf("%s\n", str[i]);
	puts(SEP);
}

void show_menu()
{
	//clear();
	puts(SEP);
	printf("1) print original list of strings.\n");
	printf("2) print the strings in original ASCII collatiog sequence.\n");
	printf("3) print the strings in order of increasing length.\n");
	printf("4) print the strings in order of length of the first word in the string.\n");
	printf("5) quit.\n");
	puts(SEP);
}

char * s_gets(char *str, int n)
{
	
	fgets(str, n, stdin);
	char *find;
	find = strchr(str, '\n');
	if (*find)
		*find = 0;
	return str;	
}

void print_choise(int val)
{
	printf("Enter:%d\n", val);
}

void clear(void)
{
	system("clear");
}