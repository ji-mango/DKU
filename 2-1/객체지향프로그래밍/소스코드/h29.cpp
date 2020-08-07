//연산자중복 *, 프렌드함수 + 이용 부피값 구하기
#include <iostream>
using namespace std;

class box {
private:
	double l, w, h;
public:
	box(double a, double b, double c) : l(a), w(b), h(c) {}
	void vol() {
		cout << "부피:" << l * w * h << "\n";
	}
	friend box add_box(box b1, box b2);
	box operator*(box b1);
};

box add_box(box b1, box b2)					//box끼리 더하는 함수
{
	box temp(0, 0, 0);
	temp.l = b1.l + b2.l;
	temp.w = b1.w + b2.w;
	temp.h = b1.h + b2.h;
	return temp;
}

box box :: operator*(box b1)				//*연산자 중복
{
	box temp(0, 0, 0);
	temp.l = l * b1.l;
	temp.w = w * b1.w;
	temp.h = h * b1.h;
	return temp;
}

int main()
{
	box x(2, 4, 6), y(1, 2, 3), z(0, 0, 0);
	cout << "처음값 x(2,4,6), y(1,2,3)\n";
	cout << "add_box함수 이용 : ";
	z = add_box(x, y);
	z.vol();
	cout << "*연산자 이용 : ";
	z = x * y;
	z.vol();
	return 0;
}