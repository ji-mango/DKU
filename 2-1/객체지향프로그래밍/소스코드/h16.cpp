//클래스 이용한 좌표의 원점까지 거리 계산
#include <iostream>
#include <math.h>
using namespace std;

class point {
private:
	int x, y;
public:
	point(int a, int b)								//생성자 함수(x,y값 초기화)
	{
		x = a, y = b;
	}
	double origin_distance();
};

double point::origin_distance()						//좌표(x,y)와 원점까지의 거리 반환 함수
{
	double dist;
	dist = sqrt(pow(float(x), 2) + pow(float(y), 2));
	return dist;
}

int main()
{
	point p1(3, 4), p2(-1, -5);
	cout << "p1의 원점거리=" << p1.origin_distance() << "\n";
	cout << "p2의 원점거리=" << p2.origin_distance();

	return 0;
}