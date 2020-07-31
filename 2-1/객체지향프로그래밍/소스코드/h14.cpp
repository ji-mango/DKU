//클래스를 이용한 문자열길이, 문장에속한 문자갯수 구하기
#include<iostream>
#include<cstring>
using namespace std;

class mystring {
private:
	char str[80];
public:
	mystring(const char *s);
	int strlength();
	int numchar(char ch);
};

mystring::mystring(const char *s)		//생성자함수
{
	strcpy(str, s);
}

int mystring::strlength()				//문자열길이 반환함수
{
	return strlen(str);
}

int mystring::numchar(char ch)			//문장속 ch갯수 반환함수
{
	int count = 0;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ch)
			count++;
	}
	return count;
}

int main()
{
	mystring my("I am studing C++ language.");
	cout << "문자열 길이: " << my.strlength() << "\n";
	cout << "문자 a의 개수: " << my.numchar('a') << "\n";

	return 0;
}