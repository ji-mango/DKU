//�������� �Ÿ��� ���� ����� ��ǥ�� ��ȯ(����ü ���)
#include <iostream>
#include <math.h>
using namespace std;

struct point {			//����ü ����
	int x, y;
};

int main()
{
	point p[5];
	cout << "5���� ��ǥ���� ���ʴ�� �Է�:";
	for (int i = 0; i < 5; i++)
	{
		cin >> p[i].x;
		cin >> p[i].y;
	}
	int min = 9999;
	int index = 0;
	for (int i = 0; i < 5; i++)										//�� ��ǥ���� ���������� �Ÿ� ��� for��
	{
		double dist;
		dist = sqrt(pow(float(p[i].x), 2) + pow(float(p[i].y), 2));
		if (dist < min)												//�Ÿ� �ּڰ�, �׶��� index ����
		{
			min = dist;
			index = i;
		}
	}
	cout << "�������� �Ÿ��� ���� ����� ��ǥ:(" << p[index].x << "," << p[index].y << ")";

	return 0;
}