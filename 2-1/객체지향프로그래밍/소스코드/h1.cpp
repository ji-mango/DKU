//�Ҽ� �Ǻ��ϱ�
#include<iostream>
using namespace std;

int main()
{
	int count = 0;
	int n;
	cout << "���� �Է�:";
	cin >> n;
	for (int i = 1; i <= n; i++)	//�Է¹��� ������ ��� ������ ���� for��
	{
		if (n%i == 0)
			count++;
	}
	if (count == 2)					//����� 2���̸� �Ҽ�
		cout << "�Ҽ��Դϴ�";
	else
		cout << "�Ҽ��� �ƴմϴ�";
	return 0;
}