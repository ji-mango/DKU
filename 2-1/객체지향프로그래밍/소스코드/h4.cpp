//문장의 영문자,숫자,구두점(./,/!) 개수 세기(빈라인이 입력되면 프로그램 종료)(if문 사용) 
#include <iostream>
using namespace std;

int main()
{
	char text[100][80];						//100개의 문장을 입력할수 있도록 초기화
	for (int i = 0; i < 100; i++)
	{
		cout << i + 1 << ':';
		gets_s(text[i], 80);				//문장을 입력받음
		if (!text[i][0])					//엔터가 입력되면 프로그램 종료
		{
			cout << "프로그램 종료";
			break;
		}
		int cnt1 = 0;						//영문자 개수 변수
		int cnt2 = 0;						//숫자 개수 변수
		int cnt3 = 0;						//구두점 개수 변수
		for (int j = 0; text[i][j]; j++)
		{
			if ((text[i][j] >= 'a'&&text[i][j] <= 'z') ||						//영문자 개수 카운트
				(text[i][j] >= 'A'&&text[i][j] <= 'Z'))
			{
				cnt1++;
			}
			if (text[i][j] >= '0'&& text[i][j] <= '9')								//숫자 개수 카운트
			{
				cnt2++;
			}
			if (text[i][j] == ',' || text[i][j] == '.' || text[i][j] == '!')	//구두점 개수 카운트
			{
				cnt3++;
			}
		}
		cout << "영문자:" << cnt1 << "개\n";
		cout << "숫자:" << cnt2 << "개\n";
		cout << "구두점:" << cnt3 << "개\n";
	}
	return 0;
}
