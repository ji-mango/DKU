//1000~2000���� �Ҽ� ã��
#include <iostream>
using namespace std;

int main()
{
	cout << "1000~2000���� �Ҽ� : ";
	for (int i = 1000; i <= 2000; i++)	//�Ҽ� ã�� for��
	{
		int cnt = 0;
		for (int j = 1; j <= i; j++)
		{
			if (i%j == 0)
				cnt++;
		}
		if (cnt == 2)					//����� 0�� �ڱ��ڽŹۿ� ���� �Ҽ��� ��� cnt==2
			cout << "[" << i << "]    ";
	}
	return 0;
}