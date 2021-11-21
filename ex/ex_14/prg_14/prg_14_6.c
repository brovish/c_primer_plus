#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXPLIDX 18
#define MINPLIDX 0
#define MAXPLNAML 50
#define MAXROWS 1000
#define FDELIM ' '

struct player {
	unsigned int number;
	char fname[MAXPLNAML];
	char lname[MAXPLNAML];
	unsigned int bats;
	unsigned int hits;
	unsigned int walks;
	unsigned int rbi;
	float bat_avg;	 
};

void put_player(unsigned int number, char const * fname, 
		char const * lname, unsigned int bats, 
		unsigned int hits, unsigned int walks, 
		int idx, struct player * pls[]);

int main(void)
{
	FILE *fp;
	long cnt = 1L;
	long last = 0;
	char ch = 0;
	int space = 0;
	int nline = 0;
	int ch_cnt;
	unsigned int number;
	char fname[MAXPLNAML];
	char lname[MAXPLNAML];
	unsigned int bats;
	unsigned int hits;
	unsigned int walks;
	unsigned int rbi;
	char * chptr;
	chptr = &ch;
	space = number = bats = hits = walks = rbi = ch_cnt = 0;
	
	struct player pls[MAXROWS];
		
	if ((fp = fopen("players.txt", "rb")) == NULL)
	{
		fprintf(stderr, "Can't open file \"players.txt\".\n");
		exit(EXIT_FAILURE);
	}
	
	fseek(fp, 0L, SEEK_END);
	last = ftell(fp);
	rewind(fp);
	
	while (cnt <= last && nline < MAXROWS)
	{
		ch = getc(fp);
		printf("%c", ch);
		if (ch != FDELIM)
		{
			switch (space)
			{
				case 0:
					number = (int) strtol(chptr, NULL, 10);	
					break;
				case 1:
					fname[ch_cnt++] = ch;
					break; 
				case 2: 
					lname[ch_cnt++] = ch;
					break;
				case 3:
					bats = (int) strtol(chptr, NULL, 10);
					break;
				case 4:
					hits = (int) strtol(chptr, NULL, 10);
					break;
				case 5:
					walks = (int) strtol(chptr, NULL, 10);
					break;
				case 6:
					rbi = (int) strtol(chptr, NULL, 10);
					break;	
			}
			
						
		} 
		if (ch == '\n')
		{
			printf("space=%d;number=%d;bats=%d;hits=%d;walks=%d;rbi=%d;%s %s\n",
			space, number, bats, hits, walks, rbi, fname, lname);	
			nline++;
			ch_cnt = space = number = bats = hits = walks = rbi = 0;
			
		
		} 
		if (ch == FDELIM)
			space++;
		
		
		//printf("nline=%d, space=%d\n", nline, space);
		
		//printf("number=%d;bats=%d;hits=%d;walks=%d;rbi=%d\n",
		//	number, bats, hits, walks, rbi);	
		
		
		
		fseek(fp, cnt, SEEK_SET);
		cnt++;
	}
	
	if (fclose(fp)!= 0)
		fprintf(stderr, "Error closing file \"players.txt\".\n");
	
	return 0;
}

void put_player(unsigned int number, char const * fname, 
	char const * lname, unsigned int bats, 
	unsigned int hits, unsigned int walks, 
	int idx, struct player * pls[])
{
	pls[idx]->number = number;
	strcpy(pls[idx]->fname, fname);
	strcpy(pls[idx]->lname, lname);
	pls[idx]->hits = hits;
	pls[idx]->walks = walks;
	pls[idx]->bats = bats;
}
