//������ ������,����,������(./,/!) ���� ����(������� �ԷµǸ� ���α׷� ����)(if�� ���)#include <iostream>
#include <iostream>
using namespace std;

int main()
{
	char text[100][80];						//100���� ������ �Է��Ҽ� �ֵ��� �ʱ�ȭ
	for (int i = 0; i < 100; i++)
	{
		cout << i + 1 << ':';
		gets_s(text[i], 80);				//������ �Է¹���
		if (!text[i][0])					//���Ͱ� �ԷµǸ� ���α׷� ����
		{
			cout << "���α׷� ����";
			break;
		}
		int cnt1 = 0;						//������ ���� ����
		int cnt2 = 0;						//���� ���� ����
		int cnt3 = 0;						//������ ���� ����
		for (int j = 0; text[i][j]; j++)
		{
			if ((text[i][j] >= 'a'&&text[i][j] <= 'z') ||						//������ ���� ī��Ʈ
				(text[i][j] >= 'A'&&text[i][j] <= 'Z'))
			{
				cnt1++;
			}
			if (text[i][j] >= '0'&& text[i][j] <= '9')								//���� ���� ī��Ʈ
			{
				cnt2++;
			}
			if (text[i][j] == ',' || text[i][j] == '.' || text[i][j] == '!')	//������ ���� ī��Ʈ
			{
				cnt3++;
			}
		}
		cout << "������:" << cnt1 << "��\n";
		cout << "����:" << cnt2 << "��\n";
		cout << "������:" << cnt3 << "��\n";
	}
	return 0;
}