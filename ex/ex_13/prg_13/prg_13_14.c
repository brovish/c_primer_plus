#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rows = 20;
int cols = 30;

#define MAXROWS rows - 1
#define MAXCOLS cols - 1

void add_ch_data(int rows, int cols, char arr[rows][cols+1], const int data[rows][cols]);
void print_data(int rows, int cols, int const arr[rows][cols]);
void print_ch_data(int rows, int cols, char const arr[rows][cols+1]);
void de_glithc_data(int rows, int cols, int data[rows][cols]);
int int_diff2vals(int val1, int val2);
int int_avg4vals(int val1, int val2, int val3, int val4);
int int_avg3vals(int val1, int val2, int val3);
int int_avg2vals(int val1, int val2);

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
	//printf("%d %d = %d\n", 0, 2, int_diff2vals(0, 2));
	//printf("%d %d = %d\n", 2, 0, int_diff2vals(2, 0));
	//printf("%d %d %d= %d\n", 2, 2, 1, int_avg3vals(2, 2, 1));
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
	//puts("");
	de_glithc_data(rows, cols, data);
	
	if (fclose(fp) != 0)
		fprintf(stderr, "Error closing file \"input.graph\"\n");
	add_ch_data(rows, cols, chdata, data);
	//printf("%d %d\n", rows, cols);
	print_ch_data(rows, cols + 1, chdata);
	return 0;
}

void de_glithc_data(int rows, int cols, int data[rows][cols])
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int upper, lower, right, left, avg;
			upper = i + 1;
			lower = i - 1;
			right = j + 1;
			left = j - 1;
			avg = 0;
					
			if (left < 0 && lower < 0) 
			{	
				//printf("data[%d][%d]\n", i, j);
				
				//printf("%d\n", int_diff2vals(data[i][j], data[upper][j]));
				//printf("%d\n", int_diff2vals(data[i][j], data[i][right]));
				if (int_diff2vals(data[i][j], data[upper][j]) > 1
					&& int_diff2vals(data[i][j], data[i][right]) > 1
				)
					//printf("!data[%d][%d] ", i, j);
					data[i][j] = int_avg2vals(data[upper][j], data[i][right]);
					
			} else 
			
			if (right > MAXCOLS && lower < 0) 
			{
				//printf("data[%d][%d]\n", i, j);	
				if (int_diff2vals(data[i][j], data[upper][j]) > 1
					&& int_diff2vals(data[i][j], data[i][left]) > 1
				)
				//printf("!data[%d][%d] ", i, j);
				data[i][j] = int_avg2vals(data[upper][j], data[i][left]);
				
			} else
			
			if (left < 0 && upper > MAXROWS) 
			{
			 	//printf("data[%d][%d]\n", i, j);	
			 	if (int_diff2vals(data[i][j], data[lower][j]) > 1
					&& int_diff2vals(data[i][j], data[i][right]) > 1
				)
				//printf("!data[%d][%d] ", i, j);
				data[i][j] = int_avg2vals(data[lower][j], data[i][right]);
				
			} else 
			
			if (right > MAXCOLS && upper > MAXROWS) 
			{
				//printf("data[%d][%d]\n", i, j);
				if (int_diff2vals(data[i][j], data[lower][j]) > 1
					&& int_diff2vals(data[i][j], data[i][left]) > 1
				)
				//printf("!data[%d][%d] ", i, j);
				data[i][j] = int_avg2vals(data[lower][j], data[i][left]);	
			} else 
			
			if (lower < 0)
			{
				//printf("data[%d][%d]\n", i, j);	
				if (int_diff2vals(data[i][j], data[upper][j]) > 1
					&& int_diff2vals(data[i][j], data[i][left]) > 1
					&& int_diff2vals(data[i][j], data[i][right]) > 1
				)
				//printf("!data[%d][%d] ", i, j);
				data[i][j] = int_avg3vals(data[upper][j], data[i][left], data[i][right]);
			} else
			
			if (upper > MAXROWS)
			{
				//printf("data[%d][%d]\n", i, j);
				if (int_diff2vals(data[i][j], data[lower][j]) > 1
					&& int_diff2vals(data[i][j], data[i][left]) > 1
					&& int_diff2vals(data[i][j], data[i][right]) > 1
				)
				//printf("!data[%d][%d] ", i, j);
				data[i][j] = int_avg3vals(data[lower][j], data[i][left], data[i][right]);			
			} else
			
			if (right > MAXCOLS)
			{
				//printf("data[%d][%d]\n", i, j);
				if (int_diff2vals(data[i][j], data[upper][j]) > 1
					&& int_diff2vals(data[i][j], data[lower][j]) > 1
					&& int_diff2vals(data[i][j], data[i][left]) > 1
				)
				//printf("!data[%d][%d] ", i, j);
				data[i][j] = int_avg3vals(data[lower][j], data[i][left], data[i][upper]);			
			} else
			
			if (left < 0)
			{
			
				if (int_diff2vals(data[i][j], data[upper][j]) > 1
					&& int_diff2vals(data[i][j], data[lower][j]) > 1
					&& int_diff2vals(data[i][j], data[i][right]) > 1
				)
				//printf("!data[%d][%d] ", i, j);
				data[i][j] = int_avg3vals(data[upper][j], data[i][lower], data[i][right]);
			} else			
			
			if (int_diff2vals(data[i][j], data[upper][j]) > 1
					&& int_diff2vals(data[i][j], data[lower][j]) > 1
					&& int_diff2vals(data[i][j], data[i][left]) > 1
					&& int_diff2vals(data[i][j], data[i][right]) > 1
				)
			{
				//printf("!data[%d][%d] ", i, j);
				data[i][j] = int_avg4vals(data[upper][j], data[i][left], data[i][right], 
				data[lower][j]);	
			}
			//printf("data[%d][%d]=%d ", i, j, data[i][j]);
		}
		//puts("");
	}

}

int int_diff2vals(int val1, int val2)
{
	return abs(val1-val2);
}

int int_avg2vals(int val1, int val2)
{
	return (int) (val1 + val2) / 2;
}

int int_avg3vals(int val1, int val2, int val3)
{
	return (int) (val1 + val2 + val3) / 3;
}

int int_avg4vals(int val1, int val2, int val3, int val4)
{
	return (int) (val1 + val2 + val3 + val4) / 4;
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

void print_data(int rows, int cols, int const arr[rows][cols])
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
void print_ch_data(int rows, int cols, char const arr[rows][cols])
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
