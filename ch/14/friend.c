#include <stdio.h>
#define LEN 20

const char * msg[5] = 
{
	"	Thank you for the wordeful evening, ",
	"You certanly prove that a ", 
	"is special kind of guy. We must get together", 
	"over a delicious ",
	" and have a few laught"
};

struct names {
	char first[LEN];
	char last[LEN];
};

struct guy {
	struct names handle;
	char favfood[LEN];
	char job[LEN];
	float income;
};

int main(void)
{
	struct guy fellow = {
		{"Even", "Villard"},
		"grilled salmon",
		"personality coach",
		168112.0
	};
	printf("Dear %s, \n\n", fellow.handle.first);
	printf("%s%s\n", msg[0], fellow.handle.first);
	printf("%s%s\n", msg[1], fellow.job);
	printf("%s\n", msg[2]);
	printf("%s%s%s", msg[3], fellow.favfood, msg[4]);
	
	if (fellow.income > 150000.0)
		puts("!!");
	else if (fellow.income > 75000.0)
		puts("!");
	else puts(".");
	
	printf("\n%40s%s\n", " ", "See you soon,");
	printf("%40s%s\n", " ", "Shalala");
	
	return 0;
}