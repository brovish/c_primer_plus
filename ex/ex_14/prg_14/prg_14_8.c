#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#define MINSEAT 1
#define MAXSEAT 12
#define MLNAME 100
#define FILE_N "registrar.dat"

struct person {
	char lname[MLNAME];
	char fname[MLNAME];
};

struct seat {
	struct person person;	
	int number;
	int assigned;
};

void show_list_alphabetical(const struct seat seats[MAXSEAT]);
int get_empty_seats(const struct seat seats[MAXSEAT]);
void show_list_of_empty_seats(const struct seat seats[MAXSEAT]);
void empty_seats_number(const struct seat seats[MAXSEAT]);
void assign_seat(struct seat seat[MAXSEAT], int number);
void delete_seat(struct seat seat[MAXSEAT], int number);
int get_empty_seat(const struct seat seats[MAXSEAT]);
struct seat * get_seat_by_number(int number, struct seat seat[MAXSEAT]);
char * s_gets(char *, int);
void eat_line(void);
void show_menu(void);
char get_menu_choose(void);
int get_number_choose(void);
int is_empty_seat(int n, const struct seat seats[MAXSEAT]);
int file_exists(char * fn);
void init_empty_seats(struct seat seats[MAXSEAT]);
void init_seats(struct seat seats[MAXSEAT], FILE * fp);

int main(void)
{
	
	char ch;
	int exit = 0;
	int number = 0;
	FILE * fp;
	struct seat seats[MAXSEAT];
	 	
	if (file_exists(FILE_N))
	{
		if ((fp = fopen(FILE_N, "r+b")) == NULL)
		{
			fprintf(stderr, "Can't open file \"%s\".\n", FILE_N);
			return 1;
		}
		
		init_seats(seats, fp);	
	} 
	else 
	{
		if ((fp = fopen(FILE_N, "a+b")) == NULL)
		{
			fprintf(stderr, "Can't open file \"%s\".\n", FILE_N);
			return 1;
		}
		init_empty_seats(seats);
	}	
	
	fclose(fp);
		
	while (!exit)
	{
		show_menu();
		ch = get_menu_choose();
	
		switch (ch)
		{
			case 'a':
				empty_seats_number(seats);
				break;
			case 'b':
				show_list_of_empty_seats(seats);	
				break;
			case 'c':
				show_list_alphabetical(seats);	
				break;
			case 'd':
				
				if (get_empty_seat(seats) == 0)
				{
					printf("All seats are assigned.\n");
					break;
				}
				number = get_number_choose();			
				
				if (!is_empty_seat(number, seats))
				{
					printf("Seat number %d already assigned.\n", number);
					break;
				}
				
				assign_seat(seats, number);
										
				break;
			case 'e':
				number = get_number_choose();			
				
				if (is_empty_seat(number, seats))
				{
					printf("Seat number %d not assigned.\n", number);
					break;
				}
				
				delete_seat(seats, number);
					
				break;
			case 'f':
				exit = 1;	
				break;		
		}
	}
	
	if ((fp = fopen(FILE_N, "w+b")) == NULL)
	{
		fprintf(stderr, "Can't open file \"%s\".\n", FILE_N);
		return 1;
	}
	
	fwrite(&seats[0], sizeof(struct seat), MAXSEAT, fp);
	
	fclose(fp);
	
	return 0;
}

void init_seats(struct seat seats[MAXSEAT], FILE * fp)
{
	int cnt = 0;
	while (cnt < MAXSEAT && fread(&seats[cnt], sizeof(struct seat), 1, fp) == 1)
	{
		cnt++;
	}	
}

void init_empty_seats(struct seat seats[MAXSEAT])
{
	
	for (int i = 0; i < MAXSEAT; i++)
	{
		seats[i].number = i + 1;
		seats[i].assigned = 0;
		strcpy(seats[i].person.fname, "");
		strcpy(seats[i].person.lname, "");
	}
	
}

int file_exists(char * fn)
{	
	return access(fn, F_OK) == 0 ? 1 : 0; 
}

