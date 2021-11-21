#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXPLIDX 18
#define MINPLIDX 0
#define MAXPLNAML 50
#define MAXROWS 100
#define FDELIM ' '

struct player {
	int number;
	char fname[MAXPLNAML];
	char lname[MAXPLNAML];
	int bats;
	int hits;
	int walks;
	int rbi;
	float bat_avg;	 
};

void print_players(const struct player * pls, int n);
void print_all_players(const struct player  * pls, int n);

void put_player(signed int number, char const * fname, 
		char const * lname, unsigned int bats, 
		unsigned int hits, unsigned int walks, 
		unsigned int rbi, struct player * pls);

void calc_batting_avg(struct player * pls, int n);

int get_numbers_players(const struct player  * pls, int n);

int main(void)
{
	FILE *fp;
	signed int number;
	//int cnt_players = 0;
	char fname[MAXPLNAML];
	char lname[MAXPLNAML];
	char words[MAXPLNAML];
	unsigned int bats;
	unsigned int hits;
	unsigned int walks;
	unsigned int rbi;
	int idx = 0;
	
	struct player pls[MAXROWS];
		
	if ((fp = fopen("players.txt", "r")) == NULL)
	{
		fprintf(stderr, "Can't open file \"players.txt\".\n");
		exit(EXIT_FAILURE);
	}
	
	int cnt = 0;
	int rows = 0;
	
	while ((fscanf(fp, "%s ", words)) == 1 && rows < MAXROWS)
	{	
		//printf("%s cnt=%d\n", words, cnt);
		//printf("cnt=%d\n", cnt);
		//number = (int)strtol(words, NULL, 10);
		
		switch (cnt)
		{
			case 0:
				number = (int)strtol(words, NULL, 10);
				break;
			case 1:
				strcpy(fname, words);
				break;
			case 2:
				strcpy(lname, words);
				break;
			case 3:
				bats = (int)strtol(words, NULL, 10);
				break;
			case 4:
				hits = (int)strtol(words, NULL, 10);
				break;
			case 5:
				walks = (int)strtol(words, NULL, 10);
				break;
			case 6:
				rbi = (int)strtol(words, NULL, 10);
				break;
		}
		
		cnt++;
		
		if (cnt == 7)
		{
			cnt = 0;
			rows++;
			//printf("number=%d;bats=%d;hits=%d;walks=%d;rbi=%d;%s %s\n",
                        //number, bats, hits, walks, rbi, fname, lname);
                        if (number <= MAXPLIDX && number >= MINPLIDX)
 	                       put_player(number, fname, lname, bats, 
					hits, walks, rbi, &pls[idx++]);

		}
		
		
	}
	
	//printf("Total rows=%d\n", rows);
	
	//s_gets(words, fp);
	//printf("%s\n", words);
	//s_gets(words, fp);
	//printf("%s\n", words);
	
	//cnt_players = get_numbers_players(pls, idx);
	//printf("%d\n",cnt_players);
	puts("Input data:");
	print_players(pls, idx);
	puts("");
	calc_batting_avg(pls, idx);
	
	//cnt_players = get_numbers_players(pls, idx);
	//printf("%d\n",cnt_players);
	puts("Players data:");
	print_players(pls, idx);
	
	print_all_players(pls, idx);
	
	if (fclose(fp)!= 0)
		fprintf(stderr, "Error closing file \"players.txt\".\n");
	
	return 0;
}

void calc_batting_avg(struct player * pls, int n)
{/*The batting average is calculated by dividing the cumulative number
of hits for a player by the cumulative number of at-bats; it should be a floating-point
calculation
*/
	
	//int s_hits, s_bats;
	int top, seek;
	for (top = 0; top < n - 1; top++)
	{
		for (seek = top + 1; seek < n; seek++)
		{
			if (pls[top].number == pls[seek].number)
			{
				//printf("top=%d;seek=%d;num=%d;hits:%d;hits2:%d\n", 
				//	top, seek, pls[seek].number, pls[seek].hits,
				//	pls[top].hits);	
				pls[seek].rbi += pls[top].rbi;
				pls[seek].bats += pls[top].bats;
				pls[seek].hits += pls[top].hits;
				pls[seek].walks += pls[top].walks;
				pls[top].number = -1;
				//strcpy(pls[top].fname, "");
			}
			
		}
		//printf("num3=%d\n", pls[top].number);		
	}
	
	for (int i = 0; i < n; i++)
	{
		pls[i].bat_avg = (float) pls[i].hits / pls[i].bats;
	}

	
}

void print_players(const struct player  * pls, int n)
{
	int j = 1;
	
	for (int i = 0; i < n; i++)
	{
		if (pls[i].number >= 0)
		 {
			printf("%3d) number:%3d %2s %2s \tbats:%3d hits:%3d"
			" walks:%3d rbi:%3d batting average:%3.2f\n",
				j++, pls[i].number,  
				pls[i].fname, pls[i].lname, 
				pls[i].bats, pls[i].hits, 
				pls[i].walks, pls[i].rbi,
				pls[i].bat_avg);
		}
	} 
}

void print_all_players(const struct player  * pls, int n)
{
	int s_bats;
	int s_hits;
	int s_walks;
	int s_rbi;
	
	s_rbi = s_walks = s_hits = s_bats = 0;
	
	float s_bat_avg = 0.f;
	
	for (int i = 0; i < n; i++)
	{
		if (pls[i].number >= 0)
		 {
			
			s_bats += pls[i].bats;
			s_rbi += pls[i].rbi;
			s_hits += pls[i].hits;
			s_walks += pls[i].walks;
			s_bat_avg += pls[i].bat_avg;
		}
	} 
	
	printf("Teams average:\n");
	printf("\t\t\t\tbats:%d hits:%3d walks:%3d rbi:%3d batting average:%3.2f\n", 
	s_bats, s_hits, s_walks, s_rbi, s_bat_avg);			
}

int get_numbers_players(const struct player  * pls, int n)
{
	int cnt = 0;
	
	for (int i = 0; i < n; i++)
	{
		if (pls[i].number >= 0)
			cnt++;	
	} 
	
	return cnt;
}

void put_player(signed int number, char const * fname, 
		char const * lname, unsigned int bats, 
		unsigned int hits, unsigned int walks, 
		unsigned int rbi, struct player * pls)
{
	pls->number = number;
	strcpy(pls->fname, fname);
	strcpy(pls->lname, lname);
	pls->hits = hits;
	pls->walks = walks;
	pls->bats = bats;
	pls->rbi = rbi;
	pls->bat_avg = 0.f;
}