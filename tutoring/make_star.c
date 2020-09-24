#include<stdio.h>

int main()
{
	int num;
	printf("정수 입력:");
	scanf_s("%d", &num);
	for (int i = 1; i <= num; i++)
	{
		for (int a = 1; a <= i; a++)
		{
			printf("*");
		}
		printf("\n");
	}

	printf("\n");

	for (int i = 1; i <=num; i++)
	{
		for (int a=1;a<=(num+1-i);a++)
		{
			printf("*");
		}
		printf("\n");
	}

	printf("\n");

	for (int i = 1; i <= num; i++)
	{
		for (int a = 1; a < (num + 1 - i); a++)
		{
			printf(" ");
		}
		for (int a = 1; a <= i; a++)
		{
			printf("*");
		}
		printf("\n");
	}

	printf("\n");

	for (int i = 1; i <= num; i++)
	{
		for (int a = 1; a < i; a++)
		{
			printf(" ");
		}
		for (int a = 1; a <= (num+1-i); a++)
		{
			printf("*");
		}
		printf("\n");
	}

	printf("\n");

	for (int i = 1; i <= num; i++)
	{
		for (int a = 1; a < (num + 1 - i); a++)
		{
			printf(" ");
		}
		for (int a = 1; a <= 2 * i - 1; a++)
		{
			printf("*");
		}
		printf("\n");
	}

	printf("\n");

	for (int i = 1; i <= num; i++)
	{
		for (int a = 1; a < i; a++)
		{
			printf(" ");
		}
		for (int a = 1; a <= 2*num-2*i+1; a++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}


