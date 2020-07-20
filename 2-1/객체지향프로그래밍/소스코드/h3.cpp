//문장의 마침표,공백,콤마 개수 세기(빈라인이 입력되면 프로그램 종료)(switch문 사용)
#include <iostream>
using namespace std;

int main()
{
	char text[100][80];						//100개의 문장을 입력할수 있도록 초기화
	for (int i = 0; i < 100; i++)
	{
		cout << i + 1 << ':';
		gets_s(text[i], 80);				//문장을 입력받음
		if (!text[i][0])					//빈라인이 입력되면 프로그램 종료
		{
			cout << "프로그램 종료";
			break;
		}
		int cnt1 = 0;						//마침표 개수 변수
		int cnt2 = 0;						//공백 개수 변수
		int cnt3 = 0;						//콤마 개수 변수
		for (int k = 0; text[i][k]; k++)
		{
			switch (text[i][k])				//마침표, 공백, 콤마 개수 세기위한 switch문
			{
			case '.':
				cnt1++;
				break;
			case ' ':
				cnt2++;
				break;
			case ',':
				cnt3++;
				break;
			}
		}
		cout << "마침표:" << cnt1 << "개\n";
		cout << "공백:" << cnt2 << "개\n";
		cout << "콤마:" << cnt3 << "개\n";
		cout << "총개수:" << cnt1 + cnt2 + cnt3 << "개\n";
	}
	return 0;
}