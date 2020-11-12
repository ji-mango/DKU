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
	BstNode *q = 0;						//p�� �θ�
	while (p) {
		q = p;
		if (x == p->key) {				//x�� �̹� ����
			cout << "Ű�� �̹� ����\n";
			return false;				//���Ծ���
		}
		if (x < p->key)
			p = p->LeftChild;
		else
			p = p->RightChild;
	}
	p = new BstNode;					//������ ����
	p->LeftChild = p->RightChild = 0;
	p->key = x;
	if (!root)							//�� Ʈ���� ���
		root = p;						//p�� root�� ����Ŵ
	else if (x < q->key)				//�����Ϸ��� ���� q�� ������ ������
		q->LeftChild = p;				//���� �ڽĿ� ����
	else								//�����Ϸ��� ���� q�� ������ ũ��
		q->RightChild = p;				//������ �ڽĿ� ����
	return true;
}
bool BST::Delete(int x) {
	BstNode *p = root;
	BstNode *q = 0;						//p�� ������

	while (p)							//�� Ʈ���� �ƴ� ���
	{
		if (x < p->key)					//x�� p���� ���� ���
		{
			q = p;
			p = p->LeftChild;			//p�� �����ڽ����� �̵�
		}
		else if (x > p->key)			//x�� p���� Ŭ ���
		{
			q = p;
			p = p->RightChild;			//p�� �������ڽ����� �̵�
		}
		else							//x�� p�� ���� ���
		{
			break;
		}
	}
	if (!p)								//while���� ���� ��ġ�ϴ� ���� ���� ���
	{
		cout << "�������� �ʴ� ���Դϴ�.\n";
		return false;
	}

	if (p->LeftChild == 0 && p->RightChild == 0) //�ܸ���� ������ ���
	{
		if (x < q->key)							//p�� q�� �����ڽ��� ���
		{
			q->LeftChild = 0;					//�����ڽ� null
			delete p;
		}
		else									//p�� q�� �������ڽ��� ���
		{
			q->RightChild = 0;					//�������ڽ� null
			delete p;
		}
	}
	else if (p->LeftChild == 0 || p->RightChild == 0)//������ ����� �ڽ��� �ϳ��� ���
	{
		if (p->LeftChild == 0)					//������ �ڽĸ� �ִ� ���
		{
			if (x < q->key)						//p�� q�� ���� �ڽ��� ���
			{
				q->LeftChild = p->RightChild;	//p������ �ڽ��� q���� �ڽ�����
				delete p;
			}
			else								//p�� q�� ������ �ڽ��� ���
			{
				q->RightChild = p->RightChild;	//p������ �ڽ��� q������ �ڽ�����
				delete p;
			}
		}
		else									//���� �ڽĸ� �ִ� ���
		{
			if (x < q->key)						//p�� q�� ���� �ڽ��� ���
			{
				q->LeftChild = p->LeftChild;	//p���� �ڽ��� q���� �ڽ�����
				delete p;
			}
			else								//p�� q�� ������ �ڽ��� ���
			{
				q->RightChild = p->LeftChild;	//p���� �ڽ��� q������ �ڽ�����
				delete p;
			}
		}
	}

	else										//�ΰ��� �ڽ��� ���� ����� ����
	{
		BstNode *t = p;
		q = p;
		p = p->RightChild;						//p�� �������ڽ����� p�� ��ġ ����
		while (p->LeftChild)					//p�� �����ڽ��� ����������
		{
			q = p;								//q�� p�� ������
			p = p->LeftChild;					//p�� p�� �����ڽ����� �̵�
		}
		t->key = p->key;						//t�� ������ ����Ʈ�� ���� ���� ���� ��ü
		if (t == q)								//���� ��������� �����尡 �������� ��ġ(t)�� �� 
		{
			t->RightChild = p->RightChild;		//������������� �������ڽ��� t�� �������ڽĿ� ����
			delete p;
		}
		else if (p->RightChild)					//p�� ������ �ڽ��� ���� ��
		{
			q->LeftChild = p->RightChild;		//p�� �������ڽ��� q�� �����ڽĿ� ����
			delete p;
		}
		else									//p�� �ܸ������ ��
		{
			q->LeftChild = 0;					//q�� �����ڽĿ� null
			delete p;
		}
	}
	return true;
}
BstNode* BST::Search(int x)
{
	for (BstNode *p = root; p;)										//p�� root���� Ž��
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
		inorder(CurrentNode->LeftChild);							//���� �ڽ����� �̵�
		cout << CurrentNode->key << ' ';							//key ���
		inorder(CurrentNode->RightChild);							//������ �ڽ����� �̵�
	}
}
int main()
{
	BST *test = new BST();
	int menu, key_cnt, key_num;
	cout << "1.���� 2.���� 3.Ž�� 4.�����켱��ȸ 5.����\n";
	while (1)
	{
		cout << "�޴� ����: ";
		cin >> menu;

		switch (menu)
		{
		case 1:
			cout << "�Է��� Ű ����: ";
			cin >> key_cnt;
			cout << "������ �� �Է�: ";
			for (int i = 0; i < key_cnt; i++)
			{
				cin >> key_num;
				test->Insert(key_num);
			}
			break;
		case 2:
			cout << "������ �� �Է�: ";
			cin >> key_num;
			test->Delete(key_num);
			break;
		case 3:
			cout << "Ž���� �� �Է�: ";
			cin >> key_num;
			if (test->Search(key_num) == 0)
				cout << "����\n";
			else
				cout << "����\n";
			break;
		case 4:
			cout << "�����켱��ȸ: ";
			test->inorder();
			cout << "\n";
			break;
		case 5:
			cout << "���α׷� ����\n";
			break;
		}
		if (menu == 5)
			break;
	}
	return 0;
}
