//예외처리 이용  0으로 나눌수 없는 예외 처리하기
#include<iostream>
using namespace std;

double divide(double a, double b)
{
	try {
		if (b == 0) throw 'a';
		cout << "a/b=" << a / b << "\n";
	}
	catch (char i) {						//b==0이면
		cout << "0으로 나눌 수 없습니다!\n";//0으로 나눌수 없다는 문구 반환
	}
}

int main()
{
	double a, b;
	cout << "실수 두개 입력:";
	cin >> a >> b;
	divide(a, b);

	return 0;
}