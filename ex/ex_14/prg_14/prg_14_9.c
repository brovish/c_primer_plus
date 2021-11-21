#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#define MINSEAT 1
#define FLIGHTSN 4
#define MAXSEAT 12*FLIGHTSN
#define MLNAME 100
#define FLN 10
#define FILE_N "registrar_v2.dat"
#define FL1 "102"
#define FL2 "311"
#define FL3 "444"
#define FL4 "519"

struct person {
	char lname[MLNAME];
	char fname[MLNAME];
};

struct seat {
	struct person person;	
	int number;
	int assigned;
	int confirmed;
	char flight[FLN];
};

void clear_screen(void);
void show_list_of_empty_seats(const struct seat seats[MAXSEAT], char * flight);
void show_list_alphabetical(const struct seat seats[MAXSEAT], char * flight);
void show_main_menu(char * flight);
void show_flight_menu();
char * s_gets(char *, int);
void eat_line(void);

int file_exists(char * fn);
int check_flight_number(char * flight);

int get_empty_seats(const struct seat seats[MAXSEAT], char * flight);
int get_confirmed_seat(const struct seat seats[MAXSEAT], char * flight);
char get_menu_choose(void);
int get_number_choose(void);
void get_flight_info(char * flight, int n);
int get_start_seat_index(const struct seat seats[MAXSEAT], char * flight);

void init_empty_seats(struct seat seats[MAXSEAT]);
void init_seats(struct seat seats[MAXSEAT], FILE * fp);

void empty_seats_number(const struct seat seats[MAXSEAT], char * flight);
void assign_seat(struct seat seat[MAXSEAT], int number, char * flight);
void confirm_seat(struct seat seats[MAXSEAT], int number, char * flight);
void delete_seat(struct seat seat[MAXSEAT], int number, char * flight);
int get_empty_seat(const struct seat seats[MAXSEAT], char * flight);
int is_empty_seat(int n, const struct seat seats[MAXSEAT], char * flight);
int is_confirmed_seat(int number, const struct seat seats[MAXSEAT], char * flight);


