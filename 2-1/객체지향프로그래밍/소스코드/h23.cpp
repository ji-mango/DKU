//일반클래스(template class)이용한 배열의 최대값 출력(배열 동적 생성)
#include<iostream>
#include<cstring>
using namespace std;

template <class x> class max {
private:
	x *list;
	int size;
public:
	max(x n) { size = n; list = new x[size]; }		//배열을 동적으로 생성
	void input();
	void m();
};

template <class x> void max <x>::input()			//배열 입력 함수
{
	for (int i = 0; i < size; i++)
	{
		x n;
		cin >> n;
		list[i] = n;
	}
}

template <class x> void max <x>::m()				//최대값 출력 함수
{
	x max_num = 0;
	for (int i = 0; i < size; i++)
	{
		if (max_num < list[i])
		{
			max_num = list[i];
		}
	}
	cout << "최대값 : " << max_num << "\n";
}
int main()
{
	int size;
	cout << "배열의 크기 입력 : ";
	cin >> size;
	max<int> m1(size);								//배열이 정수인 경우
	cout << "배열 입력 : ";
	m1.input();
	m1.m();

	cout << "배열의 크기 입력 : ";
	cin >> size;
	max<float> m2(size);							//배열이 실수인 경우
	cout << "배열 입력 : ";
	m2.input();
	m2.m();
	return 0;
}