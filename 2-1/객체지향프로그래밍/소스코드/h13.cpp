//�ߺ��Լ� ����ؼ� ���ڿ� ��������
#include <iostream>
#include <cstring>
using namespace std;

void rev_str(char *s1, char *s2);
void rev_str(char *s1);

int main()
{
	char s1[80], s2[80];
	strcpy(s1, "hello");

	rev_str(s1, s2);							//�ΰ��� ���ڿ� ȣ��
	cout << "rev_str(s1,s2)�Լ� ��� ��\ns1:";
	cout << s1 << "\ns2:" << s2 << "\n";
	rev_str(s1);								//�Ѱ��� ���ڿ� ȣ��
	cout << "rev_str(s1)�Լ� ��� �� \ns1:";
	cout << s1;

	return 0;
}

void rev_str(char *s1, char *s2)				//s1���ڿ��� s2�� �������� �����ϴ� �Լ�
{
	int len;
	len = strlen(s1);
	for (int i = 0; i < len; i++)
	{
		*(s2 + i) = *(s1 + len - 1 - i);
	}
	*(s2 + len) = NULL;
}

void rev_str(char *s1)							//s1���ڿ��� s1�� �������� �����ϴ� �Լ�
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