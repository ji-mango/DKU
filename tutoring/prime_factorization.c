#include<stdio.h>

int main()
{
	int num = 0;
	printf("���� �Է�:");
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