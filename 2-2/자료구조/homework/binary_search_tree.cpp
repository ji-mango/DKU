#include <iostream>
using namespace std;

class BstNode;
class BST {
private:
	BstNode *root;
public:
	bool Insert(int x);
	bool Delete(int x);
	BstNode *Search(int x);
	void inorder();
	void inorder(BstNode * CurrentNode);
	BST() { root = 0; }
};

class BstNode {
	friend BST;
private:
	int key;
	BstNode *LeftChild;
	BstNode *RightChild;
public:
	BstNode() {
		LeftChild = 0;
		RightChild = 0;
		key = 0;
	}
};

bool BST::Insert(int x)
{
	BstNode *p = root;
	BstNode *q = 0;						//p의 부모
	while (p) {
		q = p;
		if (x == p->key) {				//x가 이미 존재
			cout << "키가 이미 존재\n";
			return false;				//삽입안함
		}
		if (x < p->key)
			p = p->LeftChild;
		else
			p = p->RightChild;
	}
	p = new BstNode;					//삽입을 수행
	p->LeftChild = p->RightChild = 0;
	p->key = x;
	if (!root)							//빈 트리일 경우
		root = p;						//p가 root를 가리킴
	else if (x < q->key)				//삽입하려는 값이 q의 값보다 작으면
		q->LeftChild = p;				//왼쪽 자식에 삽입
	else								//삽입하려는 값이 q의 값보다 크면
		q->RightChild = p;				//오른쪽 자식에 삽입
	return true;
}
bool BST::Delete(int x) {
	BstNode *p = root;
	BstNode *q = 0;						//p의 선행노드

	while (p)							//빈 트리가 아닌 경우
	{
		if (x < p->key)					//x가 p보다 작을 경우
		{
			q = p;
			p = p->LeftChild;			//p의 왼쪽자식으로 이동
		}
		else if (x > p->key)			//x가 p보다 클 경우
		{
			q = p;
			p = p->RightChild;			//p의 오른쪽자식으로 이동
		}
		else							//x가 p와 같을 경우
		{
			break;
		}
	}
	if (!p)								//while문을 돌고 일치하는 값이 없을 경우
	{
		cout << "존재하지 않는 값입니다.\n";
		return false;
	}

	if (p->LeftChild == 0 && p->RightChild == 0) //단말노드 삭제의 경우
	{
		if (x < q->key)							//p가 q의 왼쪽자식일 경우
		{
			q->LeftChild = 0;					//왼쪽자식 null
			delete p;
		}
		else									//p가 q의 오른쪽자식일 경우
		{
			q->RightChild = 0;					//오른쪽자식 null
			delete p;
		}
	}
	else if (p->LeftChild == 0 || p->RightChild == 0)//삭제할 노드의 자식이 하나인 경우
	{
		if (p->LeftChild == 0)					//오른쪽 자식만 있는 경우
		{
			if (x < q->key)						//p가 q의 왼쪽 자식인 경우
			{
				q->LeftChild = p->RightChild;	//p오른쪽 자식을 q왼쪽 자식으로
				delete p;
			}
			else								//p가 q의 오른쪽 자식인 경우
			{
				q->RightChild = p->RightChild;	//p오른쪽 자식을 q오른쪽 자식으로
				delete p;
			}
		}
		else									//왼쪽 자식만 있는 경우
		{
			if (x < q->key)						//p가 q의 왼쪽 자식인 경우
			{
				q->LeftChild = p->LeftChild;	//p왼쪽 자식을 q왼쪽 자식으로
				delete p;
			}
			else								//p가 q의 오른쪽 자식인 경우
			{
				q->RightChild = p->LeftChild;	//p왼쪽 자식을 q오른쪽 자식으로
				delete p;
			}
		}
	}

	else										//두개의 자식을 갖는 노드의 삭제
	{
		BstNode *t = p;
		q = p;
		p = p->RightChild;						//p의 오른쪽자식으로 p의 위치 변경
		while (p->LeftChild)					//p의 왼쪽자식이 있을때까지
		{
			q = p;								//q는 p의 선행노드
			p = p->LeftChild;					//p를 p의 왼쪽자식으로 이동
		}
		t->key = p->key;						//t를 오른쪽 서브트리 가장 작은 노드로 대체
		if (t == q)								//가장 작은노드의 선행노드가 삭제값의 위치(t)일 때 
		{
			t->RightChild = p->RightChild;		//가장작은노드의 오른쪽자식을 t의 오른쪽자식에 넣음
			delete p;
		}
		else if (p->RightChild)					//p의 오른쪽 자식이 있을 때
		{
			q->LeftChild = p->RightChild;		//p의 오른쪽자식을 q의 왼쪽자식에 넣음
			delete p;
		}
		else									//p가 단말노드일 때
		{
			q->LeftChild = 0;					//q의 왼쪽자식에 null
			delete p;
		}
	}
	return true;
}
BstNode* BST::Search(int x)
{
	for (BstNode *p = root; p;)										//p가 root부터 탐색
	{
		if (x == p->key)
			return p;
		if (x < p->key)
			p = p->LeftChild;
		else
			p = p->RightChild;
	}
	return 0;
}

void BST::inorder()
{
	inorder(root);
}
void BST::inorder(BstNode *CurrentNode)
{
	if (CurrentNode)
	{
		inorder(CurrentNode->LeftChild);							//왼쪽 자식으로 이동
		cout << CurrentNode->key << ' ';							//key 출력
		inorder(CurrentNode->RightChild);							//오른쪽 자식으로 이동
	}
}
int main()
{
	BST *test = new BST();
	int menu, key_cnt, key_num;
	cout << "1.삽입 2.삭제 3.탐색 4.중위우선순회 5.종료\n";
	while (1)
	{
		cout << "메뉴 선택: ";
		cin >> menu;

		switch (menu)
		{
		case 1:
			cout << "입력할 키 개수: ";
			cin >> key_cnt;
			cout << "삽입할 값 입력: ";
			for (int i = 0; i < key_cnt; i++)
			{
				cin >> key_num;
				test->Insert(key_num);
			}
			break;
		case 2:
			cout << "삭제할 값 입력: ";
			cin >> key_num;
			test->Delete(key_num);
			break;
		case 3:
			cout << "탐색할 값 입력: ";
			cin >> key_num;
			if (test->Search(key_num) == 0)
				cout << "실패\n";
			else
				cout << "성공\n";
			break;
		case 4:
			cout << "중위우선순회: ";
			test->inorder();
			cout << "\n";
			break;
		case 5:
			cout << "프로그램 종료\n";
			break;
		}
		if (menu == 5)
			break;
	}
	return 0;
}
