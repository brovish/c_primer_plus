#include <stdio.h>
//#include <string.h>

#define MNAMEL 100 
#define MGR 5

struct entity {
	char fname [MNAMEL];
	char lname [MNAMEL];
	char mname [MNAMEL];
};

struct govrec {
	int ssn;
	struct entity person;
};

void print_gov_rec(struct govrec rec[MGR]);
void print_gov_rec_v2(char * fname, char * lname,
	 char * mname, int ssn);

int main(void)
{	
	
	struct govrec rec [MGR] = 
	{
		{123456789, {"Max", "Tkachenko"}}, 
		{987654321, {"Prety", "Lord", "Advanced"}},
		{123789456, {"Ronny", "Rot", "Gabon"}},
		{789123456, {"Borry", "Lorry"}},
		{456789123, {"Faromet", "Comirnaty"}}
	};	
	
	print_gov_rec(rec);
	for (int i = 0; i < MGR; i++)
	{
		print_gov_rec_v2(rec[i].person.fname,
		rec[i].person.lname, rec[i].person.mname, 
		rec[i].ssn);
	}
	
	return 0;
}

void print_gov_rec_v2(char * fname, char * lname,
	 char * mname, int ssn)
{
	if (mname[0])
	{
			printf("%s, %s %c. -- %d\n", 
			fname, lname, mname[0], ssn);	
	}
	else
	{
			printf("%s, %s -- %d\n", 
			fname, lname, ssn);
	}
}

void print_gov_rec(struct govrec rec[MGR])
{
	for (int i = 0; i < MGR; i++)
	{	
		//printf("%c\n", rec[i].person.mname[0]);
		if (rec[i].person.mname[0])
		{
			printf("%s, %s %c. -- %d\n", 
			rec[i].person.fname, rec[i].person.lname, 
			rec[i].person.mname[0], rec[i].ssn);	
		}
		else
		{
			printf("%s, %s -- %d\n", 
			rec[i].person.fname, rec[i].person.lname, 
			rec[i].ssn);	
		}	
	}
}