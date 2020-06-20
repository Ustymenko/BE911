#include <iostream>
#include <time.h>
#include <algorithm>
using namespace std;
typedef bool (*CMP)(int a, int b);
class Array {
private:
	int N;
	int* array;
	void QuickSort(int left, int right);
public:
	Array();
	explicit Array(int);
	Array(const Array& Ar);
	Array(Array&& a) noexcept;
	~Array();
	int Size() const;
	const int* Data() const;
	int* Data();
	void Clear();
	void Print();
	void SetRnd(int min, int max);
	void Input();
	void Quicksort();
	Array& operator=(const Array& Ar);//this = Ar
	Array& operator=(Array&& a)  noexcept;
	Array operator+(const Array& RAr) const;//this + RAr
	Array operator+(int el) const; //this + el
	//Array operator+(int el); //el   + this error
	friend  Array operator+(int el, const Array& Rar);
	Array operator-();
	Array& operator++();
	Array operator++(int);
	Array& operator--();
	Array operator--(int);
	Array operator+();
	bool operator==(const Array& P);
	bool operator !=(const Array& P);
	bool operator <(const Array& P);
	bool operator >(const Array& P);
	int operator [](int i) const;
	int& operator [](int i);
	friend ostream& operator << (ostream& out, const Array& a);
	friend istream& operator >> (istream& in, Array& a);
	void Sort(bool revers = false);

};
Array::Array()
{
	N = 0;
	array = nullptr;
}
//Array::Array(int n) :N(n), array(new int[n] {0})
Array::Array(int n)
{
	N = n;
	if (N > 0)
		array = new int[n] {0};
	else
		array = nullptr;
}
//Array::Array(const Array& Ar)
//{
// N = Ar.N;
// array = new int[Ar.N];
// for (size_t i = 0; i < N; i++)
//  array[i] = Ar.array[i];
//}
Array::Array(const Array& Ar) :Array(Ar.N)
{
	//copy(Ar.array, Ar.array + N, array); 
	memcpy(array, Ar.array, N * sizeof(*array));
}
Array::Array(Array&& a) noexcept {
	N = a.N;
	array = a.array;
	a.array = nullptr;
	//cout << "MoveArr\n";
}
Array& Array::operator=(Array&& a)  noexcept {
	Clear();
	N = a.N;
	array = a.array;
	a.array = nullptr;
	//cout << "MoveArr=\n";
	return *this;
}
Array::~Array()
{
	//cout << "destroy\n" << endl;
	Clear();
}
int Array::Size() const
{
	return N;
}
int* Array::Data()
{
	return array;
}
const int* Array::Data() const
{
	return array;
}
void Array::Clear()
{
	N = 0;
	delete[] array;
	array = nullptr;
}
void Array::Print()
{
	for (int i = 0; i < N; i++)
		cout << array[i] << "\t";
	cout <<"\n----------------------------------------\n";
}
void Array::SetRnd(int min, int max)
{
	if (min > max)swap(min, max);
	for (int i = 0; i < N; i++)
		array[i] = min + rand() % (max - min + 1);
}
void Array::Input()
{
	for (int i = 0; i < N; i++)
	{
		cout << "array[" << i << "] = ";
		cin >> array[i];
	}
}
void Array::QuickSort(int left, int right) {
	int i = left, j = right - 1;
	int m = array[i + (j - i) / 2];
	while (i <= j) {
		while (array[i] < m)i++;
		while (array[j] > m)j--;
		if (i <= j) {
			swap(array[i], array[j]);
			i++;
			j--;
		}
	}
	if (left < j)QuickSort(left, j + 1);
	if (i < right) QuickSort(i, right);
}
void Array::Quicksort() { QuickSort(0, N); }
void Array::Sort(bool revers) {
	CMP cmp = NULL;
	if (revers)
		cmp = [](int a, int b) { return a > b; };
	else
		cmp = [](int a, int b) { return a < b; };
	for (int i = 0; i < N - 1; ++i)
	{
		int pos = i;
		for (int j = i + 1; j < N; ++j)
			if (cmp(array[j], array[pos]))
				pos = j;
		std::swap(array[i], array[pos]);
	}
}

