//동적할당(배열할당)이용 자신보다 작은 수의 개수
#include <iostream>
using namespace std;

int main()
{
	cout << "배열의 크기 입력:";
	int size;
	cin >> size;
	int *list;
	list = new int[size];							//size개 원소의 배열을 할당
	cout << size << "개의 수:";
	for (int i = 0; i < size; i++)
	{
		cin >> list[i];
	}
	for (int i = 0; i < size; i++)					//자신보다 작은 수의 개수 구하는 for문
	{
		int cnt = 0;
		for (int j = 0; j < size; j++)
		{
			if (list[i] > list[j])
				cnt++;
		}
		cout << list[i] << "-->" << cnt << "\n";
	}
	delete[] list;									//전체 배열 해제
	return 0;
}