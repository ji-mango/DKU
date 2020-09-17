#include<iostream>
using namespace std;

class Polynomial;
class Term {
	friend Polynomial;
private:
	float coef;			//계수
	int exp;			//지수
};
class Polynomial
{
private:
	Term *termArray;	//0이 아닌 항의 배열
	int capacity;		//termArray의 크기
	int terms;			//0이 아닌 항의 수
public:
	void Print(void);
	void NewTerm(const float theCoeff, const int theExp);
	Polynomial Add(Polynomial b);
	Polynomial multiply(Polynomial b);
	//Polynomial(void);
	//~Polynomial(void);
};

Polynomial Polynomial::Add(Polynomial b)			//a(x)와 b(x)를 더한 결과를 반환
{
	Polynomial c;
	int aPos = 0, bPos = 0;

	while ((aPos < terms) && (bPos < terms))
	{
		if (termArray[aPos].exp == b.termArray[bPos].exp)
		{
			float t = termArray[aPos].coef + b.termArray[bPos].coef;
			if (t) c.NewTerm(t, termArray[aPos].exp);
			aPos++; bPos++;
		}
		else if (termArray[aPos].exp < b.termArray[bPos].exp)
		{
			c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
			bPos++;
		}
		else
		{
			c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
			aPos++;
		}
	}
	//a(x)의 나머지항들 추가
	for (; aPos < terms; aPos++)
		c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
	//b(x)의 나머지항들 추가
	for (; bPos < terms; bPos++)
		c.NewTerm(termArray[bPos].coef, termArray[bPos].exp);

	return c;
}

void Polynomial::NewTerm(const float theCoeff, const int theExp)
{
	if (terms == capacity)
	{
		//termArray크기 두배로 확장
		capacity *= 2;
		Term *temp = new Term[capacity];
		for (int i = 0; i < terms; i++)
		{
			temp[i] = termArray[i];
		}
		delete[] termArray;
		termArray = temp;
	}

	termArray[terms].coef = theCoeff;
	termArray[terms].exp = theExp;
}

void Polynomial::Print(void)
{
	for (int i = 0; i < terms; i++)
	{
		cout << termArray[i].coef << "x^" << termArray[i].exp;
		if (i - 1 == terms)
			cout << "+";
	}

}

Polynomial Polynomial::multiply(Polynomial b)
{
	Polynomial c;
	int aPos, bPos;

	for (; aPos < terms; aPos++)
	{
		Polynomial d;
		for (; bPos < terms; bPos++)
		{
			float multi = termArray[aPos].coef*b.termArray[bPos].exp;
			int add = termArray[aPos].exp + b.termArray[bPos].exp;
			d.NewTerm(multi, add);
		}
		c = c.Add(d);
	}

	return c;
}

int main()
{
	Polynomial A, B, C;
	int i, n, e;
	float c;

	cout << "다항식 A의 항의 수:";
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cout << "다항식 A의" << i << "번째 항의 계수와 지수:";
		cin >> c >> e;

		A.NewTerm(c, e);
	}
	cout << "다항식 B의 항의 수:";
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cout << "다항식 B의" << i << "번째 항의 계수와 지수:";
		cin >> c >> e;

		B.NewTerm(c, e);
	}
	cout << "다항식A";
	A.Print();
	cout << "다항식B";
	B.Print();
	C = A.multiply(B);
	C.Print();

	return 0;
}
