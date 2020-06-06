#include "mylibr.h"
#include <iostream>
using namespace std;
double Sum(double a, double b) {
	return a + b;
}
double Mult(double a, double b) {
	return a * b;
}
void Info() {
	cout << __cplusplus << endl;
	cout << __DATE__ << endl;
	cout << __TIME__ << endl;
	cout << __LINE__ << endl;
	cout << __FILE__ << endl;
}
