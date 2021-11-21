#include <stdio.h>
#include <string.h>

#define NLEN 30

struct namect {
	char fname[NLEN];
	char lname[NLEN];
	int letters;
};

struct namect getinfo();
struct namect makeinfo(struct namect);
void showinfo(struct namect);
char * s_gets(char *, int);

int main(void)
{
	struct namect person;
	person = getinfo();
	person = makeinfo(person);
	showinfo(person);
	
	return 0;
}

struct namect getinfo()
{
	
	struct namect pst;
	
	printf("Enter your first name: ");
	s_gets(pst.fname, NLEN);
	printf("Enter your last name: ");
	s_gets(pst.lname, NLEN);
	return pst;
}

struct namect makeinfo(struct namect pst)
{
	pst.letters = strlen(pst.fname) + 
	strlen(pst.lname);
	return pst;
}

void showinfo(struct namect pst)
{
	printf("%s %s, your name contains %d letters.\n", 
		pst.fname, pst.lname, pst.letters);
}

char * s_gets(char * st, int n)
{
	char *ret_val;
	char *find;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = 0;
		else
			while (getchar() != '\n')
				continue;
	}
	
	return ret_val;
}