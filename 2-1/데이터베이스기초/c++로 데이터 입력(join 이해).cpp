//DB데이터 처리
#include<stdio.h>
#include<string.h>

struct student
{
	int id;
	char name[10];
};

struct course
{
	char id[10];
	char name[20];
};

struct course_taken
{
	int sid;
	char cid[10];
	int grade;
};
int main()
{
	struct student s[7] = { {930405,"한나라"},{940123,"강동희"},
	{950564,"허영만"},{960157,"이동주"},{970734,"조용필"},
	{980115,"이미숙"},{980397,"조용기"} };

	struct course c[15] = { {"cs111","기초전산"},{"cs211","수치해석"},
	{"cs221","자료구조론"},{"cs222","시스템프로그래밍"},{"cs311","컴퓨터 구조론"},
	{"cs312","알고리즘"},{"cs321","프로그래밍언어론"},{"cs322","운영체제"},
	{"cs411","데이타베이스"},{"cs413","컴퓨터네트워크"},{"cs421","소프트웨어 공학"},
	{"ss111","전산통계"},{"ss311","응용해석학"},{"ss312","통계적 품질관리"},
	{"ss321","회귀분석"} };

	struct course_taken ct[16] = { {930405,"cs111",2},{930405,"cs222",3},
	{930405,"cs411",4},{940123,"ss111",2},{940123,"cs221",4},
	{940123,"ss312",4},{950564,"cs111",2},{950564,"cs222",1},
	{950564,"cs411",2},{960157,"cs111",1},{970734,"cs211",3},
	{970734,"cs222",2},{980115,"ss111",4},{980115,"cs221",3},
	{980115,"cs311",4},{980397,"cs111",2} };

	//1-(b)
	printf("학생이름 | 과목번호 | 학점 \n");
	printf("==============================\n");
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (s[i].id == ct[j].sid)
			{
				printf("%s     %s    %d\n", s[i].name, ct[j].cid, ct[j].grade);
			}
		}
	}
	printf("\n");
	//2-(b)
	printf("학생이름 | 과목이름 | 학점 \n");
	printf("===============================\n");
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			for (int k = 0; k < 16; k++)
			{
				if ((s[i].id == ct[k].sid) && (strcmp(c[j].id, ct[k].cid) == 0))
				{
					printf("%s %s  %d\n", s[i].name, c[j].name, ct[k].grade);
				}
			}
		}
	}
}