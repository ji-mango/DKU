//프렌드함수 연산자중복 이용(*,--접두사,--접미사)
#include<iostream>
using namespace std;

class three_d {
private:
	int x, y, z;
public:
	three_d() { x = y = z = 0; }
	three_d(int i, int j, int k) { x = i; y = j; z = k; }
	friend three_d operator*(three_d op1, three_d op2);
	friend three_d operator--(three_d &op1);				//--를 중복하기위해 참조 사용
	friend three_d operator--(three_d &op1, int notused);
	void show();
};

three_d operator*(three_d op1, three_d op2)					//프렌드함수, *중복
{
	three_d temp;
	temp.x = op1.x*op2.x;
	temp.y = op1.y*op2.y;
	temp.z = op1.z*op2.z;
	return temp;
}

three_d operator--(three_d &op1)							//프렌드함수, --(접미사) 중복, 참조사용
{
	op1.x--;
	op1.y--;
	op1.z--;
	return op1;
}

three_d operator--(three_d &op1, int notused)				////프렌드함수, --(접두사) 중복, 참조사용
{
	three_d temp = op1;
	op1.x--;
	op1.y--;
	op1.z--;
	return temp;
}

void three_d::show()
{
	cout << x << "," << y << "," << z << "\n";
}

int main()
{
	three_d a(1, 2, 3), b(10, 11, 12), c;
	cout << "원래 a,b\n";
	a.show();
	b.show();
	cout << "*사용\n";
	c = a * b;
	c.show();
	cout << "--(접두사 버전) 사용\n";
	--c;
	c.show();
	cout << "--(접미사 버전) 사용\n";
	c--;
	c.show();

	return 0;
}