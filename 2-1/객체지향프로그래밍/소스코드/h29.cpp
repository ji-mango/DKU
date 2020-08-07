//�������ߺ� *, �������Լ� + �̿� ���ǰ� ���ϱ�
#include <iostream>
using namespace std;

class box {
private:
	double l, w, h;
public:
	box(double a, double b, double c) : l(a), w(b), h(c) {}
	void vol() {
		cout << "����:" << l * w * h << "\n";
	}
	friend box add_box(box b1, box b2);
	box operator*(box b1);
};

box add_box(box b1, box b2)					//box���� ���ϴ� �Լ�
{
	box temp(0, 0, 0);
	temp.l = b1.l + b2.l;
	temp.w = b1.w + b2.w;
	temp.h = b1.h + b2.h;
	return temp;
}

box box :: operator*(box b1)				//*������ �ߺ�
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
	cout << "ó���� x(2,4,6), y(1,2,3)\n";
	cout << "add_box�Լ� �̿� : ";
	z = add_box(x, y);
	z.vol();
	cout << "*������ �̿� : ";
	z = x * y;
	z.vol();
	return 0;
}