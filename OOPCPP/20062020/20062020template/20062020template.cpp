#include <iostream>
using namespace std;
//int Max(int a, int b) {
//	return a > b ? a : b;
//}
//double Max(double a, double b) {
//	return a > b ? a : b;
//}
//template<class T>
//template<typename T, typename U>
//T Max(T a, U b) {
//	return a > b ? a : b;
//}
//template<typename Res, typename T, typename U>
//Res Max(T a, U b) {
//	return a > b ? a : b;
//}
//50   | 20.99
//5.9  | 20 
///	
///
template< typename T, typename U>
auto Max(T a, U b) ///->decltype(a+b)
{
	return a > b ? a : b;
}
///
template<typename T>
T* Max(T* a, T* b)
{
	return strcmp(a, b) < 0 ? b : a;
}

//const char* Max(const char* a, const char* b)
//{
//	return strcmp(a,b)<0 ? b : a;
//}
int main()
{
	{
		int a = 10;
		int b = 20;
		//cout << "max(" << a << "," << b << ")=" << Max<int, int, int>(a, b) << endl;
	//	cout << "max(" << a << "," << b << ")=" << Max<int>(a, b) << endl;
		cout << "max(" << a << "," << b << ")=" << Max(a, b) << "\t" << typeid(Max(a, b)).name() << endl;
	}
	{
		double a = 10.99;
		double b = 20.99;
		//cout << "max(" << a << "," << b << ")=" << Max<double>(a, b) << endl;
		cout << "max(" << a << "," << b << ")=" << Max(a, b) << "\t" << typeid(Max(a, b)).name() << endl;
	}
	{
		int a = 10;
		double b = 20.99;
		//	cout << "max(" << a << "," << b << ")=" << Max<double>(a, b) << endl;
		cout << "max(" << a << "," << b << ")=" << Max(a, b) << "\t" << typeid(Max(a, b)).name() << endl;
	}
	{
		double a = 10.99;
		int b = 5;
		//cout << "max(" << a << "," << b << ")=" << Max<double>(a, b) << endl;
		cout << "max(" << a << "," << b << ")=" << Max(a, b) << "\t" << typeid(Max(a, b)).name() << endl;
	}
	{
		double a = 1.99;
		int b = 15;
		//cout << "max(" << a << "," << b << ")=" << Max<double>(a, b) << endl;
		cout << "max(" << a << "," << b << ")=" << Max(a, b) << "\t" << typeid(Max(a, b)).name() << endl;
	}
	{
		char a[] = "Anna";
		char b[] = "Petro";
		cout << "max(" << a << "," << b << ")=" << Max(a, b) << "\t" << typeid(Max(a, b)).name() << endl;
	}
	{
		char a[] = "Anna";
		char b[] = "Petro";
		//cout << "max(" << a << "," << b << ")=" << Max<double>(a, b) << endl;
		cout << "max(" << a << "," << b << ")=" << Max((const char*)a, (const char*)b) << "\t" << typeid(Max((const char*)a, (const char*)b)).name() << endl;
	}
	//end

}
