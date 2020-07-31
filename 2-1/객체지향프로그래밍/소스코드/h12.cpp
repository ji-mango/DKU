//함수 이용해서 배열의 평균 구하기
#include <iostream>
using namespace std;

float avg(float arr[], int n);

int main()
{
	float arr[5];
	cout << "5개의 수 입력";
	for (int i = 0; i < 5; i++)			//배열 입력
	{
		cin >> arr[i];
	}
	cout << "평균:" << avg(arr, 5);

	return 0;
}

float avg(float arr[], int n)			//배열의 평균을 반환하는 함수
{
	float add = 0;
	for (int i = 0; i < n; i++)			//배열의 수 모두 더하기
	{
		add = add + arr[i];
	}
	return add / n;						//모두 더한수를 배열의 크기로 나누기(평균 반환)
}