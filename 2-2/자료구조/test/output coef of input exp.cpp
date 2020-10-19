#include <iostream>
using namespace std;

class polynomial;
class term {
friend polynomial;
private:
	float coef;
	int exp;
};

class polynomial {
private:
	term *termarray;
	int capacity;
	int terms;
public:
	float return_coef(int exp_num);
	void newTerm(const float theCoeff, const int theExp);
	polynomial(void);
	~polynomial(void);
};

polynomial::polynomial(void)
{
	capacity = 4;
	terms = 0;
	termarray = new term[capacity];  // 크기 4 로 배열 생성
}

polynomial::~polynomial(void)
{

}

void polynomial::newTerm(const float theCoeff, const int theExp)
{
	if (terms == capacity)
	{
		capacity *= 2;
		term *temp = new term[capacity];
		for (int i = 0; i < terms; i++)
		{
			temp[i] = termarray[i];
		}
		delete[] termarray;
		termarray = temp;
	}
	termarray[terms].coef = theCoeff;
	termarray[terms++].exp = theExp;
}
float polynomial::return_coef(int exp_num)
{
	int aPos = 0;
	float coef_num = 0;
	for (; aPos <= terms; aPos++)
	{
		if (termarray[aPos].exp == exp_num)
			coef_num=termarray[aPos].coef;
	}
	if (coef_num == 0)
		return 0;
	else
		return coef_num;
}

int main()
{
	int exp_num;
	polynomial a;
	a.newTerm(3, 4);
	a.newTerm(6, 2);
	a.newTerm(1, 0);
	cout << "계수 입력:";
	cin >> exp_num;
	cout << exp_num << "의 계수: " << a.return_coef(exp_num);
} 

