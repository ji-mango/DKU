//������ �ߺ� �̿�(*,--���λ�,--���̻�)
#include <iostream>
using namespace std;

class three_d {
private:
	int x, y, z;
public:
	three_d() { x = y = z = 0; };
	three_d(int i, int j, int k) { x = i; y = j; z = k; };

	three_d operator*(three_d op2);
	three_d operator--();
	three_d operator--(int notused);

	void show();
};

three_d three_d::operator*(three_d op2)				//*�� �ߺ�
{
	three_d temp;
	temp.x = x * op2.x;
	temp.y = y * op2.y;
	temp.z = z * op2.z;
	return temp;
}

three_d three_d::operator--()						//--���λ� ����
{
	x--;											//x,y,z �� ����
	y--;
	z--;
	return *this;									//����� �� ��ȯ
}

three_d three_d::operator--(int notused)			//--���̻� ����
{
	three_d temp = *this;							//������ ���� ����
	x--;
	y--;
	z--;
	return temp;									//������ �� ��ȯ
}

void three_d::show()								//x,y,z ��ǥ�� ������
{
	cout << x << ",";
	cout << y << ",";
	cout << z << "\n";
}

int main()
{
	three_d a(1, 2, 3), b(7, 8, 9), c;
	cout << "���� a,b\n";
	a.show();
	b.show();
	cout << "*���\n";
	c = a * b;
	c.show();
	cout << "--(���λ� ����) ���\n";
	--c;
	c.show();
	cout << "--(���̻� ����) ���\n";
	c--;
	c.show();
	return 0;
}