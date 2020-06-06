#include <iostream>
#include <time.h>
using namespace std;

int* createarr(int n) {
	return new int[n] {0};
}
void print(int* mas, size_t length) {
	for (size_t i = 0; i < length; i++)
		cout << mas[i] << '\t';
	cout << '\n';
}
void setrnd(int* mas, size_t length, int a = -10, int b = 10) {//mas =0x1317
	for (size_t i = 0; i < length; i++)
		mas[i] = a + rand() % (b - a + 1);
	//mas = nullptr;//mas =0
}

size_t CountPos(int* mas, size_t length) {
	size_t k = 0;
	for (size_t i = 0; i < length; i++) {
		if (mas[i] > 0) k++;
	}
	/*cout << '\n';
	cout << k;*/
	return k;
}
unsigned int  CountNeg(int* mas, unsigned int length) {
	unsigned int k = 0;
	for (unsigned int i = 0; i < length; i++) {
		if (mas[i] < 0) k++;
	}
	return k;
}

void  CountNegPosZero(int* mas, size_t length, size_t& p, size_t& n, size_t& z) {
	unsigned int k = 0;
	for (unsigned int i = 0; i < length; i++) {
		if (mas[i] == 0) k++;
	}
	z = k;
	n = 0;
	for (unsigned int i = 0; i < length; i++) {
		if (mas[i] < 0) n++;
	}
	p = CountPos(mas, length);
}



void Test(int& a) {
	a = 1000;
}
//						0x1425			6				2
//	0  1        4
//  -5 10 0 -36 -15 -6
int PositionPositive(int* mas, size_t length, size_t number) {
	int k = 0;
	for (size_t i = 0; i < length; i++)
		if (mas[i] > 0)
		{
			k++;
			if (k == number)
				return i;
		}
	return -1;
}
//	0  1        4
//  -5 10 0 -36 15 -6
//					0x1425			6			1		2	
void SumBetween(int* mas, size_t length, size_t a, size_t b) {
	int pos1 = PositionPositive(mas, length, a);
	int pos2 = PositionPositive(mas, length, b);
	if (pos1 != -1 && pos2 != -1) {
		int s = 0;
		for (size_t i = pos1 + 1; i < pos2; i++)
			s += mas[i];
		cout << "Sum=" << s << endl;
	}
	else
		cout << "not positive elements" << endl;
}
bool SumBetween2(int* mas, size_t length, size_t a, size_t b, int& s) {
	s = 0;
	int pos1 = PositionPositive(mas, length, a);
	int pos2 = PositionPositive(mas, length, b);
	if (pos1 != -1 && pos2 != -1) {
		for (size_t i = pos1 + 1; i < pos2; i++)
			s += mas[i];
		return true;
	}
	return false;
}

/////ax^2+bx+c=0
///0//"not root\n";
///2//"x1=" << x1 << " x2=" 
///1//"x=" << x << endl;
///3//cout << "inf root\n";
/////int EquationX2(double a, double b, double c,double& x1, double& x2) 
	//
void EquationX2(double a, double b, double c) {
	double d = b * b - 4 * a * c;
	if (a != 0)
		if (d > 0) {
			double x1 = (-b - sqrt(d)) / (2 * a);
			double x2 = (-b + sqrt(d)) / (2 * a);
			cout << "x1=" << x1 << " x2=" << x2 << endl;
		}
		else
			if (d == 0) {
				double x = -b / (2 * a);
				cout << "x=" << x << endl;
			}
			else cout << "not root\n";
	else {//bx+c=0
		if (b == 0) {
			//c=0
			if (c==0)
				cout << "inf root\n";
			else //5=0
				cout << "not root\n";
		}
		else {
			if (c == 0) //bx=0
				cout << "x=" << 0 << "\n";
			else //bx+c=0
				cout << "x="<<-c/b<<"\n";
		}
	}
}




void test1()
{
	int count = 10;
	//Test(count);
	//std::cout << "count ="<< count;
	std::cout << "Enter n=";
	cin >> count;
	int* arr = createarr(count); //0x1317
//	setrnd(arr, count);
//	setrnd(arr, count,-100);
	setrnd(arr, count, -100, 100);//0x1317
	print(arr, count);
	cout << "CountPos=" << CountPos(arr, count);//2;
	cout << endl;
	cout << "CountNeg=" << CountNeg(arr, count);//2;
	cout << endl;
	size_t p = 10, n = 20, z = 30;
	CountNegPosZero(arr, count, p, n, z);
	cout << "pos=" << p << endl;
	cout << "neg=" << n << endl;
	cout << "zer=" << z << endl;
	//знайти суму елементів між 2 позитивним елементом та 5 позитивним елементом

	cout << "pos2=" << PositionPositive(arr, count, 2) << endl;
	SumBetween(arr, count, 2, 4);

	int sum = 0;
	if (SumBetween2(arr, count, 2, 4, sum))
		cout << "Sum=" << sum << endl;
	else
		cout << "not positive elements" << endl;


	delete[] arr;
}

int main()
{
	srand(time(0));
	//test1();
	int a = 1, b = -5, c = 6;
	EquationX2(a, b, c);
	a = 1;
	b = 5;
	c = 6;
	EquationX2(a, b, c);
	a = 10;
	b = 5;
	c = 6;
	EquationX2(a, b, c);
	a = 0;
	b = 5;
	c = 6;
	EquationX2(a, b, c);
	a = 0;
	b = 0;
	c = 6;
	EquationX2(a, b, c);
	a = 0;
	b = 6;
	c = 0;
	EquationX2(a, b, c);
}
