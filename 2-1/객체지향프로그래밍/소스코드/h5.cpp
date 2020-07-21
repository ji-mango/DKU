//1000~2000사이 소수 찾기
#include <iostream>
using namespace std;

int main()
{
	cout << "1000~2000사이 소수 : ";
	for (int i = 1000; i <= 2000; i++)	//소수 찾는 for문
	{
		int cnt = 0;
		for (int j = 1; j <= i; j++)
		{
			if (i%j == 0)
				cnt++;
		}
		if (cnt == 2)					//약수가 0과 자기자신밖에 없는 소수인 경우 cnt==2
			cout << "[" << i << "]    ";
	}
	return 0;
}