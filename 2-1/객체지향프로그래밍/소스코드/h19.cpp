//연산자 중복 이용(*,--접두사,--접미사)
#include <iostream>
using namespace std;

class three_d {
private:
	int x, y, z;
public:
	three_d() { x = y = z = 0; };
	three_d(int i, int j, int k) { x = i; y = j; z = k; };

	three_d operator*(three_d op2);
	three_d operator--();
	three_d operator--(int notused);

	void show();
};

three_d three_d::operator*(three_d op2)				//*를 중복
{
	three_d temp;
	temp.x = x * op2.x;
	temp.y = y * op2.y;
	temp.z = z * op2.z;
	return temp;
}

three_d three_d::operator--()						//--접두사 버전
{
	x--;											//x,y,z 를 감소
	y--;
	z--;
	return *this;									//변경된 값 반환
}

three_d three_d::operator--(int notused)			//--접미사 버전
{
	three_d temp = *this;							//원래의 값을 저장
	x--;
	y--;
	z--;
	return temp;									//원래의 값 반환
}

void three_d::show()								//x,y,z 좌표를 보여줌
{
	cout << x << ",";
	cout << y << ",";
	cout << z << "\n";
}

int main()
{
	three_d a(1, 2, 3), b(7, 8, 9), c;
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