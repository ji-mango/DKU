//����ó�� �̿�  0���� ������ ���� ���� ó���ϱ�
#include<iostream>
using namespace std;

double divide(double a, double b)
{
	try {
		if (b == 0) throw 'a';
		cout << "a/b=" << a / b << "\n";
	}
	catch (char i) {						//b==0�̸�
		cout << "0���� ���� �� �����ϴ�!\n";//0���� ������ ���ٴ� ���� ��ȯ
	}
}

int main()
{
	double a, b;
	cout << "�Ǽ� �ΰ� �Է�:";
	cin >> a >> b;
	divide(a, b);

	return 0;
}