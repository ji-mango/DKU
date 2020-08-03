//클래스 이용한 사각형의 넓이 계산, 더넓은 사각형의 면적 구하기#include <math.h>
#include <iostream>
#include <cstdlib>
using namespace std;

class rectangle {
private:
	int x1, y1;
	int x2, y2;
public:
	rectangle(int a, int b, int c, int d)					//x1,y1,x2,y2의 초기값을 매개변수로 받아들임
	{
		x1 = a, y1 = b, x2 = c, y2 = d;
	};
	int area();
	int largearea(rectangle rect);
};

int rectangle::area()										//사각형의 면적 계산 함수
{
	int area;
	area = abs(x2 - x1)*abs(y2 - y1);
	return area;
}
int rectangle::largearea(rectangle rect)					//더 큰 사각형의 면적 계산 함수
{
	int area1;
	int area2;
	area1 = abs(x2 - x1)*abs(y2 - y1);
	area2 = abs(rect.x2 - rect.x1)*abs(rect.y2 - rect.y1);
	if (area1 > area2)
		return area1;
	else
		return area2;
}

int main()
{
	rectangle r1(1, 1, 3, 4), r2(-1, -2, 1, -5);
	cout << "사각형 1의 면적=" << r1.area();
	cout << "더 큰 사각형의 면적=" << r1.largearea(r2);
}