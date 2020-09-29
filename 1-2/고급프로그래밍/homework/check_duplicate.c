#include<stdio.h>
#include<stdlib.h>

int main()
{
	int size;
	int *arr = NULL;
	int *nonum = NULL;										//중복된 수 체크하기 위한 배열

	for (int a = 0; a < 3; a++)						//프로그램 3번 반복
	{
		printf("배열의 크기를 입력:");
		scanf_s("%d", &size);

		arr = malloc(size * sizeof(int));		//동적 메모리 할당을 사용하여 정수형 배열 생성
		nonum = malloc(size * sizeof(int));	//동적 메모리 할당

		printf("정수 입력:");
		for (int i = 0; i < size; i++)
		{
			scanf_s("%d", &arr[i]);
		}

		for (int i = 0; i < size; i++)				//중복된 수 체크하기 위해 배열 모두 1로 초기화
			nonum[i] = 1;

		for (int i = 0; i < size; i++)				//중복수 체크 위한 for문
		{
			for (int j = 0; j < size; j++)
			{
				if (arr[i] == arr[j] && i != j)			//중복된 수가 있으면
					nonum[j] = 0;						//0으로 갱신
			}
		}
		printf("중복되지 않은 정수들:");
		for (int i = 0; i < size; i++)
		{
			if (nonum[i] != 0)							//중복되지 않은 정수 출력
				printf("%d  ", arr[i]);
		}

		printf("\n\n");
		free(arr);									//동적메모리 해제
		free(nonum);								//동적메모리 해제
	}
}