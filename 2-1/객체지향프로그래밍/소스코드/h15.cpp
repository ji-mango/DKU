//queueŬ����(����Լ�-����ū�� ��ȯ,�Ű����� ����ŭ �ڿ������� ���)
#include<iostream>
using namespace std;
class queue {
private:
	int sloc, rloc;
public:
	queue(int n);						//������
	~queue();							//�Ҹ���
	void qput(int i);
	int qget();
	int max();
	void reverse_print(int num);
};

queue::queue(int n = 100)
{
	sloc = rloc = -1;
	size = n;
	q = new int[size];					//���� �迭 �Ҵ�

	cout << "Queue ����\n";
}

queue::~queue()
{
	cout << "Queue �Ҹ�\n";
}

void queue::qput(int i)					//�ϳ��� ������ ť�� ����
{
	if (sloc == (size - 1))
		cout << "Queue�� ���� ������\n";
	sloc++;
	q[sloc] = i;
}

int queue::qget()						//ť���� �ϳ��� ������ ��´�
{
	if (rloc == sloc)
	{
		cout << "Queue�� �������";
		return 0;
	}
	rloc++;
	return q[rloc];
}

int queue::max()						//q���� ���� ū ���� ��ȯ
{
	int maximum = 0;
	for (int i = 0; i < size; i++)
	{
		if (rloc == sloc)				//q�� ��������� -999�� ��ȯ
		{
			return -999;
			break;
		}
		if (q[i] > maximum)
			maximum = q[i];
	}
	return maximum;
}

void queue::reverse_print(int num)		//�ڿ������� num����ŭ ���
{
	for (int i = 0; i < num; i++)
	{
		if (rloc == sloc)
		{
			cout << "Queue�� �������\n";
			break;
		}
		cout << q[sloc - i] << "\n";
	}
}

int main()
{
	queue a(20);						//a.q�� ũ�� 20
	a.qput(1);
	a.qput(15);
	a.qput(4);
	a.qput(21);
	a.qput(22);
	a.qput(9);

	cout << "���� ū ��:" << a.max() << "\n";
	cout << "�ڿ������� 4�� ���\n";
	a.reverse_print(4);

	return 0;
}