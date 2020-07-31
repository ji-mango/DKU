//queue클래스(멤버함수-가장큰값 반환,매개변수 수만큼 뒤에서부터 출력)
#include<iostream>
using namespace std;
class queue {
private:
	int sloc, rloc;
public:
	queue(int n);						//생성자
	~queue();							//소멸자
	void qput(int i);
	int qget();
	int max();
	void reverse_print(int num);
};

queue::queue(int n = 100)
{
	sloc = rloc = -1;
	size = n;
	q = new int[size];					//동적 배열 할당

	cout << "Queue 생성\n";
}

queue::~queue()
{
	cout << "Queue 소멸\n";
}

void queue::qput(int i)					//하나의 정수를 큐에 저장
{
	if (sloc == (size - 1))
		cout << "Queue가 가득 차있음\n";
	sloc++;
	q[sloc] = i;
}

int queue::qget()						//큐에서 하나의 정수를 얻는다
{
	if (rloc == sloc)
	{
		cout << "Queue가 비어있음";
		return 0;
	}
	rloc++;
	return q[rloc];
}

int queue::max()						//q에서 가장 큰 값을 반환
{
	int maximum = 0;
	for (int i = 0; i < size; i++)
	{
		if (rloc == sloc)				//q가 비어있으면 -999를 반환
		{
			return -999;
			break;
		}
		if (q[i] > maximum)
			maximum = q[i];
	}
	return maximum;
}

void queue::reverse_print(int num)		//뒤에서부터 num개만큼 출력
{
	for (int i = 0; i < num; i++)
	{
		if (rloc == sloc)
		{
			cout << "Queue가 비어있음\n";
			break;
		}
		cout << q[sloc - i] << "\n";
	}
}

int main()
{
	queue a(20);						//a.q의 크기 20
	a.qput(1);
	a.qput(15);
	a.qput(4);
	a.qput(21);
	a.qput(22);
	a.qput(9);

	cout << "가장 큰 값:" << a.max() << "\n";
	cout << "뒤에서부터 4개 출력\n";
	a.reverse_print(4);

	return 0;
}