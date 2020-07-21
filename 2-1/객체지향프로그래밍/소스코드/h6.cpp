//빈라인 입력될때까지 토큰 개수 계산
#include <iostream>
using namespace std;

int main()
{
	char text[100][80];
	char token[80];
	char *p, *q;
	cout << "입력:";
	int cnt = 0;
	for (int i = 0; i < 100; i++)
	{
		gets_s(text[i], 80);
		p = text[i];
		if (!text[i][0])				//엔터 입력하면 문장입력받기 종료
			break;
		while (*p)
		{
			q = token;
			while (*p != ' '&&*p)		//빈칸, 널 종료 문자를 만날때까지 문자들을 읽음
			{
				*q = *p;
				q++;
				p++;
			}
			if (*p)						//빈칸을 건너뛰게 함
				p++;
			*q = '\0';					//토큰 끝에 널문자
			cnt++;						//토큰의 개수 카운트
		}
	}
	cout << "총 토큰의 수:" << cnt;
	return 0;
}