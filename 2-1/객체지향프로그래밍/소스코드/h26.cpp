//���� ã������ �迭�� Ž���ϴ� ���ø�Ʈ �Լ�
#include <iostream>
using namespace std;

//�迭�� Ž���ϴ� ���ø�Ʈ �Լ�
template <class type> int find(type object, type *list, int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (object == list[i])
		{
			return i;								//��ġ�ϴ� �ε��� ��ȯ
			count++;
		}
	}
	if (count == 0)									//��ġ�ϴ� ���� ������ -1 ��ȯ
		return -1;
}

int main()
{
	int size;
	int *p, f_i;
	float *q, f_f;
	char *r, f_c;

	cout << "�迭 ũ�� : ";							//int��
	cin >> size;
	p = new int;
	*p = size;
	cout << "�迭 �Է� : ";
	for (int i = 0; i < size; i++)
		cin >> p[i];
	cout << "Ž���� �� : ";
	cin >> f_i;
	cout << "��� : " << find(f_i, p, size) << "\n";

	cout << "�迭 ũ�� : ";							//float��
	cin >> size;
	q = new float;
	*q = size;
	cout << "�迭 �Է� : ";
	for (int i = 0; i < size; i++)
		cin >> q[i];
	cout << "Ž���� �� : ";
	cin >> f_f;
	cout << "��� : " << find(f_f, q, size) << "\n";

	cout << "�迭 ũ�� : ";							//char��
	cin >> size;
	r = new char;
	*r = size;
	cout << "�迭 �Է� : ";
	for (int i = 0; i < size; i++)
		cin >> r[i];
	cout << "Ž���� �� : ";
	cin >> f_c;
	cout << "��� : " << find(f_c, r, size) << "\n";

	return 0;
}