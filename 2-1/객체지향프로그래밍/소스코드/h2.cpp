//���� ���� �� ã�� 0��° ��ġ�� ���ġ
#include <iostream>
using namespace std;

int main()
{
	int list[6];
	cout << "�Է�:";
	for (int i = 0; i < 6; i++)		//�迭 �Է�
	{
		cin >> list[i];
	}
	int min = 9999;
	int index = 0;
	for (int i = 0; i < 6; i++)		//�ּڰ� ����
	{
		if (list[i] < min)
		{
			min = list[i];
			index = i;
		}
	}
	int num = 0;
	num = list[0];					//�ּڰ� 0��° ��ġ�� ���ġ
	list[0] = list[index];
	list[index] = num;

	cout << "���:";
	for (int i = 0; i < 6; i++)
	{
		cout << list[i] << ' ';
	}
}