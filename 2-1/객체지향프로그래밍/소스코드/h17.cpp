//클래스를 객체로한 함수 이용한 좌표끼리의 거리 계산(friend함수도 이용)
#include <iostream>
#include <math.h>
using namespace std;

class point {
private:
	int x, y;
public:
	point(int a, int b)											//생성자 함수(x,y값 초기화)
	{
		x = a, y = b;
	}
	float two_distance(point a);
	friend float distance2(point a, point b);
};

float point::two_distance(point a)								//class point의 (x,y)와 class a의 (x,y)사이의 거리 함수(멤버 함수)
{
	float dist;
	dist = sqrt(pow(float(x - a.x), 2) + pow(float(y - a.y), 2));
	return dist;
}

float distance2(point a, point b)								//class a의 (x,y)와 class b의 (x,y)사이의 거리 함수(독립함수)
{
	float dist;
	dist = sqrt(pow(float(a.x - b.x), 2) + pow(float(a.y - b.y), 2));
	return dist;
}
int main()
{
	point p1(3, 4), p2(-1, -5);
	cout << "p1과 p2 사이의 거리=" << p1.two_distance(p2) << "\n";
	cout << "p1과 p2 사이의 거리=" << distance2(p1, p2);

	return 0;
}