//������ ��ħǥ,����,�޸� ���� ����(������� �ԷµǸ� ���α׷� ����)(switch�� ���)
#include <iostream>
using namespace std;

int main()
{
	char text[100][80];						//100���� ������ �Է��Ҽ� �ֵ��� �ʱ�ȭ
	for (int i = 0; i < 100; i++)
	{
		cout << i + 1 << ':';
		gets_s(text[i], 80);				//������ �Է¹���
		if (!text[i][0])					//������� �ԷµǸ� ���α׷� ����
		{
			cout << "���α׷� ����";
			break;
		}
		int cnt1 = 0;						//��ħǥ ���� ����
		int cnt2 = 0;						//���� ���� ����
		int cnt3 = 0;						//�޸� ���� ����
		for (int k = 0; text[i][k]; k++)
		{
			switch (text[i][k])				//��ħǥ, ����, �޸� ���� �������� switch��
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
		cout << "��ħǥ:" << cnt1 << "��\n";
		cout << "����:" << cnt2 << "��\n";
		cout << "�޸�:" << cnt3 << "��\n";
		cout << "�Ѱ���:" << cnt1 + cnt2 + cnt3 << "��\n";
	}
	return 0;
}