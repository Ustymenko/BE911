#include <iostream>
#include <time.h>
#include "mylibr.h"

using namespace std;

#define PI 3.1415
#define Mult(a,b) ((a)*(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define SIZEARRAY(arr) (sizeof(arr) / sizeof(*(arr)))
#define GetRnd(min,max) ((min)+rand()%(int)((max)-(min)+1))

#define ToStr(x) ( #x )
#define ToChar(x) ( #@x )

#define CALL(Name) Print##Name()

//#define DEBUG
//#define ARRCOLUMN
//#define ARRROW
//#if
//#ifdef 
//#else
//#ifndef 
//#endif 
//#elif
void TEST() {
	cout <<__cplusplus << endl;
	cout <<__DATE__ << endl;
	cout <<__TIME__ << endl;
	cout <<__LINE__ << endl;
	cout <<__FILE__ << endl;
}



void PrintFirst() {

	cout << "PrintFirst" << endl;
}
void PrintSecond() {

	cout << "PrintSecond" << endl;
}
void rrrr() {
		int N;
		cin >> N;
		int prev = N, count = 0;
		while (N != 0) {
			if (cin >> N && N)
			{
				count++;
			}
			cin >> N;

		}
		cout << count;
		
	
}

void Print(int* mas) {
	//(sizeof(mas) / sizeof(*(mas))) // 4/4=>1
	cout << SIZEARRAY(mas) << endl;
}
void test2()
{
	cout << PI << endl;
	cout << Mult(3, 4) << endl;//debug
	cout << Mult(2.5, 2.5) << endl;
	cout << Mult(2 + 3, 2 + 3) << endl; //2+3*2+3 => (2+3)*(2+3)

	cout << Max(2 + 5, 20 + 3) << endl;

	int mas[]{ 8,2,33,5,6,49 };
	int sum = 0;
	//(sizeof(mas) / sizeof(*(mas))) //24/4=>6
	for (size_t i = 0; i < SIZEARRAY(mas); i++)
	{
		sum += mas[i];
#if defined(DEBUG)
		cout << "sum"<<i<< "="<< sum << endl;//debug
#endif

	}
//#if defined(ARRCOLUMN)
#ifdef ARRCOLUMN
	for (size_t i = 0; i < SIZEARRAY(mas); i++)
	{
		cout << "mas[" << i << "]=" << mas[i] << endl;
	}
#elif defined(ARRROW)
	for (size_t i = 0; i < SIZEARRAY(mas); i++)
	{
		cout << mas[i] << "\t";
	}
	cout << endl;
#else
	for (size_t i = 0; i < SIZEARRAY(mas); i++)
			cout << mas[i];
	cout << endl; 
#endif


	cout <<"sum="<< sum << endl;//debug
	cout << SIZEARRAY(mas) << endl;
	Print(mas);
	srand(time(0));
	cout << GetRnd(-5, 5) << endl;
	cout << GetRnd(-10, 10) << endl;
	for (size_t i = 0; i < 10; i++)
		cout << GetRnd(-5.2, 8.9) << "\t";
	cout << "--------------------------------------------\n";

	cout << ToStr(159) << endl;
	cout << ToStr(raketa) << endl;
	cout << ToStr("raketa") << endl;

	const char* str1 = ToStr(159);
	const char* str2 = ToStr(153.36494);
	const char* str3 = ToStr(ItStep);
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;
	char c1 = ToChar(Q);
	cout << c1 << endl;
	char c2 = ToChar(8);
	cout << c2 << endl;
	CALL(First);
	CALL(Second);

	//#define PI 40
	//#undef PI
	//	cout << endl;
	//	cout << PI << endl;
	TEST();
}
int main() {
	rrrr();

	//test2();
//#undef Mult
//	TEST();
//	cout << Mult(10, 50) << endl;
//	cout << Sum(10,50) << endl;
//	Info();

}