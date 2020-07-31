//원점까지 거리중 가장 가까운 좌표값 반환(구조체 사용)
#include <iostream>
#include <math.h>
using namespace std;

struct point {			//구조체 선언
	int x, y;
};

int main()
{
	point p[5];
	cout << "5개의 좌표값을 차례대로 입력:";
	for (int i = 0; i < 5; i++)
	{
		cin >> p[i].x;
		cin >> p[i].y;
	}
	int min = 9999;
	int index = 0;
	for (int i = 0; i < 5; i++)										//각 좌표들의 원점까지의 거리 계산 for문
	{
		double dist;
		dist = sqrt(pow(float(p[i].x), 2) + pow(float(p[i].y), 2));
		if (dist < min)												//거리 최솟값, 그때의 index 저장
		{
			min = dist;
			index = i;
		}
	}
	cout << "원점까지 거리가 가장 가까운 좌표:(" << p[index].x << "," << p[index].y << ")";

	return 0;
}