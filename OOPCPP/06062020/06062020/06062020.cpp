#include <iostream>
using namespace std;
//const double Pi = 4 * atan(1);
class Circle
{
public:
	Circle(int, int, int);
	Circle();
	void Print();
	int Diametr();
	double Square();
	double Length();
	static void SetColor(int col);
	static int GetColor();
private:
	static int color;
	int x;
	int y;
	int R;
	//const double Pi;// = 4 * atan(1);
	static const double Pi;// = 4 * atan(1);
};
const double Circle::Pi = 4 * atan(1);
int  Circle::color = 15;

Circle::Circle() :Circle(0, 0, 0)
{
	//Pi = 4 * atan(1);
}
Circle::Circle(int _x, int _y, int _R) : x(_x), y(_y), R(_R)
//Circle::Circle(int x, int y, int R) : x(x), y(y), R(R), Pi (4 * atan(1))
{

	//Pi = 6;
	//x = x;
	/*x = _x;
	y = _y;
	R = _R;*/
}
void Circle::Print()
{
	cout << "x=" << x << " y=" << y << " R=" << R << " Color=" << color << endl;
}
int Circle::Diametr()
{
	return 2 * R;
}
double Circle::Square()
{
	return Pi * R * R;
}
double Circle::Length()
{

	return 2 * Pi * R;
}
void Circle::SetColor(int col)
{
	//this->R = col;
	color = col;
}
int Circle::GetColor()
{
	return color;
}
int main()
{
	Circle Kolo(1, 1, 1);
	Kolo.Print();
	cout << "\nD=" << Kolo.Diametr() << endl;
	cout << "S=" << Kolo.Square() << endl;
	cout << "L=" << Kolo.Length() << endl;
	Circle H;
	H.Print();

	//Kolo.color = 5;
	//Circle::color = 7;

	Circle::SetColor(7);
	Kolo.SetColor(17);
	cout << Circle::GetColor() << endl;

	Kolo.Print();
	H.Print();

	cout << "The end main\n" << sizeof(Circle);
}