//여러가지 연산자중복(프렌드 함수,멤버함수 모두 이용)
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
	coord operator*(coord op2);						//좌표값 곱하기
	coord operator/(coord op2);						//좌표값 나누기
	bool operator==(coord op2);						//좌표값 같은지 비교하기
	bool operator&&(coord op2);						//좌표값의 길이 같은지 비교하기
	coord operator--();								//좌표값 -1(선행연산)
	coord operator--(int notused);					//좌표값 -1(후행연산)
	friend coord operator-(coord op1, coord op2);	//좌표값 빼기(프렌드함수 이용)
	//friend coord operator/(coord op1,coord op2);	//좌표값 나누기(프렌드함수 이용)
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
	cout << "원래 a,b 좌표\n";
	a.show();
	b.show();
	cout << "\n\n";
	cout << "*사용\n";
	c = a * b;
	c.show();
	cout << "\n";
	cout << "/사용\n";
	c = a / b;
	c.show();
	cout << "\n";
	cout << "==사용\n";
	cout << (a == b) << "\n\n";
	cout << "&&사용\n";
	cout << (a&&b) << "\n\n";
	cout << "a에 --(접두사)사용\n";
	--a;
	a.show();
	cout << "\n";
	cout << "b에 --(접미사)사용\n";
	b--;
	b.show();
	cout << "\n";
	cout << "-사용\n";
	c = a - b;
	c.show();

	return 0;
}