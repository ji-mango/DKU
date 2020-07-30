//문자열에서 일치하는 부분문자열의 수 출력(함수 사용)
#include <iostream>
using namespace std;

int find_substr(char *str, char *sub);

int main()
{
	char str[80];
	char sub[80];
	cout << "문자열 입력:";
	cin >> str;
	cout << "패턴 입력:";
	cin >> sub;

	cout << "문자열과 패턴이 일치하는 수:" << find_substr(str, sub);
	return 0;
}

int find_substr(char *str, char *sub)
{
	int cnt = 0;
	char *p, *p2;
	for (int i = 0; str[i]; i++)
	{
		p = &str[i];					//포인터를 다시 설정
		p2 = sub;
		while (*p2&&*p2 == *p)		//부분 문자열 확인
		{
			p++;
			p2++;
		}
		if (!*p2)
			cnt++;					//일치한다면 +1카운트
	}
	return cnt;							//일치하는 수 반환
}