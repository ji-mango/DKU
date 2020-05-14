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
	struct class a[SIZE] = { {"����ȣ",60,32,1},{"�����",11,35,1},{"��ȣö",36,19,1},
							 {"�̵���",42,15,1},{"�ڵ���",31,32,1},{"�ֵ���",72,50,1},
							 {"�Ѹ��",19,13,1},{"���ȣ",50,32,1},{"������",44,20,1},
							 {"���¼�",23,19,1},{"������",40,26,1},{"���",66,59,1},
							 {"���¼�",41,41,1},{"�ں�ä",40,21,1},{"������",39,45,1},
							 {"���μ�",68,63,1},{"���α�",70,82,1},{"������",52,69,1},
							 {"�ɵ���",65,84,1},{"������",31,25,1},{"�����",28,28,1},
							 {"�ӱ���",30,31,1},{"�̼���",45,90,1},{"�̿�ȣ",59,59,1},
							 {"���ָ�",53,50,1},{"�̹���",34,36,1},{"��ȣ��",64,40,1},
							 {"������",41,33,1},{"������",63,45,1},{"ȫ����",59,69,1} };
	struct class temp;


	printf("�̸�    �߰�    �⸻\n");
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
	printf("�̸�   �߰�+�⸻   ����   ����\n");
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
	printf("����     �̸�  �߰�+�⸻  ����\n");
	printf("=======================================\n");
	for (i = 0; i < SIZE; i++)
	{
		printf("%d\t%s\t %d\t %s\t \n", a[i].order, a[i].name, a[i].score, a[i].grade);
	}


	return 0;
}