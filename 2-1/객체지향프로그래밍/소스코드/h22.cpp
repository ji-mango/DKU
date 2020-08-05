//기본 클래스 파생클래스 가상함수 이용
#include <iostream>
#include <cstring>
using namespace std;

class B_class {
protected:
	char author[80];
public:
	void put_author(const char *s)
	{
		strcpy_s(author, s);
	}
	virtual void show_author()
	{
		cout << author << "\n";
	}
};

class D_class : public B_class {
private:
	char title[80];
public:
	void put_title(const char *num)
	{
		strcpy(title, num);
	}
	void show_author()
	{
		cout << "Author: " << author << "\n";
		cout << "Title: " << title << "\n";
	}
};

int main()
{
	B_class *p;
	B_class B_ob;

	D_class *dp;
	D_class D_ob;

	p = &B_ob;
	p->put_author("Tom Clancy");
	dp = &D_ob;
	dp->put_author("William Shakespeare");
	dp->put_title("The Tempest");
	cout << "아빠 클래스\n";
	p->show_author();
	cout << "파생 클래스\n";
	dp->show_author();
	return 0;
}