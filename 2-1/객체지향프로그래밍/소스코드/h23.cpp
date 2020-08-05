//�Ϲ�Ŭ����(template class)�̿��� �迭�� �ִ밪 ���(�迭 ���� ����)
#include<iostream>
#include<cstring>
using namespace std;

template <class x> class max {
private:
	x *list;
	int size;
public:
	max(x n) { size = n; list = new x[size]; }		//�迭�� �������� ����
	void input();
	void m();
};

template <class x> void max <x>::input()			//�迭 �Է� �Լ�
{
	for (int i = 0; i < size; i++)
	{
		x n;
		cin >> n;
		list[i] = n;
	}
}

template <class x> void max <x>::m()				//�ִ밪 ��� �Լ�
{
	x max_num = 0;
	for (int i = 0; i < size; i++)
	{
		if (max_num < list[i])
		{
			max_num = list[i];
		}
	}
	cout << "�ִ밪 : " << max_num << "\n";
}
int main()
{
	int size;
	cout << "�迭�� ũ�� �Է� : ";
	cin >> size;
	max<int> m1(size);								//�迭�� ������ ���
	cout << "�迭 �Է� : ";
	m1.input();
	m1.m();

	cout << "�迭�� ũ�� �Է� : ";
	cin >> size;
	max<float> m2(size);							//�迭�� �Ǽ��� ���
	cout << "�迭 �Է� : ";
	m2.input();
	m2.m();
	return 0;
}