#include<stdio.h>

int main()
{
	while (1)
	{
		int arr[999];
		int arr_num = 0;
		int index, temp;


		printf("������ ������ ���� �Է�(����� -1�� �Է�):");
		scanf_s("%d", &arr_num);

		if (arr_num == -1)
		{
			printf("---���α׷� ����---\n");
			break;
		}

		printf("%d���� ���� ���ʷ� �Է��Ͻÿ�:",arr_num);

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
		printf("������ ���:");

		for (int i = 0; i < arr_num; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
		return 0;
}