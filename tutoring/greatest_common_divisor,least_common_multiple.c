#include<stdio.h>

int main()
{
	int num1 = 0;
	int num2 = 0;
	int max;
	int min;
	printf("숫자 두개 입력:");
	scanf_s("%d %d", &num1, &num2);


	for (int i = 1; i <= num1 && i <= num2; i++)
	{
		if (num1%i == 0 && num2%i == 0)
		{
			
				max = i;
		}
	}
	printf("최대공약수:%d\n", max);

	min == (num1/max)*(num2/max)*max;
	printf("최소공배수:%d", min);
	return 0;
}