Array& Array::operator=(const Array& Ar)
{
	//cout << "operator=" << endl;
	if (&Ar != this) {
		Clear();
		N = Ar.N;
		if (N) {
			array = new int[Ar.N];
			memcpy(array, Ar.array, N * sizeof(*array));
		}
		else
			array = nullptr;
	}
	return *this;
}
Array Array::operator+(const Array& RAr) const
{
	Array nar(N + RAr.N);
	memcpy(nar.array, array, N * sizeof(*array));
	memcpy(nar.array + N, RAr.array, RAr.N * sizeof(*(RAr.array)));
	return nar;
}
Array Array::operator+(int el) const
{
	Array nar(N + 1);
	memcpy(nar.array, array, N * sizeof(*array));
	nar.array[N] = el;
	return nar;
}
Array Array::operator-()
{
	Array temp(*this);
	for (size_t i = 0; i < N; i++)
		temp.array[i] *= -1;
	return temp;
}
Array& Array::operator++()
{
	for (size_t i = 0; i < N; ++i)
	{
		++array[i];
	}
	return *this;
}
Array Array::operator++(int)
{
	Array temp(*this);
	++* this;
	return temp;
}
Array& Array::operator--()
{
	for (size_t i = 0; i < N; ++i)
		--array[i];
	return *this;
}
Array Array::operator--(int)
{
	Array temp(*this);
	--* this;
	return temp;
}
Array Array::operator+()
{
	return *this;
}
bool Array::operator==(const Array& P)
{
	if (N != P.N) {
		return false;
	}
	/*else {
	 for (size_t i = 0; i < N; i++)
	  if (array[i] != P.array[i])return false;
	}*/
	/*return true;*/
	return !memcmp(array, P.array, N * sizeof(*array));
}
bool  Array::operator !=(const Array& P)
{
	return !(*this == P);
}
bool  Array::operator <(const Array& P)
{
	if (N < P.N) {
		return true;
	}
	if (N == P.N)
		memcmp(array, P.array, N * sizeof(*array)) < 0 ? true : false;
	return false;
}
bool  Array::operator >(const Array& P)
{
	if (N > P.N) {
		return true;
	}
	if (N == P.N)
		memcmp(array, P.array, N * sizeof(*array)) > 0 ? true : false;
	return false;
}
int  Array::operator [](int i) const {
	if (i >= 0 && i < N)
		return array[i];
	exit(1);
}
int& Array::operator[](int i) {
	if (i >= 0 && i < N)
		return array[i];
	exit(1);
}

//Array operator+(int el, const Array& Rar) { // int + Array
// Array nar(Rar.Size() + 1);
// //nar.Data()[0] = el;
// *nar.Data() = el;
// memcpy(nar.Data()+1, Rar.Data(), Rar.Size() * sizeof(*Rar.Data()));
// return nar;
// //return Rar + el;
//}
Array operator+(int el, const Array& Rar) { // int + Array friend
	Array nar(Rar.N + 1);
	nar.array[0] = el;
	memcpy(nar.array + 1, Rar.array, Rar.N * sizeof(*Rar.array));
	return nar;
}
ostream& operator << (ostream& out, const Array& a) {
	for (size_t i = 0; i < a.N; i++)
		out << a[i] << '\t';
	return out;
}
istream& operator >> (istream& in, Array& a) {
	a.Input();
	return in;
}

Array foo() {
	Array a(10);
	++a;
	return a;
}
int main()
{
	//srand(time(0));
	int f = 10, k = f;
	Array mas1(3);
	//mas1.Print();
	mas1.SetRnd(-5, 5);
	cout << "-------------mas1-------------------\n";
	mas1.Print();
	cout << "-------------mas2-------------------\n";
	//mas.Input();
	Array mas2(100);
	//mas1.Print();
	mas2.SetRnd(-100, 100);
	mas2.Print();
	cout << "--------------mas3------------------\n";
	Array mas3;
	mas3 = mas1 + mas2;
	//mas3 = mas3 + mas3;
	mas3.Print();

	cout << "--------------mas3------------------\n";
	mas3 = mas1 + 30 + 40 + 50 + 60;
	mas3.Print();

	cout << "--------------mas3------------------\n";
	mas3 = 30 + mas1;
	mas3.Print();

	cout << "The end\n";
	mas3 = -mas1;
	mas3.Print();
	mas1.Print();
	mas3 = +mas1;
	mas3.Print();
	mas1.Print();
	mas3 = ++mas1;
	mas1.Print();
	mas3.Print();
	mas3 = mas1++;
	mas1.Print();
	mas3.Print();
	mas3 = --mas1;
	mas1.Print();
	mas3.Print();
	mas1 = mas3++;
	mas1.Print();

	mas3.Print();
	if (mas1 == mas3)cout << "Yes" << endl;
	else cout << "No" << endl;
	if (mas1 != mas3)cout << "Yes" << endl;
	else cout << "No" << endl;
	if (mas1 < mas3)cout << "Yes" << endl;
	else cout << "No" << endl;
	mas1[1] = 10;
	cout << mas1[1] << endl;
	cin >> mas1;
	cout << mas1;
	{
		Array P = foo();
		cout << P;
	}
	{
		Array P(3);
		P = foo();
	}
	cout << "\n";
	Array mas4(10);
	mas4.SetRnd(-100, 100);
	mas4.Print();
	mas4.Sort();
	mas4.Print();
	mas4.Sort(true);
	mas4.Print();
	cout << "\nQuicksort\n";
	mas4.SetRnd(-100, 100);
	mas4.Print();
	mas4.Quicksort();
	mas4.Print();
}