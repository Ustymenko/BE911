#include <iostream>
using namespace std;
class  Room {
	friend class House;
	double s;
public:
	Room() { s = 30; }
};

class House
{
	friend class Room;
public:
	void Show() {
		cout << R.s;
	}
private:
	Room R;
};
//зовнішня функція
class Number
{
public:
	Number(int a, int b) :a(a), b(b) {}
private:
	int a, b;
	friend bool TestDiv(Number ob);
};

bool TestDiv(Number ob) {
	return ob.a % ob.b == 0;
}

//зовнішня функція декільком класам
class NumberB;
class NumberA
{
public:
	NumberA(int a) :a(a) {}
private:
	int a;
	friend bool TestDiv(NumberA obA, NumberB obB);
};
class NumberB
{
public:
	NumberB(int b) :b(b) {}
private:
	int b;
	friend bool TestDiv(NumberA obA, NumberB obB);
};

bool TestDiv(NumberA obA, NumberB obB) {
	return obA.a % obB.b == 0;
}

//дружня функція з іншого класу
class Num1;
class Num2
{
public:
	Num2(int a) :a(a) {}
	/*bool Dilen(Num1 N1) { error
		return a % N1.b == 0;
	}*/
	bool Dilen(Num1 N1);
private:
	int a;
};
class Num1
{
public:
	Num1(int a) :b(a) {}
private:
	int b;
	friend bool Num2::Dilen(Num1 N1);
};
bool Num2::Dilen(Num1 N1)
{
	return a % N1.b == 0;	
}

int main()
{
	Number ob(10, 3);
	cout << TestDiv(ob) << endl;

	NumberA A(10);
	NumberB B(2);
	cout << TestDiv(A, B) << endl;

	Num1 A1(2);
	Num2 B2(10);
	cout << B2.Dilen(A1) << endl;
}

