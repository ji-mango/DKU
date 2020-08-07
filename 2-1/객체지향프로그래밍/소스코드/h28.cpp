//자연로그,상용로그 출력하는 프로그램(멤버함수이용)
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	cout.precision(5);
	cout.setf(ios::showpos);

	cout << "log(x)     log10(x)\n";
	cout << "----------------------\n";
	for (int i = 2; i <= 20; i++)
	{
		cout.left;
		cout.width(10);
		cout << left << log(i) << " ";
		cout.left;
		cout.width(10);
		cout << left << log10(i) << "\n";
	}

	return 0;
}