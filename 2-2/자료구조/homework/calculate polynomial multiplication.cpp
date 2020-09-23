#include <iostream>
using namespace std;

class Polynomial;
class Term {
	friend Polynomial;
private:
	float coef;			//���
	int exp;			//����
};
class Polynomial
{
private:
	Term *termArray;	//0�� �ƴ� ���� �迭
	int capacity;		//termArray�� ũ��
	int terms;			//0�� �ƴ� ���� ��
public:
	void Print(void);
	void NewTerm(const float theCoeff, const int theExp);
	Polynomial Add(Polynomial b);
	Polynomial multiply(Polynomial b);
	Polynomial(void);
	~Polynomial(void);
};

Polynomial::Polynomial(void)
{
	capacity = 4;
	terms = 0;
	termArray = new Term[capacity];  // ũ�� 4 �� �迭 ����
}

Polynomial::~Polynomial(void)
{

}

Polynomial Polynomial::Add(Polynomial b)
// a(x)(*this�� ��)�� b(x)�� ���� ����� ��ȯ�Ѵ�.
{
	Polynomial c;
	int aPos = 0, bPos = 0;

	while ((aPos < terms) && (bPos < b.terms))
		if (termArray[aPos].exp == b.termArray[bPos].exp) {
			float t = termArray[aPos].coef + b.termArray[bPos].coef;
			if (t) c.NewTerm(t, termArray[aPos].exp);
			aPos++; bPos++;
		}
		else if (termArray[aPos].exp < b.termArray[bPos].exp) {
			c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
			bPos++;
		}
		else {
			c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
			aPos++;
		}

	// A(x)(*this)�� ������ �׵��� �߰��Ѵ�.
	for (; aPos < terms; aPos++)
		c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);

	// B(x)�� ������ �׵��� �߰��Ѵ�.
	for (; bPos < b.terms; bPos++)
		c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);

	return c;
} // Add�� ��


void Polynomial::NewTerm(const float theCoeff, const int theExp)
// ���ο� ���� termArray ���� ÷���Ѵ�.
{
	if (terms == capacity)
	{//termArray�� ũ�⸦ �� ��� Ȯ��
		capacity *= 2;
		Term *temp = new Term[capacity];           // ���ο� �迭
		for (int i = 0; i < terms; i++)
			temp[i] = termArray[i];
		delete[] termArray;                       // ���� �޸𸮸� ��ȯ
		termArray = temp;
	}
	termArray[terms].coef = theCoeff;
	termArray[terms++].exp = theExp;
}

Polynomial Polynomial::multiply(Polynomial b)
{
	Polynomial c;									//������ ���� ������ ���ؼ� ������ ��ü ����
	int aPos, bPos;

	for (aPos = 0; aPos < terms; aPos++)				//���׽� A ���� ����ŭ �ݺ�
	{
		Polynomial d;								//���� �� �����ϱ����� ��ü ����
		for (bPos = 0; bPos < b.terms; bPos++)			//���׽� B ���� ����ŭ �ݺ�
		{
			float multi = termArray[aPos].coef*b.termArray[bPos].coef;	//��� ����
			int add = termArray[aPos].exp + b.termArray[bPos].exp;		//���� ����
			d.NewTerm(multi, add);
		}
		c = c.Add(d);								//���Ѱ͵��� �������� ����
	}

	return c;
}


void Polynomial::Print()
{
	int i;

	cout << "\n";
	if (terms) {
		for (i = 0; i < terms - 1; i++)
			cout << termArray[i].coef << " x^" << termArray[i].exp << " + ";
		// ������ ���� ���
		cout << termArray[i].coef << " x^" << termArray[i].exp << "\n";
	}
	else
		cout << " No terms ";

}

int main()
{
	Polynomial A, B, C;
	int i, n, e;
	float c;

	cout << "���׽� A�� ���� ��:";
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cout << "���׽� A��" << i << "��° ���� ����� ����:";
		cin >> c >> e;

		A.NewTerm(c, e);
	}
	cout << "���׽� B�� ���� ��:";
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cout << "���׽� B��" << i << "��° ���� ����� ����:";
		cin >> c >> e;

		B.NewTerm(c, e);
	}
	cout << "���׽�A";
	A.Print();
	cout << "���׽�B";
	B.Print();
	C = A.multiply(B);
	cout << "���׽�A X ���׽�B";
	C.Print();

	return 0;
}