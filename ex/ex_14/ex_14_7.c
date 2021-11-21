#include <stdio.h>

struct name {
		char first[20];
		char last[20];
	};
	
struct bem {
	int limbs;
	struct name title;
	char type[30];
};

void struct_print(const struct bem * n);

int main(void)
{
	
	
	struct bem * pb;
	struct bem deb = {
		6, 
		{"Berbnazel", "Gwolkapwolk"},
		"Arcturan"
	};
	
	pb = &deb;
	
	printf("%d\n", deb.limbs);
	printf("%s\n", pb->type);
	printf("%s\n", pb->type + 2);
	
	printf("%s\n", pb->title.last);
	printf("%s\n", deb.title.last);
	
	struct_print(pb);
	struct_print(&deb);
	
	return 0;
}

void struct_print(const struct bem * n)
{
	printf("%s %s is a %d-limbed %s\n", 
	n->title.first, n->title.last, n->limbs, n->type);
}