//�����Ҵ�(�迭�Ҵ�)�̿� �ڽź��� ���� ���� ����
#include <iostream>
using namespace std;

int main()
{
	cout << "�迭�� ũ�� �Է�:";
	int size;
	cin >> size;
	int *list;
	list = new int[size];							//size�� ������ �迭�� �Ҵ�
	cout << size << "���� ��:";
	for (int i = 0; i < size; i++)
	{
		cin >> list[i];
	}
	for (int i = 0; i < size; i++)					//�ڽź��� ���� ���� ���� ���ϴ� for��
	{
		int cnt = 0;
		for (int j = 0; j < size; j++)
		{
			if (list[i] > list[j])
				cnt++;
		}
		cout << list[i] << "-->" << cnt << "\n";
	}
	delete[] list;									//��ü �迭 ����
	return 0;
}