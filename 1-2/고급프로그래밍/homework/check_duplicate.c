#include<stdio.h>
#include<stdlib.h>

int main()
{
	int size;
	int *arr = NULL;
	int *nonum = NULL;										//�ߺ��� �� üũ�ϱ� ���� �迭

	for (int a = 0; a < 3; a++)						//���α׷� 3�� �ݺ�
	{
		printf("�迭�� ũ�⸦ �Է�:");
		scanf_s("%d", &size);

		arr = malloc(size * sizeof(int));		//���� �޸� �Ҵ��� ����Ͽ� ������ �迭 ����
		nonum = malloc(size * sizeof(int));	//���� �޸� �Ҵ�

		printf("���� �Է�:");
		for (int i = 0; i < size; i++)
		{
			scanf_s("%d", &arr[i]);
		}

		for (int i = 0; i < size; i++)				//�ߺ��� �� üũ�ϱ� ���� �迭 ��� 1�� �ʱ�ȭ
			nonum[i] = 1;

		for (int i = 0; i < size; i++)				//�ߺ��� üũ ���� for��
		{
			for (int j = 0; j < size; j++)
			{
				if (arr[i] == arr[j] && i != j)			//�ߺ��� ���� ������
					nonum[j] = 0;						//0���� ����
			}
		}
		printf("�ߺ����� ���� ������:");
		for (int i = 0; i < size; i++)
		{
			if (nonum[i] != 0)							//�ߺ����� ���� ���� ���
				printf("%d  ", arr[i]);
		}

		printf("\n\n");
		free(arr);									//�����޸� ����
		free(nonum);								//�����޸� ����
	}
}