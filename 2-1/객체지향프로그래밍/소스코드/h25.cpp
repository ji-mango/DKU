//�� �μ� �� ���� ���� ��ȯ�ϴ� ���ø�Ʈ �Լ�
#include <iostream>
using namespace std;

template <class type> type min(type a, type b)			//���ø�Ʈ �Լ� �̿��Ͽ� �� ���� ����,���� ���� ��ȯ
{
	if (a < b)
		return a;
	else
		return b;
}
int main()
{
	cout << "min(3,4)�Է� : " << min(3, 4) << "\n";
	cout << "min('c','a')�Է� : " << min('c', 'a') << "\n";

	return 0;
}