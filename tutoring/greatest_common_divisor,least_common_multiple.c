#include<stdio.h>

int main()
{
	int num1 = 0;
	int num2 = 0;
	int max;
	int min;
	printf("���� �ΰ� �Է�:");
	scanf_s("%d %d", &num1, &num2);


	for (int i = 1; i <= num1 && i <= num2; i++)
	{
		if (num1%i == 0 && num2%i == 0)
		{
			
				max = i;
		}
	}
	printf("�ִ�����:%d\n", max);

	min == (num1/max)*(num2/max)*max;
	printf("�ּҰ����:%d", min);
	return 0;
}