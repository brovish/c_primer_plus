#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ML 100
#define MG 3
#define CSIZE 4

struct name {
	char fname[ML];
	char lname[ML];
};

struct student {
	struct name name;
	float grade[MG];
	float grade_avg;
};

void input_scores(struct student students[CSIZE]);
void input_score(struct student * student, float grade, int grade_idx);
void print_students(const struct student students[CSIZE]);
//void print_student_grade(float const grades[MG]);
//void print_student_with_grade(const struct student * student);
char * s_gets(char * st, int n);
int search_name(char * st, const struct student students[CSIZE]);
char * strtolower(char * st);
int search_selected(const int current, signed int const * selected);
void calc_avg_grade(struct student students[CSIZE]);
void print_students_info(const struct student students[CSIZE]);
void print_class_info(const struct student students[CSIZE]);

int main(void)
{
	struct student students[CSIZE] =
	{
		{{"Max", "Tkachenko"}, {0, 0, 0}}, 
		{{"Beatrice", "Fonnue"}, {0, 0, 0}},
		{{"Global", "Rory"}, {0, 0, 0}},
		{{"Mid", "Stamp"}, {0, 0, 0}}
	};
	
	print_students(students);
	
	input_scores(students);
	
	calc_avg_grade(students);
	
	print_students_info(students);
	print_class_info(students);
	//print_students(students);
	
	return 0;
}

void calc_avg_grade(struct student students[CSIZE])
{
	float sum = 0;
	int cnt = 0;
	for (int i = 0; i < CSIZE; i++)
	{
		sum = 0;
		cnt = 0;
		//printf("%s %s\ngrades:", students[i].name.fname, students[i].name.lname);
		for (int j = 0; j < MG; j++)
		{
			if (students[i].grade[j] != 0)
			{	
				sum += students[i].grade[j];
				//printf(" %4.2f", students[i].grade[j]);
				cnt++;
			}
		}
		//puts("");
		students[i].grade_avg = (float) sum / cnt;
		//printf("%f\n", students[i].grade_avg);
	
	}	
}

void print_class_info(const struct student students[CSIZE])
{
	float sum = 0;
	//int cnt = 0;
	
	for (int i = 0; i < CSIZE; i++)
	{
		sum += students[i].grade_avg;
		//for (int j = 0; j < MG; j++)
		//{
		//	if (students[i].grade[j] != 0)
		//	{	
		//		sum += students[i].grade[j];
		//	}
		//cnt++;
		//}
	}
	printf("Average for class is %.2f\n", (float) sum / CSIZE);
}	

void print_students_info(const struct student students[CSIZE])
{
	for (int i = 0; i < CSIZE; i++)
	{
		printf("%s %s\n", students[i].name.fname, students[i].name.lname);
		printf("Average grade: %.2f\nGrades:", students[i].grade_avg);
		for (int j = 0; j < MG; j++)
		{
			if (students[i].grade[j] != 0)
			{	
				printf(" %4.2f", students[i].grade[j]);
			}
		}
		puts("");
		
	}	
}

void input_scores(struct student students[CSIZE])
{
	char name[ML];
	int cnt = 1;
	int score_cnt = 0;
	//int is_selected = 1;
	int f_idx = 0;
	int rv;
	float score = 0;
	signed int selected[CSIZE] = {-1, -1, -1, -1};
	//printf("%d %d %d\n", selected[0], selected[1], selected[2]);
	printf("Enter first name or last name of student\n");
	printf("Press [enter] to quit\n");
	while (s_gets(name, ML) != NULL && name[0] != 0)
	{
		
		f_idx = search_name(name, students);
		
		//search_selected(f_idx, selected)
		//printf("cnt=%d\n", cnt);
		//printf("f_idx=%d isselected=%d\n", f_idx, search_selected(f_idx, selected));
		
		if (f_idx >= 0)
		{
			//printf("f_idx=%d isselected=%d\n", f_idx, search_selected(f_idx, selected));
			if (search_selected(f_idx, selected))
			{
				printf("Student with name %s already selected.\n", name);
				printf("Enter next student\n");
				printf("Press [enter] to quit\n");
				continue;
			}
						
			selected[cnt] = f_idx;
			printf("Selected student: %s\n", name);
			printf("Now enter %s %d grades\n", name, MG);
			printf("Enter negative value to quit\n");
			score = 0;
			score_cnt = 0;
			//printf("f_idx=%d\n", f_idx);
			while (score_cnt < MG && score >= 0)
			{
				rv = scanf("%f", &score);
				if (!rv)
				{
					printf("Please enter valid score.\n");
					while (getchar() != '\n')
						continue;
					continue;
				}
				
				while (getchar() != '\n')
					continue;
			
				if (score >= 0)
					input_score(&students[f_idx], score, score_cnt++);
				//printf("%f\n", students[f_idx].grade[score_cnt]);
				//score_cnt++;
				//print_student_with_grade(&students[f_idx]);
			}
		}			
		else
		{
			printf("Student with name %s not found.\n", name);
			printf("Enter next student\n");
			printf("Press [enter] to quit\n");
			continue;

		}
		cnt++;
		
		if (cnt > CSIZE)
		{
			break;
		}
			
		printf("Enter next student\n");
		printf("Press [enter] to quit\n");
		//printf("search_name=%d\n", search_name(name, students));
		
		//cnt++;	
	}
	
	//print_student_with_grade(&students[0]);
		
}

int search_selected(const int current, signed int const * selected)
{
	
	int ret_val = 0;
	
	for (int i = 0; i < CSIZE; i++)
	{
		//printf("selected[%d]=%d;cur=%d\n", i, selected[i], current);
		if (selected[i] == current)
		{
			ret_val = 1;
			break;	
		}
	}	
	
	return ret_val;
	
}

void input_score(struct student * student, float grade, int grade_idx)
{
	
	student->grade[grade_idx] = grade;
	//printf("student->grade[%d] = %.2f\n", grade_idx, grade);
	
}

int search_name(char * st, const struct student students[CSIZE])
{
	int find = -1;
	struct student copystudents[CSIZE];
	char stcopy[ML];
	char * ptr;
	ptr = st;
	int i = 0;
		
	while (*ptr)
	{
		stcopy[i] = *ptr;	
		i++;
		ptr++;
	}
	
	stcopy[i] = 0;
	strtolower(stcopy);
	
	for (i = 0; i < CSIZE; i++)
	{
		copystudents[i] = students[i];
		strtolower(copystudents[i].name.lname);
		strtolower(copystudents[i].name.fname);
	}
	
	for (i = 0; i < CSIZE; i++)
	{
		if (strcmp(stcopy, copystudents[i].name.fname) == 0
		|| strcmp(stcopy, copystudents[i].name.lname) == 0)
		{
			find = i;
			break;
		}
	}
	
	return find;
}

/*
void print_student_with_grade(const struct student * student)
{
	printf("%s %s\n", student->name.fname, student->name.lname);
	print_student_grade(student->grade);
}
*/


void print_students(const struct student students[CSIZE])
{
	for (int i = 0; i < CSIZE; i++)
	{
		printf("%s %s\n", students[i].name.fname,
		students[i].name.lname);
	}
}

void print_student_grade(float const grades[MG])
{
	for (int i = 0; i < MG; i++)
	{
		printf("grade %d is %.2f,", i + 1, grades[i]);
	}
	printf("\n");
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
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	
	return ret_val;
}

char * strtolower(char * st)
{
	while (*st)
	{
		*st = tolower(*st);
		//printf("st=%s\n", st);
		st++;
	}
	//printf("st=%s\n", st);
	return st;
}