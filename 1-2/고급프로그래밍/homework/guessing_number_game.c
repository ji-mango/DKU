#include<stdio.h>

int main()
{
	int num = 55; //게임의 정답인 정수 num을 55로 설정
	int user_num = 0; //정답을 맞추는 사용자에게 입력받기위한 변수 user_num
	int count = 0; //시행횟수를 세기위한 변수 count 초기화

	printf("하나의 수를 입력하시오:");

	while (num != user_num) //정답과 다른 수를 입력받았을 때 반복
	{
		scanf_s("%d", &user_num); //정답을 맞추기 위한 정수 입력
		if (user_num < num) //정답보다 입력받은 수가 작으면
			printf("더 큰 수를 입력하시오:");
		else if (user_num > num) //정답보다 입력받은 수가 크면
			printf("더 작은 수를 입력하시오:");
		count++; //시행횟수 1회씩 늘리기
	}
	printf("맞습니다. 시행횟수는 %d번 입니다.", count); //정답과 시행횟수 출력


	return 0;
}