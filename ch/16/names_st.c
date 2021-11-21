#include "names_st.h"

void get_names(names * pn)
{
	printf("Enter your first name: ");
	s_gets(pn->fname, SLEN);
	
	printf("Enter your last name: ");
	s_gets(pn->lname, SLEN);
}

void show_names(const names * pn)
{
	printf("%s %s", pn->fname, pn->lname);
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
			*find  = 0;
		else 
			while (getchar() != '\n')
				continue;
	}
	
	return ret_val;
}