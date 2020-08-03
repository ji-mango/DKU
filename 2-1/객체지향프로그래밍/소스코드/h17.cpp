//Ŭ������ ��ü���� �Լ� �̿��� ��ǥ������ �Ÿ� ���(friend�Լ��� �̿�)
#include <iostream>
#include <math.h>
using namespace std;

class point {
private:
	int x, y;
public:
	point(int a, int b)											//������ �Լ�(x,y�� �ʱ�ȭ)
	{
		x = a, y = b;
	}
	float two_distance(point a);
	friend float distance2(point a, point b);
};

float point::two_distance(point a)								//class point�� (x,y)�� class a�� (x,y)������ �Ÿ� �Լ�(��� �Լ�)
{
	float dist;
	dist = sqrt(pow(float(x - a.x), 2) + pow(float(y - a.y), 2));
	return dist;
}

float distance2(point a, point b)								//class a�� (x,y)�� class b�� (x,y)������ �Ÿ� �Լ�(�����Լ�)
{
	float dist;
	dist = sqrt(pow(float(a.x - b.x), 2) + pow(float(a.y - b.y), 2));
	return dist;
}
int main()
{
	point p1(3, 4), p2(-1, -5);
	cout << "p1�� p2 ������ �Ÿ�=" << p1.two_distance(p2) << "\n";
	cout << "p1�� p2 ������ �Ÿ�=" << distance2(p1, p2);

	return 0;
}