//Ŭ������ �̿��� ���ڿ�����, ���忡���� ���ڰ��� ���ϱ�
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

mystring::mystring(const char *s)		//�������Լ�
{
	strcpy(str, s);
}

int mystring::strlength()				//���ڿ����� ��ȯ�Լ�
{
	return strlen(str);
}

int mystring::numchar(char ch)			//����� ch���� ��ȯ�Լ�
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
	cout << "���ڿ� ����: " << my.strlength() << "\n";
	cout << "���� a�� ����: " << my.numchar('a') << "\n";

	return 0;
}