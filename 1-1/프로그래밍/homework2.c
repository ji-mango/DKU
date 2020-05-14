#include <stdio.h>

int main()
{
	int line, none, star;

	for (star = 1; star <= 9; star++)
		printf("*");
	printf("\n");

	for (line = 1; line <= 7; line++)
	{
		printf("*       *");
		printf("\n");
	}

	for (star = 1; star <= 9; star++)
		printf("*");
	printf("\n");


	for (line = 1; line <= 5; line++)
	{
		for (none = 1; none <= 5 - line; none++)
		{
			printf(" ");
		}

		for (star = 1; star <= (2 * line) - 1; star++)
		{
			printf("*");
		}

		printf("\n");
	}
	for (line = 6; line <= 9; line++)
	{
		for (none = 1; none <= line - 5; none++)
		{
			printf(" ");
		}

		for (star = 1; star <= (9 - line) * 2 + 1; star++)
		{
			printf("*");
		}

		printf("\n");
	}

	return 0;

}