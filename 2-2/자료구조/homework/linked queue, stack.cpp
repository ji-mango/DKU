#include <iostream>
using namespace std;

class LinkedStack;									//stack클래스 전방선언
class LinkedQueue;									//queue클래스 전방선언
class ChainNode {
	friend LinkedStack;
	friend LinkedQueue;
private:
	int data;
	ChainNode *link;
public:
	ChainNode(int element = 0, ChainNode *next = 0)	//생성자
	{
		data = element; link = next;
	}
};
class LinkedStack {
private:
	ChainNode *top;
public:
	LinkedStack() { top = 0; };		//생성자
	void Push(const int& e);		//삽입 함수
	int *Pop();						//삭제 함수
	void view();					//출력 함수
};

class LinkedQueue {
private:
	ChainNode *front, *rear;
public:
	LinkedQueue() { front = 0, rear = 0; };	//생성자
	void Push(const int& e);				//삽입 함수
	int *Pop();								//삭제 함수
	void view();							//출력 함수
};

void LinkedStack::Push(const int& e)
{
	top = new ChainNode(e, top);
}
int* LinkedStack::Pop()
{
	if (top == 0) return 0;			//빈 스택이면 null 반환
	ChainNode* delNode = top;
	int &x = top->data;				//top 노드의 data필드를 x에 저장
	top = top->link;				//top 위치를 다음 노드로 이동
	delete delNode;					//노드 삭제
	return &x;
}
void LinkedStack::view()
{
	ChainNode *p = top;
	if (top == 0)					//top이 null일 경우(비어있을 경우)
	{
		cout << "비어있음";
	}
	for (p; p->link; p = p->link)
	{
		cout << "스택(LIFO순):" << p->data << " ";
	}
	cout << p->data << "\n";		//마지막 데이터 반환
}


void LinkedQueue::Push(const int& e)
{
	if (front == 0) front = rear = new ChainNode(e, 0);	//공백 큐
	else rear = rear->link = new ChainNode(e, 0);		//노드 삽입하고 rear 수정
}
int* LinkedQueue::Pop() {
	if (front == 0) return 0;		//공백 큐이므로 null 반환
	ChainNode* delNode = front;
	int &retvalue = front->data;	//삭제되는 값을 retvalue에 저장
	front = front->link;			//front위치를 다음 노드로 이동
	delete delNode;					//노드 삭제
	return &retvalue;
}
void LinkedQueue::view()
{
	ChainNode *p = front;
	if (rear == 0)					//rear이 null일 경우(비어있을 경우)
	{
		cout << "비어있음";
	}
	for (p; p->link; p = p->link)
	{
		cout << "스택(FIFO순):" << p->data << " ";
	}
	cout << p->data << "\n";		//마지막 데이터 반환
}

int main()
{
	int menu, push_num;
	LinkedStack stack;
	LinkedQueue queue;
	cout << "        -----메뉴-----\n";
	cout << "1.스택에 삽입    2.큐에 삽입\n";
	cout << "3.스택에서 삭제  4.큐에서 삭제\n";
	cout << "5.스택 내용 보기 6.큐 내용 보기\n";
	cout << "7.프로그램 종료\n";
	while (1)
	{
		cout << "메뉴 선택(삽입은 숫자도 입력):";
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
			cout << "1~7중에 선택";
		}
	}
}