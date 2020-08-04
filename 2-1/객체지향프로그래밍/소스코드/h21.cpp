//�������� �������ߺ�(������ �Լ�,����Լ� ��� �̿�)
#include<iostream>
using namespace std;

class coord {
private:
	int x, y;
public:
	coord() { x = 0; y = 0; }
	coord(int i, int j) { x = i; y = j; }
	void get_xy(int &i, int &j) { i = x; j = y; }
	void show() { cout << x << "," << y << "\n"; }
	coord operator*(coord op2);						//��ǥ�� ���ϱ�
	coord operator/(coord op2);						//��ǥ�� ������
	bool operator==(coord op2);						//��ǥ�� ������ ���ϱ�
	bool operator&&(coord op2);						//��ǥ���� ���� ������ ���ϱ�
	coord operator--();								//��ǥ�� -1(���࿬��)
	coord operator--(int notused);					//��ǥ�� -1(���࿬��)
	friend coord operator-(coord op1, coord op2);	//��ǥ�� ����(�������Լ� �̿�)
	//friend coord operator/(coord op1,coord op2);	//��ǥ�� ������(�������Լ� �̿�)
};

coord coord::operator*(coord op2)
{
	coord temp;
	temp.x = x * op2.x;
	temp.y = y * op2.y;
	return temp;
}

coord coord::operator/(coord op2)
{
	coord temp;
	temp.x = x / op2.x;
	temp.y = y / op2.y;
	return temp;
}

bool coord::operator==(coord op2)
{
	return (x == op2.x&&y == op2.y);
}

bool coord::operator&&(coord op2)
{
	double t1, t2;
	t1 = sqrt((x*x) + (y*y));
	t2 = sqrt((op2.x*op2.x) + (op2.y*op2.y));
	return (t1 == t2);
}

coord coord::operator--()
{
	x--;
	y--;
	return *this;
}

coord coord::operator--(int notused)
{
	coord temp = *this;
	x--;
	y--;
	return temp;
}

coord operator-(coord op1, coord op2)
{
	coord temp;
	temp.x = op1.x - op2.x;
	temp.y = op1.y - op2.y;
	return temp;
}

//coord operator/(coord op1,coord op2)
//{
//	coord temp;
//	temp.x = op1.x / op2.x;
//	temp.y = op1.y / op2.y;
//	return temp;
//}

int main()
{
	coord a(20, 30), b(-20, -30), c;
	cout << "���� a,b ��ǥ\n";
	a.show();
	b.show();
	cout << "\n\n";
	cout << "*���\n";
	c = a * b;
	c.show();
	cout << "\n";
	cout << "/���\n";
	c = a / b;
	c.show();
	cout << "\n";
	cout << "==���\n";
	cout << (a == b) << "\n\n";
	cout << "&&���\n";
	cout << (a&&b) << "\n\n";
	cout << "a�� --(���λ�)���\n";
	--a;
	a.show();
	cout << "\n";
	cout << "b�� --(���̻�)���\n";
	b--;
	b.show();
	cout << "\n";
	cout << "-���\n";
	c = a - b;
	c.show();

	return 0;
}