//�ߺ��Լ� �̿�
#include <iostream>
using namespace std;

int powerx(int x);
int powerx(int x, int y);
int powerx(int x, int y, int z);

int main()
{
	int a, b, c;
	cout << "���� ���� �Է�: ";
	cin >> a;
	cin >> b;
	cin >> c;
	cout << "x^2=" << powerx(a) << "\n";
	cout << "x^y=" << powerx(a, b) << "\n";
	cout << "x^y*z=" << powerx(a, b, c) << "\n";

	return 0;
}

int powerx(int x)
{
	return x * x;
}

int powerx(int x, int y)
{
	int a = x;
	for (int i = 1; i < y; i++)
	{
		a = a * x;
	}
	return a;
}

int powerx(int x, int y, int z)
{
	int a = x;
	for (int i = 1; i < y; i++)
	{
		a = a * x;
	}
	return a * z;
}