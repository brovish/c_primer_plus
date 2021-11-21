#include <stdio.h>

struct month {
		char m_name[30];
		char m_abv[3];
		int m_cnt;
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

int tdays(int n);

int main(void)
{
	
	
	
	for (int i = 0; i < 12; i++)
	{
		printf("%2d) %10s (%3s); days: %d; days till start year: %d\n", 
		m12[i].m_cnt, m12[i].m_name, m12[i].m_abv, m12[i].days, 
			tdays(m12[i].m_cnt));
	}
		
	return 0;
}

int tdays(int n)
{
	int sum = 0;
	
	for (int i = 0; i < n; i++)
	{
		sum += m12[i].days;
	}
	
	return sum;	
}