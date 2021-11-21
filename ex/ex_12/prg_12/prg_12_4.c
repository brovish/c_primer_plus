#include <stdio.h>
static int t_times(void);

static int cnt = 0;

int main(void)
{
	
	printf("cnt=%d", cnt);
	int i = 0;
	do {
		
		if (i % 2 == 0)
			puts("");
		printf("t_times()=%2d   ", t_times());
		i++;
	} while ( i < 14);
 	
 	puts("	");
 	
	printf("after loop: cnt=%d\n", cnt);
	
	t_times();
		
	printf("     final: cnt=%d\n", cnt);
	
	printf("Done.\n");
	
	return 0;
}

int t_times(void)
{
	cnt++;
	return cnt;
}
