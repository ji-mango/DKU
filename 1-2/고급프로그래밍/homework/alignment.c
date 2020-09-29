#include<stdio.h>

int main()
{
	while (1)
	{
		int arr[999];
		int arr_num = 0;
		int index, temp;


		printf("정렬할 정수의 수를 입력(종료시 -1을 입력):");
		scanf_s("%d", &arr_num);

		if (arr_num == -1)
		{
			printf("---프로그램 종료---\n");
			break;
		}

		printf("%d개의 수를 차례로 입력하시오:",arr_num);

		for (int i = 0; i < arr_num; i++)
		{
			scanf_s("%d", &arr[i]);
		}
		for (int i = 0; i < arr_num - 1; i++)
		{
			index = i;
			for (int j = i + 1; j < arr_num; j++)
			{
				if (arr[j] < arr[index])
					index = j;
			}

			temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
		}
		printf("정렬의 결과:");

		for (int i = 0; i < arr_num; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
		return 0;
}