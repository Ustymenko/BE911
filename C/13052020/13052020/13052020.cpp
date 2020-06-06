#include <string.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>
//#include "MyLibr.h"  ???????
using namespace std;


int main() {
	setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char group[][50]={
		"Аня",
		"Петро",
		"Іван",
		"Іра",
		"Ярослав"
	};
	int size = 5;
	for (size_t i = 0; i < size; i++)
			cout << group[i] << endl;
	cout << "------------------------------------"<< endl;
	bool fl;
	int k = 0;
	do {
		fl = false;
		for (size_t i = 0; i < size-k-1; i++)
		{
			if (strcoll(group[i],group[i + 1])>0) {
				swap(group[i], group[i + 1]);
				fl = true;
			}
		}
		k++;
	} while (fl);

	for (size_t i = 0; i < size; i++)
		cout << group[i] << endl;
	cout << "------------------------------------" << endl;


}

