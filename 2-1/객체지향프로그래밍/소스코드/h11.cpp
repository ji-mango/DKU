//Ŭ������ �̿��� ���Ǳ��ϱ�
#include <iostream>
using namespace std;

class box {
private:										//���뵥���� x,y,z�� volume ����
	double x, y, z;
	double volume;
public:											//�����Լ� ����
	void setbox(double a, double b, double c);
	void calcvolume();
	int vol();
};

void box::setbox(double a, double b, double c)
{
	x = a;										//x�� ���� ����
	y = b;										//y�� ���� ����
	z = c;										//z�� ���� ����
}

void box::calcvolume()							//x,y,z �� ���� ���ϴ� �Լ�
{
	volume = x * y * z;
}

int box::vol()									//���� ��ȯ �Լ�
{
	return volume;
}

int main()
{
	int a, b, c;
	box mybox;
	cout << "����, ����, ���� �Է�:";
	cin >> a >> b >> c;
	mybox.setbox(a, b, c);
	mybox.calcvolume();
	cout << "����:" << mybox.vol();

	return 0;
}