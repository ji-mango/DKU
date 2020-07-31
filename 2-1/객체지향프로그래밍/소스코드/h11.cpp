//클래스를 이용한 부피구하기
#include <iostream>
using namespace std;

class box {
private:										//전용데이터 x,y,z와 volume 선언
	double x, y, z;
	double volume;
public:											//공용함수 선언
	void setbox(double a, double b, double c);
	void calcvolume();
	int vol();
};

void box::setbox(double a, double b, double c)
{
	x = a;										//x를 직접 참조
	y = b;										//y를 직접 참조
	z = c;										//z를 직접 참조
}

void box::calcvolume()							//x,y,z 의 부피 구하는 함수
{
	volume = x * y * z;
}

int box::vol()									//부피 반환 함수
{
	return volume;
}

int main()
{
	int a, b, c;
	box mybox;
	cout << "가로, 세로, 높이 입력:";
	cin >> a >> b >> c;
	mybox.setbox(a, b, c);
	mybox.calcvolume();
	cout << "부피:" << mybox.vol();

	return 0;
}