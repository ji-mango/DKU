//�Լ� �̿��ؼ� �迭�� ��� ���ϱ�
#include <iostream>
using namespace std;

float avg(float arr[], int n);

int main()
{
	float arr[5];
	cout << "5���� �� �Է�";
	for (int i = 0; i < 5; i++)			//�迭 �Է�
	{
		cin >> arr[i];
	}
	cout << "���:" << avg(arr, 5);

	return 0;
}

float avg(float arr[], int n)			//�迭�� ����� ��ȯ�ϴ� �Լ�
{
	float add = 0;
	for (int i = 0; i < n; i++)			//�迭�� �� ��� ���ϱ�
	{
		add = add + arr[i];
	}
	return add / n;						//��� ���Ѽ��� �迭�� ũ��� ������(��� ��ȯ)
}