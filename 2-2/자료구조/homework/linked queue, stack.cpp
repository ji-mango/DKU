#include <iostream>
using namespace std;

class LinkedStack;									//stackŬ���� ���漱��
class LinkedQueue;									//queueŬ���� ���漱��
class ChainNode {
	friend LinkedStack;
	friend LinkedQueue;
private:
	int data;
	ChainNode *link;
public:
	ChainNode(int element = 0, ChainNode *next = 0)	//������
	{
		data = element; link = next;
	}
};
class LinkedStack {
private:
	ChainNode *top;
public:
	LinkedStack() { top = 0; };		//������
	void Push(const int& e);		//���� �Լ�
	int *Pop();						//���� �Լ�
	void view();					//��� �Լ�
};

class LinkedQueue {
private:
	ChainNode *front, *rear;
public:
	LinkedQueue() { front = 0, rear = 0; };	//������
	void Push(const int& e);				//���� �Լ�
	int *Pop();								//���� �Լ�
	void view();							//��� �Լ�
};

void LinkedStack::Push(const int& e)
{
	top = new ChainNode(e, top);
}
int* LinkedStack::Pop()
{
	if (top == 0) return 0;			//�� �����̸� null ��ȯ
	ChainNode* delNode = top;
	int &x = top->data;				//top ����� data�ʵ带 x�� ����
	top = top->link;				//top ��ġ�� ���� ���� �̵�
	delete delNode;					//��� ����
	return &x;
}
void LinkedStack::view()
{
	ChainNode *p = top;
	if (top == 0)					//top�� null�� ���(������� ���)
	{
		cout << "�������";
	}
	for (p; p->link; p = p->link)
	{
		cout << "����(LIFO��):" << p->data << " ";
	}
	cout << p->data << "\n";		//������ ������ ��ȯ
}


void LinkedQueue::Push(const int& e)
{
	if (front == 0) front = rear = new ChainNode(e, 0);	//���� ť
	else rear = rear->link = new ChainNode(e, 0);		//��� �����ϰ� rear ����
}
int* LinkedQueue::Pop() {
	if (front == 0) return 0;		//���� ť�̹Ƿ� null ��ȯ
	ChainNode* delNode = front;
	int &retvalue = front->data;	//�����Ǵ� ���� retvalue�� ����
	front = front->link;			//front��ġ�� ���� ���� �̵�
	delete delNode;					//��� ����
	return &retvalue;
}
void LinkedQueue::view()
{
	ChainNode *p = front;
	if (rear == 0)					//rear�� null�� ���(������� ���)
	{
		cout << "�������";
	}
	for (p; p->link; p = p->link)
	{
		cout << "����(FIFO��):" << p->data << " ";
	}
	cout << p->data << "\n";		//������ ������ ��ȯ
}

int main()
{
	int menu, push_num;
	LinkedStack stack;
	LinkedQueue queue;
	cout << "        -----�޴�-----\n";
	cout << "1.���ÿ� ����    2.ť�� ����\n";
	cout << "3.���ÿ��� ����  4.ť���� ����\n";
	cout << "5.���� ���� ���� 6.ť ���� ����\n";
	cout << "7.���α׷� ����\n";
	while (1)
	{
		cout << "�޴� ����(������ ���ڵ� �Է�):";
		cin >> menu;
		if (menu == 1)
		{
			cin >> push_num;
			stack.Push(push_num);
		}
		else if (menu == 2)
		{
			cin >> push_num;
			queue.Push(push_num);
		}
		else if (menu == 3)
		{
			stack.Pop();
		}
		else if (menu == 4)
		{
			queue.Pop();
		}
		else if (menu == 5)
		{
			stack.view();
		}
		else if (menu == 6)
		{
			queue.view();
		}
		else if (menu == 7)
		{
			break;
		}
		else
		{
			cout << "1~7�߿� ����";
		}
	}
}