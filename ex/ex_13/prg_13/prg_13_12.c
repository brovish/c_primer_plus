#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROWS 20
#define COLS 30

void add_ch_data(char arr[][COLS + 1], const int data[][COLS], int rows, int cols);
void print_data(int arr[][COLS], int rows, int cols);
void print_ch_data(char arr[][COLS + 1], int rows, int cols);

int main(void)
{
	FILE *fp;
	long cnt = 1L;
	long last;
	char ch = 0;
	char *chp = &ch;
	int i = 0; 
	int j = 0;
	int data[ROWS][COLS];
	char chdata[ROWS][COLS + 1];
	if ((fp = fopen("input.graph", "rb")) == NULL)
	{
		fprintf(stderr, "Can't open file \"input.graph\"\n");
		exit(EXIT_FAILURE);
	}
	
	fseek(fp, 0L, SEEK_END);
	last = ftell(fp);
	rewind(fp);	
	
	while (cnt <= last)
	{
		ch = getc(fp);
		if (ch != ' ')
		{	
			
			data[i][j] = (int)strtol(chp, NULL, 10);
			j++;
			if (j > COLS)
			{
				i++;
				j = 0;
			}	
		}
		fseek(fp, cnt, SEEK_SET);
		cnt++;
	}
	
	if (fclose(fp) != 0)
		fprintf(stderr, "Error closing file \"input.graph\"\n");
	
	add_ch_data(chdata, data, ROWS, COLS);
	print_ch_data(chdata, ROWS, COLS + 1);
	
	
	return 0;
}

void print_data(int arr[][COLS], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%d", arr[i][j]);			
		}
		puts("");
	}
}


void print_ch_data(char arr[][COLS + 1], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%c", arr[i][j]);			
		}
		puts("");
	}
}

void add_ch_data(char arr[][COLS + 1], const int data[][COLS], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			switch (data[i][j])
			{
				case 0 :
					arr[i][j] = ' ';
					break;
				case 1 :
					arr[i][j] = '.';
					break;
				case 2 :
					arr[i][j] = ',';
					break;	
				case 3 :
					arr[i][j] = '!';
					break;
				case 4 :
					arr[i][j] = ':';
					break;		
				case 5 :
					arr[i][j] = '<';
					break;
				case 6 :
					arr[i][j] = '>';
					break;
				case 7 :
					arr[i][j] = '%';
					break;
				case 8 :
					arr[i][j] = '@';
					break;	
				case 9 :
					arr[i][j] = '#';
					break;
			}				
		}
		arr[i][cols] = 0;
	}
	
}
