//Ŭ���� �̿��� ��ǥ�� �������� �Ÿ� ���
#include <iostream>
#include <math.h>
using namespace std;

class point {
private:
	int x, y;
public:
	point(int a, int b)								//������ �Լ�(x,y�� �ʱ�ȭ)
	{
		x = a, y = b;
	}
	double origin_distance();
};

double point::origin_distance()						//��ǥ(x,y)�� ���������� �Ÿ� ��ȯ �Լ�
{
	double dist;
	dist = sqrt(pow(float(x), 2) + pow(float(y), 2));
	return dist;
}

int main()
{
	point p1(3, 4), p2(-1, -5);
	cout << "p1�� �����Ÿ�=" << p1.origin_distance() << "\n";
	cout << "p2�� �����Ÿ�=" << p2.origin_distance();

	return 0;
}