//중복함수 사용해서 문자열 역순복사
#include <iostream>
#include <cstring>
using namespace std;

void rev_str(char *s1, char *s2);
void rev_str(char *s1);

int main()
{
	char s1[80], s2[80];
	strcpy(s1, "hello");

	rev_str(s1, s2);							//두개의 문자열 호출
	cout << "rev_str(s1,s2)함수 사용 후\ns1:";
	cout << s1 << "\ns2:" << s2 << "\n";
	rev_str(s1);								//한개의 문자열 호출
	cout << "rev_str(s1)함수 사용 후 \ns1:";
	cout << s1;

	return 0;
}

void rev_str(char *s1, char *s2)				//s1문자열을 s2에 역순으로 복사하는 함수
{
	int len;
	len = strlen(s1);
	for (int i = 0; i < len; i++)
	{
		*(s2 + i) = *(s1 + len - 1 - i);
	}
	*(s2 + len) = NULL;
}

void rev_str(char *s1)							//s1문자열을 s1에 역순으로 복사하는 함수
{
	int len;
	char s2[80];
	len = strlen(s1);
	for (int i = 0; i < len; i++)
	{
		*(s2 + i) = *(s1 + len - 1 - i);
	}
	for (int i = 0; i < len; i++)
	{
		*(s1 + i) = *(s2 + i);
	}
}