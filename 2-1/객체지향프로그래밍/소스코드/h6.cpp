//����� �Էµɶ����� ��ū ���� ���
#include <iostream>
using namespace std;

int main()
{
	char text[100][80];
	char token[80];
	char *p, *q;
	cout << "�Է�:";
	int cnt = 0;
	for (int i = 0; i < 100; i++)
	{
		gets_s(text[i], 80);
		p = text[i];
		if (!text[i][0])				//���� �Է��ϸ� �����Է¹ޱ� ����
			break;
		while (*p)
		{
			q = token;
			while (*p != ' '&&*p)		//��ĭ, �� ���� ���ڸ� ���������� ���ڵ��� ����
			{
				*q = *p;
				q++;
				p++;
			}
			if (*p)						//��ĭ�� �ǳʶٰ� ��
				p++;
			*q = '\0';					//��ū ���� �ι���
			cnt++;						//��ū�� ���� ī��Ʈ
		}
	}
	cout << "�� ��ū�� ��:" << cnt;
	return 0;
}