int main(void)
{
	
	char ch;
	int exit = 0;
	int number = 0;
	FILE * fp;
	struct seat seats[MAXSEAT];
	char flight[FLN];
	
	 	
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
	
	START:;
	clear_screen();	
	show_flight_menu();
	get_flight_info(flight, FLN);
	
	if (flight[0] == 0)
		return 1;
			
		
	while (!exit)
	{
		
		show_main_menu(flight);
		ch = get_menu_choose();
	
		switch (ch)
		{
			case 'a':
				empty_seats_number(seats, flight);
				break;
			case 'b':
				show_list_of_empty_seats(seats, flight);	
				break;
			case 'c':
				show_list_alphabetical(seats, flight);	
				break;
			case 'd':
				
				if (get_empty_seat(seats, flight) == 0)
				{
					printf("All seats are assigned.\n");
					break;
				}
				number = get_number_choose();			
				
				if (!is_empty_seat(number, seats, flight))
				{
					printf("Flight %s, seat number %d already assigned.\n",
						flight, number);
					break;
				}
				
				assign_seat(seats, number, flight);
														
				break;
			case 'e':
				number = get_number_choose();			
				
				if (is_empty_seat(number, seats, flight))
				{
					printf("Flight %s, seat number %d not assigned.\n", 
						flight, number);
					break;
				}
				
				delete_seat(seats, number, flight);
					
				break;
			case 'f': 
				goto START;
			
			case 'g':
				
				
				
				if (get_confirmed_seat(seats, flight) == 0)
				{
					printf("All seats are confirmed.\n");
					break;
				}
				number = get_number_choose();			
				
				if (!is_confirmed_seat(number, seats, flight))
				{
					printf("Flight %s, seat number %d already confirmed.\n",
						flight, number);
					break;
				}
				
				if (is_empty_seat(number, seats, flight))
				{
					printf("Flight %s, seat number %d not assigned.\n",
						flight, number);
					break;
				}
				
				confirm_seat(seats, number, flight);
														
				break;
			
			
			case 'h':
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
	for (int i = 0, j = 1, m = 1, n = 1, k = 1; i < MAXSEAT; i++)
	{
		
		if (i < 12)
		{
			seats[i].number = j++;
			seats[i].assigned = 0;
			seats[i].confirmed = 0;
			strcpy(seats[i].person.fname, "");
			strcpy(seats[i].person.lname, "");
			strcpy(seats[i].flight, FL1);
		}
		
		if (i >= 12 && i < 24)
		{
			seats[i].number = m++;
			seats[i].confirmed = 0;
			seats[i].assigned = 0;
			strcpy(seats[i].person.fname, "");
			strcpy(seats[i].person.lname, "");
			strcpy(seats[i].flight, FL2);
		}
		
		if (i >= 24 && i < 36)
		{
			seats[i].number = k++;
			seats[i].confirmed = 0;
			seats[i].assigned = 0;
			strcpy(seats[i].person.fname, "");
			strcpy(seats[i].person.lname, "");
			strcpy(seats[i].flight, FL3);
		}
		
		if (i >= 36 && i < 48)
		{
			seats[i].number = n++;
			seats[i].confirmed = 0;
			seats[i].assigned = 0;
			strcpy(seats[i].person.fname, "");
			strcpy(seats[i].person.lname, "");
			strcpy(seats[i].flight, FL4);
		}
	}
	
}

int file_exists(char * fn)
{	
	return access(fn, F_OK) == 0 ? 1 : 0; 
}

void show_list_alphabetical(const struct seat seats[MAXSEAT], char * flight)
{
	int top, seek, i, j;
	struct seat temp;
	struct seat copy_seats[MAXSEAT];
	
	for(i = 0, j = 0; i < MAXSEAT; i++)
	{
		if (strcmp(seats[i].flight, flight) == 0) 
			copy_seats[j++] = seats[i];
	}
	
	for (top = 0; top < MAXSEAT/FLIGHTSN; top++)
	{
		for (seek = top + 1; seek < MAXSEAT/FLIGHTSN; seek++)
		{
			if (strcmp(copy_seats[top].person.lname, copy_seats[seek].person.lname) > 0)
			{
				temp = copy_seats[top];
				copy_seats[top] = copy_seats[seek];
				copy_seats[seek] = temp;
			}
		}
	}
	
	for (i = 0; i < MAXSEAT/FLIGHTSN; i++)
	{		
		if (copy_seats[i].assigned)
			printf("Fligh %s, seat number %d: %s %s (confirmed: %s)\n", 
			copy_seats[i].flight,
			copy_seats[i].number, 
			copy_seats[i].person.fname, copy_seats[i].person.lname, 
			copy_seats[i].confirmed ? "yes" : "no");
		else
			printf("Fligh %s, seat number %d: %s\n", 
			copy_seats[i].flight,
			copy_seats[i].number, 
			"not assigned");
		
	}
}

int get_empty_seat(const struct seat seats[MAXSEAT], char * flight)
{
	int indx = 0;
	indx = get_start_seat_index(seats, flight);
	int m_indx = indx + 12;	
		
	int num = 0;
	for (; indx < m_indx; indx++)
	{
		if (!seats[indx].confirmed)
		{	
			num = seats[indx].number;
			break;
		}
	}
	
	return num;
}

int get_confirmed_seat(const struct seat seats[MAXSEAT], char * flight)
{
	int indx = 0;
	indx = get_start_seat_index(seats, flight);
	int m_indx = indx + 12;	
		
	int num = 0;
	for (; indx < m_indx; indx++)
	{
		if (!seats[indx].confirmed)
		{	
			num = seats[indx].number;
			break;
		}
	}
	
	return num;
}

int get_start_seat_index(const struct seat seats[MAXSEAT], char * flight)
{
	
	int i = 0;
	for (; i < MAXSEAT; i++)
	{
		
		if (i < 12 && strcmp(FL1, flight) == 0)
			break;
		if (i >= 12 && i < 24 && strcmp(FL2, flight) == 0)
			break;		
		if (i >= 24 && i < 36 && strcmp(FL3, flight) == 0)
			break;
		if (i >= 36 && i < 48 && strcmp(FL4, flight) == 0)
			break;
	}
	
	return i;

}

int is_empty_seat(int number, const struct seat seats[MAXSEAT], char * flight)
{
	
	int indx = 0;
	indx = get_start_seat_index(seats, flight);
	return !seats[number - 1 + indx].assigned;
}

int is_confirmed_seat(int number, const struct seat seats[MAXSEAT], char * flight)
{
	int indx = 0;
	indx = get_start_seat_index(seats, flight);
	return !seats[number - 1 + indx].confirmed;
}


void assign_seat(struct seat seats[MAXSEAT], int number, char * flight)
{
	
	int indx = 0;
	indx = get_start_seat_index(seats, flight);
	
	puts("Enter last name:");
	puts("press [enter] at the start of the line to stop.");
	
	if (s_gets(seats[number-1+indx].person.lname, MLNAME) != NULL &&
		seats[number-1+indx].person.lname[0] != 0)
	{
		puts("Enter first name:");
		s_gets(seats[number-1+indx].person.fname, MLNAME);		
		seats[number-1+indx].assigned = 1;
	}
	
	printf("Flight %s, seat %d assigned.\n", flight, number);
			
}

void confirm_seat(struct seat seats[MAXSEAT], int number, char * flight)
{
	
	char answer[10];
	int indx = 0;
	indx = get_start_seat_index(seats, flight);
	
	printf("Confirm flight %s, seat number %d for %s %s? (yes or no)\n", 
		flight, number, seats[number-1+indx].person.fname, 
		seats[number-1+indx].person.lname);
	//puts("press [enter] at the start of the line to stop.");
	if (s_gets(answer, 10) != NULL && answer[0] != 0)
	{
		if (strcmp(answer, "yes") == 0)
		{
			seats[number-1+indx].confirmed= 1;
			printf("Flight %s, seat %d confirmed.\n", flight, number);
		}
	}
}


void get_flight_info(char * flight, int  n)
{
	printf("Please enter flight number:\n");
	puts("press [enter] at the start of the line to stop.");
	s_gets(flight, n);
	while (!check_flight_number(flight) && flight[0] != 0)
	{
		puts("Incorrect flight number");
		show_flight_menu();
		
		printf("Please enter flight number:\n");
		puts("press [enter] at the start of the line to stop.");
	
		s_gets(flight, n);
	}	
}

int check_flight_number(char * flight)
{
	int correct = 0;
	if (strcmp(flight, FL1) == 0 || 
		strcmp(flight, FL2) == 0 || 
		strcmp(flight, FL3) == 0 || 
		strcmp(flight, FL4) == 0) 
		correct = 1;
	return correct;
}

void delete_seat(struct seat seats[MAXSEAT], int number, char * flight)
{
	
	int indx = 0;
	indx = get_start_seat_index(seats, flight);
		
	seats[number-1+indx].assigned = 0;
	seats[number-1+indx].confirmed = 0;
	strcpy(seats[number-1+indx].person.fname, "");
	strcpy(seats[number-1+indx].person.lname, "");
}

char get_menu_choose(void)
{
	char ch;
	ch = getchar();
	ch = tolower(ch);
	eat_line();
	while (strchr("abcdefgh", ch) == NULL)
	{
		puts("Please enter a, b, c, d, e, f, g or h");
		ch = tolower(getchar());
		eat_line();
	}
			
	return ch;
}

int get_number_choose(void)
{
	printf("Please enter number between %d and %d\n",
		MINSEAT, MAXSEAT/4);
	int number;
	scanf("%d", &number);
	eat_line();	
	
	if (number < MINSEAT || number > MAXSEAT/4)
		number = 0;
	
	while (number < MINSEAT || number > MAXSEAT/4)
	{
		printf("Please enter number between %d and %d\n", 
			MINSEAT, MAXSEAT/4);
		scanf("%d", &number);
		eat_line();
	}
			
	return number;
}

void empty_seats_number(const struct seat seats[MAXSEAT], char * flight)
{
	printf("Count of empty seats: %d\n", get_empty_seats(seats, flight));
}

int get_empty_seats(const struct seat seats[MAXSEAT], char * flight)
{
	int ret_val = 0;
	for (int i = 0; i < MAXSEAT; i++)
	{
		if (!seats[i].assigned && strcmp(seats[i].flight, flight) == 0)
			ret_val += 1; 
	}
	return ret_val;
}

void show_list_of_empty_seats(const struct seat seats[MAXSEAT], char * flight)
{
	printf("Empty seats:\n");
	for (int i = 0; i < MAXSEAT; i++)
	{
		if (!seats[i].assigned && strcmp(seats[i].flight, flight) == 0)
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

void show_main_menu(char * flight)
{
	printf("flight: %s\n", flight);
	puts("To choose a function, enter its letter label:");
	puts("a) Show number of empty seats");
	puts("b) Show list of empty seats");
	puts("c) Show alphabetical list of seats");
	puts("d) Assign a customer to a seat assigment");
	puts("e) Delete a seat assigment");
	puts("f) Return to flight selection");
	puts("g) Confirmation of seat assignment");
	puts("h) Quit");
}

void show_flight_menu()
{
	printf("Colossus Airlines flights:");
	printf(" %s, ", FL1);
	printf("%s, ", FL2);
	printf("%s, ", FL3);
	printf("%s\n", FL4);
}

void clear_screen(void)
{
	system("clear");
}