void show_list_alphabetical(const struct seat seats[MAXSEAT])
{
	int top, seek, i;
	struct seat temp;
	struct seat copy_seats[MAXSEAT];
	
	for(i = 0; i < MAXSEAT; i++)
		copy_seats[i] = seats[i];
	
	
	for (top = 0; top < MAXSEAT; top++)
	{
		for (seek = top + 1; seek < MAXSEAT; seek++)
		{
			if (strcmp(copy_seats[top].person.lname, copy_seats[seek].person.lname) > 0)
			{
				temp = copy_seats[top];
				copy_seats[top] = copy_seats[seek];
				copy_seats[seek] = temp;
			}
		}
	}
	
	for (i = 0; i < MAXSEAT; i++)
	{		
		if (copy_seats[i].assigned)
			printf("Seat number %d: %s %s\n", copy_seats[i].number, 
			copy_seats[i].person.fname, copy_seats[i].person.lname);
		else
			printf("Seat number %d: %s\n", copy_seats[i].number, 
			"not assigned");
		
	}
}

int get_empty_seat(const struct seat seats[MAXSEAT])
{
	int num = 0;
	for (int i = 0; i < MAXSEAT; i++)
	{
		if (!seats[i].assigned)
		{	
			num = seats[i].number;
			break;
		}
	}
	
	return num;
}

int is_empty_seat(int n, const struct seat seats[MAXSEAT])
{
	return !seats[n-1].assigned;
}

void assign_seat(struct seat seat[MAXSEAT], int number)
{
	
	puts("Enter last name:");
	puts("press [enter] at the start of the line to stop.");
	
	if (s_gets(seat[number-1].person.lname, MLNAME) != NULL &&
		seat[number-1].person.lname[0] != 0)
	{
		puts("Enter first name:");
		s_gets(seat[number-1].person.fname, MLNAME);		
		seat[number-1].assigned = 1;
	}		
}


void delete_seat(struct seat seat[MAXSEAT], int number)
{
	seat[number-1].assigned = 0;
	strcpy(seat[number-1].person.fname, "");
	strcpy(seat[number-1].person.lname, "");		
}

struct seat * get_seat_by_number(int number, struct seat seat[MAXSEAT])
{
	return &seat[number];
}

char get_menu_choose(void)
{
	char ch;
	ch = getchar();
	ch = tolower(ch);
	eat_line();
	while (strchr("abcdef", ch) == NULL)
	{
		puts("Please enter a, b, c, d, e or f.");
		ch = tolower(getchar());
		eat_line();
	}
			
	return ch;
}

int get_number_choose(void)
{
	printf("Please enter number between %d and %d\n",
		MINSEAT, MAXSEAT);
	int number;
	scanf("%d", &number);
	eat_line();	
	
	if (number < MINSEAT || number > MAXSEAT)
		number = 0;
	
	while (number < MINSEAT || number > MAXSEAT)
	{
		printf("Please enter number between %d and %d\n", 
			MINSEAT, MAXSEAT);
		scanf("%d", &number);
		eat_line();
	}
			
	return number;
}


void empty_seats_number(const struct seat seats[MAXSEAT])
{
	printf("Count of empty seats: %d\n", get_empty_seats(seats));
}

int get_empty_seats(const struct seat seats[MAXSEAT])
{
	int ret_val = 0;
	for (int i = 0; i < MAXSEAT; i++)
	{
		if (!seats[i].assigned)
			ret_val += 1; 
	}
	return ret_val;
}

void show_list_of_empty_seats(const struct seat seats[MAXSEAT])
{
	printf("Empty seats:\n");
	for (int i = 0; i < MAXSEAT; i++)
	{
		if (!seats[i].assigned)
		{
			printf("%d\n", seats[i].number);
		} 
	}
}


char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = 0;
		else eat_line();	
	}
	
	return ret_val;
}

void eat_line(void)
{
	while (getchar() != '\n')
		continue;
}

void show_menu(void)
{
	puts("To choose a function, enter its letter label:");
	puts("a) Show number of empty seats");
	puts("b) Show list of empty seats");
	puts("c) Show alphabetical list of seats");
	puts("d) Assign a customer to a seat assigment");
	puts("e) Delete a seat assigment");
	puts("f) Quit");
}