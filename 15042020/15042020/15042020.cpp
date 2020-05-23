#include <iostream>
#include <Windows.h>
#include <ctime>
#include <algorithm>
using namespace std;
void Print(int* m, int n) {
	for (size_t i = 0; i < n; i++)
	{
		cout << *(m++) << '\t';
	}
	cout << endl;
}
int** createArr2D(int rows, int cols) {
	int** mas = new int* [rows];
	for (size_t r = 0; r < rows; r++)
		mas[r] = new int[cols] {0};
	return mas;
}
char** createArr2Dchar(int rows, int cols) {
	char** mas = new char* [rows];
	for (size_t r = 0; r < rows; r++)
		mas[r] = new char[cols] {0};
	return mas;
}

void Print(int** mas2d,int ryadkiv, int stovpciv) {
	for (size_t r = 0; r < ryadkiv; r++)
	{
		for (size_t c = 0; c < stovpciv; c++)
			//cout << mas2d[r][c] << "\t";
			cout << *(*(mas2d+r)+c) << "\t";
		cout << endl;
	}
	cout <<"-----------------------------"<< endl;
}
void Print(char** mas2d, int ryadkiv, int stovpciv) {
	for (size_t r = 0; r < ryadkiv; r++)
	{
		for (size_t c = 0; c < stovpciv; c++)
			cout << mas2d[r][c] << "\t";
			//cout << *(*(mas2d + r) + c) << "\t";
		cout << endl;
	}
	cout << "-----------------------------" << endl;
}
void Set(int** mas2d, int ryadkiv, int stovpciv) {
	for (size_t r = 0; r < ryadkiv; r++)
		for (size_t c = 0; c < stovpciv; c++)
			mas2d[r][c] =-100+ rand()%201;
}
void Set(char** mas2d, int ryadkiv, int stovpciv) {
	for (size_t r = 0; r < ryadkiv; r++)
		for (size_t c = 0; c < stovpciv; c++)
			mas2d[r][c] = 96 + rand() % 28;
}

void deleteArr2D(int** mas ,int rows){
	for (size_t r = 0; r < rows; r++)
		delete[]  mas[r];
	delete[]  mas;
}
//1 max
int Max(int** mas2d, int ryadkiv, int stovpciv) {
	int max= mas2d[0][0];
	for (size_t r = 0; r < ryadkiv; r++)
		for (size_t c = 0; c < stovpciv; c++)
			if (mas2d[r][c]>max) max= mas2d[r][c];
	return max;
}

//2 sum
int Sum(int** mas2d, int ryadkiv, int stovpciv) {
	int sum =0;
	for (size_t r = 0; r < ryadkiv; r++)
		for (size_t c = 0; c < stovpciv; c++)
			sum+=mas2d[r][c];
	return sum;
}
//3 кількість елементів <0
size_t CountNeg(int** mas2d, int ryadkiv, int stovpciv) {
	size_t count = 0;
	for (size_t r = 0; r < ryadkiv; r++)
		for (size_t c = 0; c < stovpciv; c++)
			if (mas2d[r][c] < 0) count++;
	return count;
}
void addrow(int**& arr, int& row, int col) {
	int** nmas = createArr2D(row+1,col);
	for (size_t r = 0; r < row; r++)
		for (size_t c = 0; c < col; c++)
			nmas[r+1][c] = arr[r][c];
	deleteArr2D(arr, row);
	arr = nmas;
	row++;
}
void addrow2(int**& arr, int& row, int col) {
	int** nmas = new int* [row + 1];
	for (size_t r = 0; r < row; r++)
		nmas[r] = arr[r];
	nmas[row] = new int[col] {0};
	delete[] arr;
	arr = nmas;
	row++;
}
void Sort(int* arr, int n) {
	bool f = false;
	int k = 0;
	 do {
		 f = false;
		 for (size_t i = 0; i < n-k-1; i++)
		 {
			 if (arr[i] > arr[i + 1]) {
				 swap(arr[i], arr[i + 1]);
				 f = true;
			 }
		 }
		 k++;
	 } while (f);
}
void SortRow(int** arr, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		Sort(arr[i],c);
	}
}
void SortRow2(int** arr, int r, int c)
{
	for (int i = 0; i < r; i++)
		sort(arr[i], arr[i] + c);
}
int main()
{
	int rows, cols;
	cout << "rows="; cin >> rows;
	cout << "cols="; cin >> cols;
	int** arr = createArr2D(rows, cols);
	Set(arr, rows, cols);
	Print(arr, rows, cols);
	//SortRow(arr, rows, cols);
	SortRow2(arr, rows, cols);
	Print(arr, rows, cols);

	//addrow(arr, rows, cols);
	//Print(arr, rows, cols);

	/*addrow2(arr, rows, cols);
	Print(arr, rows, cols);*/

	deleteArr2D(arr, rows);

	/*char** arrc = createArr2Dchar(rows, cols);
	Set(arrc, rows, cols);
	Print(arrc, rows, cols);*/
	int aaa[]{ 5,3,6,9,5,94,-264,565,54,-544 };
	Sort(aaa, sizeof(aaa) / sizeof(aaa[0]));
	for (size_t i = 0; i < sizeof(aaa) / sizeof(aaa[0]); i++)
	{
		cout << aaa[i] << "\t";
	}

}