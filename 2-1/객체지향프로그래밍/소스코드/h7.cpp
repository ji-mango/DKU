//���ڿ����� ��ġ�ϴ� �κй��ڿ��� �� ���(�Լ� ���)
#include <iostream>
using namespace std;

int find_substr(char *str, char *sub);

int main()
{
	char str[80];
	char sub[80];
	cout << "���ڿ� �Է�:";
	cin >> str;
	cout << "���� �Է�:";
	cin >> sub;

	cout << "���ڿ��� ������ ��ġ�ϴ� ��:" << find_substr(str, sub);
	return 0;
}

int find_substr(char *str, char *sub)
{
	int cnt = 0;
	char *p, *p2;
	for (int i = 0; str[i]; i++)
	{
		p = &str[i];					//�����͸� �ٽ� ����
		p2 = sub;
		while (*p2&&*p2 == *p)		//�κ� ���ڿ� Ȯ��
		{
			p++;
			p2++;
		}
		if (!*p2)
			cnt++;					//��ġ�Ѵٸ� +1ī��Ʈ
	}
	return cnt;							//��ġ�ϴ� �� ��ȯ
}