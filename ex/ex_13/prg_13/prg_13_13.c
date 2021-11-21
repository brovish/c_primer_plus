#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rows = 20;
int cols = 30;


void add_ch_data(int rows, int cols, char arr[rows][cols+1], const int data[rows][cols]);
void print_data(int rows, int cols, int arr[rows][cols]);
void print_ch_data(int rows, int cols, char arr[rows][cols+1]);

int main(void)
{
	
	FILE *fp;
	long cnt = 1L;
	long last;
	char ch = 0;
	char *chp = &ch;
	int i = 0;
	int j = 0;
	int data[rows][cols];
	char chdata[rows][cols + 1];
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
			if (j > cols)
			{
				i++;
				j = 0;
			}
		}
		fseek(fp, cnt, SEEK_SET);
		cnt++;
	}
	
	//print_data(rows, cols, data);
	
	if (fclose(fp) != 0)
		fprintf(stderr, "Error closing file \"input.graph\"\n");
	add_ch_data(rows, cols, chdata, data);
	//printf("%d %d\n", rows, cols);
	print_ch_data(rows, cols + 1, chdata);
	
	return 0;
}

void add_ch_data(int rows, int cols, char arr[rows][cols+1], const int data[rows][cols])
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

void print_data(int rows, int cols, int arr[rows][cols])
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
void print_ch_data(int rows, int cols, char arr[rows][cols])
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
