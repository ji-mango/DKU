#include<stdio.h>

int main()
{
	int num = 0;
	printf("숫자 입력:");
	scanf_s("%d", &num);

	for (int i = 2; i <= num;)
	{
		if (num%i == 0)
		{
			num == num / i;
			printf("%d \n", i);
			break;
		}
		else if (num%i != 0)
			i++;
		else if (num%i == 1)
			break;
	}
}