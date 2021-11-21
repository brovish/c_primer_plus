#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MLEN 40
#define CNT_PERSONS 10
typedef struct person {
	char fname[MLEN];
	char lname[MLEN];
} Person;

int comp_lname(const void *, const void *);
int comp_fname(const void *, const void *);
Person * init_Persons(void);
void print_Person(Person *, char *);

int main(void)
{
        Person * p = init_Persons();
	print_Person(p, "Original list of persons:");
	qsort(p, CNT_PERSONS, sizeof(Person), comp_lname);
	print_Person(p, "Sorted list of persons (by Last name):");
	
	qsort(p, CNT_PERSONS, sizeof(Person), comp_fname);
	print_Person(p, "Sorted list of persons (by First name):");
	
	free(p);
        return 0;
}

void print_Person(Person * p, char * msg)
{
	puts(msg);
	
	for (int i = 0; i < CNT_PERSONS; i++)
	{
		printf("%3d) %s %s ", i+1, p[i].fname, p[i].lname);
		if (i % 3 == 2)
			putchar('\n');
	}
	putchar('\n');
}

Person * init_Persons(void)
{
	Person * p = (Person *) calloc(CNT_PERSONS, sizeof(Person));
	for (int i = 0; i < CNT_PERSONS; i++)
	{
		switch (i)
		{
			case 0: 
				strcpy(p[i].fname, "Max");
				strcpy(p[i].lname, "Morry");
				break;
			case 1: 
				strcpy(p[i].fname, "Rory");
				strcpy(p[i].lname, "Tomos");
				break;
			case 2: 
				strcpy(p[i].fname, "Farry");
				strcpy(p[i].lname, "Garr");
				break;
			case 3: 
				strcpy(p[i].fname, "Greed");
				strcpy(p[i].lname, "Tleast");
				break;
			case 4: 
				strcpy(p[i].fname, "Goblo");
				strcpy(p[i].lname, "Robby");
				break;
			case 5: 
				strcpy(p[i].fname, "Mike");
				strcpy(p[i].lname, "Borry");
				break;
			case 6: 
				strcpy(p[i].fname, "Lara");
				strcpy(p[i].lname, "Forward");
				break;
			case 7: 
				strcpy(p[i].fname, "Yiotmis");
				strcpy(p[i].lname, "Bir");
				break;
			case 8: 
				strcpy(p[i].fname, "Earry");
				strcpy(p[i].lname, "Kin");
				break;
			case 9: 
				strcpy(p[i].fname, "Katr");
				strcpy(p[i].lname, "Bob");
				break;
			default: 
				strcpy(p[i].fname, "fname");
				strcpy(p[i].lname, "lname");
				break;
				
		}
	}
	
	return p;
}

int comp_lname(const void * p1, const void * p2)
{
        const Person * ps1 = (const Person *) p1;
        const Person * ps2 = (const Person *) p2;

        int res;
        res = strcmp(ps1->lname, ps2->lname);
        if (res)
        	return res;
        else 
        	return strcmp(ps1->fname, ps2->fname);
        
}

int comp_fname(const void * p1, const void * p2)
{
        const Person * ps1 = (const Person *) p1;
        const Person * ps2 = (const Person *) p2;

        int res;
        res = strcmp(ps1->fname, ps2->fname);
        if (res)
        	return res;
        else 
        	return strcmp(ps1->lname, ps2->lname);
        
}

