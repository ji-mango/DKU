//값을 찾기위해 배열을 탐색하는 템플리트 함수
#include <iostream>
using namespace std;

//배열을 탐색하는 템플리트 함수
template <class type> int find(type object, type *list, int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (object == list[i])
		{
			return i;								//일치하는 인덱스 반환
			count++;
		}
	}
	if (count == 0)									//일치하는 것이 없으면 -1 반환
		return -1;
}

int main()
{
	int size;
	int *p, f_i;
	float *q, f_f;
	char *r, f_c;

	cout << "배열 크기 : ";							//int형
	cin >> size;
	p = new int;
	*p = size;
	cout << "배열 입력 : ";
	for (int i = 0; i < size; i++)
		cin >> p[i];
	cout << "탐색할 값 : ";
	cin >> f_i;
	cout << "결과 : " << find(f_i, p, size) << "\n";

	cout << "배열 크기 : ";							//float형
	cin >> size;
	q = new float;
	*q = size;
	cout << "배열 입력 : ";
	for (int i = 0; i < size; i++)
		cin >> q[i];
	cout << "탐색할 값 : ";
	cin >> f_f;
	cout << "결과 : " << find(f_f, q, size) << "\n";

	cout << "배열 크기 : ";							//char형
	cin >> size;
	r = new char;
	*r = size;
	cout << "배열 입력 : ";
	for (int i = 0; i < size; i++)
		cin >> r[i];
	cout << "탐색할 값 : ";
	cin >> f_c;
	cout << "결과 : " << find(f_c, r, size) << "\n";

	return 0;
}