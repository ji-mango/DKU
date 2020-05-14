#include <stdio.h>
#include <string.h>
#define SIZE 30

struct class
{
	char name[7];
	int middle;
	int final;
	int order;
	int score;
	char grade[4];
};

int main()
{

	int i, j, b, c;
	struct class a[SIZE] = { {"강덕호",60,32,1},{"고기태",11,35,1},{"곽호철",36,19,1},
							 {"이도현",42,15,1},{"박동균",31,32,1},{"최동민",72,50,1},
							 {"한명수",19,13,1},{"김승호",50,32,1},{"김은미",44,20,1},
							 {"김태성",23,19,1},{"김준형",40,26,1},{"김민",66,59,1},
							 {"박태수",41,41,1},{"박병채",40,21,1},{"민현우",39,45,1},
							 {"서인수",68,63,1},{"신인규",70,82,1},{"성재훈",52,69,1},
							 {"심동현",65,84,1},{"윤승한",31,25,1},{"김재박",28,28,1},
							 {"임기현",30,31,1},{"이수복",45,90,1},{"이원호",59,59,1},
							 {"석주명",53,50,1},{"이범석",34,36,1},{"전호진",64,40,1},
							 {"정광민",41,33,1},{"조영민",63,45,1},{"홍정모",59,69,1} };
	struct class temp;


	printf("이름    중간    기말\n");
	printf("===================================\n");
	for (i = 0; i < SIZE; i++)
	{
		printf("%-3s\t %3d\t %3d \n", a[i].name, a[i].middle, a[i].final);
	}
	for (i = 0; i < SIZE; i++)
	{
		a[i].score = (a[i].middle + a[i].final);
	}

	for (b = 0; b < SIZE; b++)
	{
		for (c = 0; c < SIZE; c++)
		{
			if (a[b].score < a[c].score)
			{
				a[b].order++;
			}
		}
	}

	for (i = 0; i < SIZE; i++)
	{
		if (a[i].order < 3)strcpy_s(a[i].grade, sizeof(a[i].grade), "A+");
		else if (a[i].order < 6)strcpy_s(a[i].grade, sizeof(a[i].grade), "A");
		else if (a[i].order < 12)strcpy_s(a[i].grade, sizeof(a[i].grade), "B+");
		else if (a[i].order < 18)strcpy_s(a[i].grade, sizeof(a[i].grade), "B");
		else if (a[i].order < 21)strcpy_s(a[i].grade, sizeof(a[i].grade), "C+");
		else if (a[i].order < 24)strcpy_s(a[i].grade, sizeof(a[i].grade), "C");
		else if (a[i].order < 25.5)strcpy_s(a[i].grade, sizeof(a[i].grade), "D+");
		else if (a[i].order < 27)strcpy_s(a[i].grade, sizeof(a[i].grade), "D");
		else   strcpy_s(a[i].grade, sizeof(a[i].grade), "F");
	}
	printf("\n===================================\n");
	printf("이름   중간+기말   석차   성적\n");
	printf("===================================\n");
	for (i = 0; i < SIZE - 1; i++)
	{
		printf("%s\t %d\t %d\t %s\n", a[i].name, a[i].score, a[i].order, a[i].grade);
	}


	for (i = 0; i < SIZE - 1; i++)
	{
		for (j = i + 1; j < SIZE; j++)
		{
			if (a[i].order > a[j].order)
			{
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}

	printf("\n=======================================\n");
	printf("석차     이름  중간+기말  성적\n");
	printf("=======================================\n");
	for (i = 0; i < SIZE; i++)
	{
		printf("%d\t%s\t %d\t %s\t \n", a[i].order, a[i].name, a[i].score, a[i].grade);
	}


	return 0;
}