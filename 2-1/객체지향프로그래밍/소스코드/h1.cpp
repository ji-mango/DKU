//소수 판별하기
#include<iostream>
using namespace std;

int main()
{
	int count = 0;
	int n;
	cout << "정수 입력:";
	cin >> n;
	for (int i = 1; i <= n; i++)	//입력받은 정수의 약수 개수를 세는 for문
	{
		if (n%i == 0)
			count++;
	}
	if (count == 2)					//약수가 2개이면 소수
		cout << "소수입니다";
	else
		cout << "소수가 아닙니다";
	return 0;
}