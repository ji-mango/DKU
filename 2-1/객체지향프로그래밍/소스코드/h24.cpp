//�ӵ� ���ϴ� Ŭ����(�����Լ�, ������ �̿�)
#include <iostream>
using namespace std;

class Distance {
protected:
	double dt;
public:
	Distance() { dt = 0; }
	Distance(double d) { dt = d; }
	virtual double trav_time()		//�ɸ��� �ð��� ����ϴ� �����Լ�
	{
		double time = 0;
		time = dt / 60;
		return time;
	}
};

class metric :public Distance {
public:
	metric(double d) { dt = d; }	//�Ļ�Ŭ�������� �Լ� ������
	double trav_time()
	{
		double time;
		time = dt / 100;			//km�� ��ȯ �� �ӵ��� ����
		return time;
	}
};

int main()
{
	Distance mile(240);
	metric km(170);

	cout << "�Ÿ� 240mile, �ӵ� �ü� 60mile �϶� �ɸ��� �ð�\n" << mile.trav_time() << "�ð�\n";
	cout << "�Ÿ� 170km, �ӵ� �ü� 100km�϶� �ɸ��� �ð�\n" << km.trav_time() << "�ð�\n";

	return 0;
}