//�������Լ� �������ߺ� �̿�(*,--���λ�,--���̻�)
#include<iostream>
using namespace std;

class three_d {
private:
	int x, y, z;
public:
	three_d() { x = y = z = 0; }
	three_d(int i, int j, int k) { x = i; y = j; z = k; }
	friend three_d operator*(three_d op1, three_d op2);
	friend three_d operator--(three_d &op1);				//--�� �ߺ��ϱ����� ���� ���
	friend three_d operator--(three_d &op1, int notused);
	void show();
};

three_d operator*(three_d op1, three_d op2)					//�������Լ�, *�ߺ�
{
	three_d temp;
	temp.x = op1.x*op2.x;
	temp.y = op1.y*op2.y;
	temp.z = op1.z*op2.z;
	return temp;
}

three_d operator--(three_d &op1)							//�������Լ�, --(���̻�) �ߺ�, �������
{
	op1.x--;
	op1.y--;
	op1.z--;
	return op1;
}

three_d operator--(three_d &op1, int notused)				////�������Լ�, --(���λ�) �ߺ�, �������
{
	three_d temp = op1;
	op1.x--;
	op1.y--;
	op1.z--;
	return temp;
}

void three_d::show()
{
	cout << x << "," << y << "," << z << "\n";
}

int main()
{
	three_d a(1, 2, 3), b(10, 11, 12), c;
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