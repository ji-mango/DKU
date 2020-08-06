//두 인수 중 작은 값을 반환하는 템플리트 함수
#include <iostream>
using namespace std;

template <class type> type min(type a, type b)			//템플리트 함수 이용하여 더 작은 숫자,문자 등을 반환
{
	if (a < b)
		return a;
	else
		return b;
}
int main()
{
	cout << "min(3,4)입력 : " << min(3, 4) << "\n";
	cout << "min('c','a')입력 : " << min('c', 'a') << "\n";

	return 0;
}