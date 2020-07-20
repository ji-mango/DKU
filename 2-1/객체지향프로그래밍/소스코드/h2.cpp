//가장 작은 수 찾아 0번째 위치에 재배치
#include <iostream>
using namespace std;

int main()
{
	int list[6];
	cout << "입력:";
	for (int i = 0; i < 6; i++)		//배열 입력
	{
		cin >> list[i];
	}
	int min = 9999;
	int index = 0;
	for (int i = 0; i < 6; i++)		//최솟값 선별
	{
		if (list[i] < min)
		{
			min = list[i];
			index = i;
		}
	}
	int num = 0;
	num = list[0];					//최솟값 0번째 위치에 재배치
	list[0] = list[index];
	list[index] = num;

	cout << "결과:";
	for (int i = 0; i < 6; i++)
	{
		cout << list[i] << ' ';
	}
}