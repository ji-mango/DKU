//속도 구하는 클래스(가상함수, 재정의 이용)
#include <iostream>
using namespace std;

class Distance {
protected:
	double dt;
public:
	Distance() { dt = 0; }
	Distance(double d) { dt = d; }
	virtual double trav_time()		//걸리는 시간을 출력하는 가상함수
	{
		double time = 0;
		time = dt / 60;
		return time;
	}
};

class metric :public Distance {
public:
	metric(double d) { dt = d; }	//파생클래스에서 함수 재정의
	double trav_time()
	{
		double time;
		time = dt / 100;			//km로 변환 후 속도로 나눔
		return time;
	}
};

int main()
{
	Distance mile(240);
	metric km(170);

	cout << "거리 240mile, 속도 시속 60mile 일때 걸리는 시간\n" << mile.trav_time() << "시간\n";
	cout << "거리 170km, 속도 시속 100km일때 걸리는 시간\n" << km.trav_time() << "시간\n";

	return 0;
}