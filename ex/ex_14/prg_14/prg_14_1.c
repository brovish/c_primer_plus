#include <stdio.h>
#include <string.h>

struct month {
	char m_name[30];
	char m_abv[3];
	int mcnt;
	int days;
};

struct month m12[12] = 
{
	 {"january", "jan", 1, 31}, {"februrary", "feb", 2, 28},
         {"march", "mar", 3, 31}, {"april", "apr", 4, 30},
         {"may", "may", 5, 31}, {"june", "jun", 6, 30},
         {"jule", "jul", 7, 31}, {"august", "aug", 8, 31},
         {"september", "sep", 9, 30}, {"october", "oct", 10, 31},
         {"november", "nov", 11, 30} ,{"december", "dec", 12, 31}
};

int tdays(char * st);

int main(void)
{
	
	for (int i= 0; i <12; i++)
	{
		printf("%d) total days: %d (month %s)\n"
			, i+1, tdays(m12[i].m_name), m12[i].m_name);	
	}
	
	return 0;
}

int tdays(char * st)
{
	int sum = 0;
	int m_num = 0;
		
	for (int i = 0; i < 12; i++)
	{
		if (strcmp(st, m12[i].m_name) == 0)
			m_num = i + 1;		
	}
	
	for (int i = 0; i < m_num; i++)
	{
		sum += m12[i].days;
	}
	
	return sum;
}