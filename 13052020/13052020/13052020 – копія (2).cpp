#include <string.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include <algorithm>
//#include "MyLibr.h"  ???????
using namespace std;
#define MENUTOP 4
#define MENULEFT 20
#define BACKGROUND 1
#define FOREGROUND 15
#define SELECTITEM 4


struct employees {
	//string name = "Мельник Олександр";
	char name[50] = "Мельник Олександр";
	int age = 35;
	int idnumb = 123456;
	char paspnumb[10] = "BH1234";
	int standing = 3;
	char addres[100] = "Лесі Українки 47";
	int postindex = 10234;
	int complproject = 18;
	double salary = 59000.0;
};

void gotorc(short r, short c) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, { c,r });
}
void Color(unsigned short Back, unsigned short Forg) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	unsigned short c = ((Back & 0x0F) << 4) + (Forg & 0x0F);
	SetConsoleTextAttribute(handle, c);
}
void paintmenu(const char** s, int sizem, int  pm) {
	system("cls");
	gotorc(MENUTOP, MENULEFT);
	Color(BACKGROUND, FOREGROUND);
	cout << "------Menu-------\n";
	for (size_t i = 0; i < sizem; i++)
	{
		gotorc(MENUTOP + i + 1, MENULEFT);
		cout << (i == pm ? Color(BACKGROUND, SELECTITEM), "=>" : "  ");
		cout << s[i] << endl;
		Color(BACKGROUND, FOREGROUND);
	}
}
void paintmenu(employees* s, int sizem, int  pm) {
	system("cls");
	gotorc(MENUTOP, MENULEFT);
	Color(BACKGROUND, FOREGROUND);
	cout << "------Menu-------\n";
	for (size_t i = 0; i < sizem; i++)
	{
		gotorc(MENUTOP + i + 1, MENULEFT);
		cout << (i == pm ? Color(BACKGROUND, SELECTITEM), "=>" : "  ");
		cout << s[i].name << endl;
		Color(BACKGROUND, FOREGROUND);
	}
}
int menu(const char** s, int sizem, int  pm = 0) {
	char c = 80;
	while (true)
	{
		if (c == 72 || c == 80) paintmenu(s, sizem, pm);
		c = _getch();
		switch (c)
		{
		case 27: //esc
			return -1;
		case 80: //down
			pm++;
			if (pm == sizem) pm = 0;
			break;
		case 72: //up
			if (pm == 0) pm = sizem;
			pm--;
			break;
		case 13: //enter
			return pm;
		}
	}
}
//int menu(employees* s, int sizem, int  pm = 0) {
//	char c = 80;
//	while (true)
//	{
//		if (c == 72 || c == 80) paintmenu(s, sizem, pm);
//		c = _getch();////???????????????
//		switch (c)
//		{
//		case 27: //esc
//			return -1;
//		case 80: //down
//			pm++;
//			if (pm == sizem) pm = 0;
//			break;
//		case 72: //up
//			if (pm == 0) pm = sizem;
//			pm--;
//			break;
//		case 13: //enter
//			return pm;
//		}
//	}
//}
void FillEmploye(employees& chel) {
	printf_s("Ent.Name \t\t");
	cin.getline(chel.name, 50);
	//cin >> chel.name;
	printf_s("Ent.Age\t\t\t");
	scanf_s("%d", &chel.age);
	printf_s("Ent.idnumb\t\t");
	scanf_s("%d", &chel.idnumb);
	printf_s("Ent.PaspNumber\t\t");
	scanf_s("%s", &chel.paspnumb, 10);
	printf_s("Ent.Standing\t\t");
	scanf_s("%d", &chel.standing);
	printf_s("Ent.addres\t\t");
	scanf_s("%s", &chel.addres, 100);
	printf_s("Ent.Post.index\t\t");
	scanf_s("%d", &chel.postindex);
	printf_s("Ent.Completed projects\t");
	scanf_s("%d", &chel.complproject);
	printf_s("Ent.Salary\t\t");
	scanf_s("%lf", &chel.salary);
	getchar();
}

void AddEmployees(employees*& Date, size_t &n) {

	//[][][] 
	employees* newarr = new employees[n + 1];
	memcpy(newarr, Date, sizeof(employees) * n);
	//for (size_t i = 0; i < n; i++)
	//	newarr[i] = Date[i];
	//[][][][new]
	FillEmploye(newarr[n]);
	delete[] Date;
	Date = newarr;
	n++;
	
}
void Head() {
	cout << "|Name                |Age   |ID Number  |Pas.Number |Stand |Addres               |Post Index |Compl.Proj |Salar      |\n";
	cout << "----------------------------------------------------------------------------------------------------------------------\n";
}
void Print(employees* Date, int n) {
	printf_s("|%-20s|%5d |%10d |%10s |%5d |%-20s |%10d |%10d |%10.2lf |",
		Date[n].name, Date[n].age, Date[n].idnumb,
		Date[n].paspnumb, Date[n].standing, Date[n].addres,
		Date[n].postindex, Date[n].complproject, Date[n].salary);
	cout << endl;
}
void PrintAll(employees* Date, int n) {
	for (size_t i = 0; i < n; i++)
		Print(Date, i);
}
void SortName(employees* gr, int n) {
	bool f;
	int j = 0;
	do
	{
		f = false;
		for (size_t i = 0; i < n - 1 - j; i++)
			if (strcmp(gr[i].name, gr[i + 1].name) > 0)
				//if ((gr[i].name > gr[i + 1].name))
			{
				swap(gr[i], gr[i + 1]);
				f = true;
			}
		j++;
	} while (f);
}
void SortAge(employees* gr, int n) {
	bool f;
	int j = 0;
	do
	{
		f = false;
		for (size_t i = 0; i < n - 1 - j; i++)
			if (gr[i].age > gr[i + 1].age) {
				swap(gr[i], gr[i + 1]);
				f = true;
			}
		j++;
	} while (f);
}
void SortStanding(employees* gr, int n) {
	bool f;
	int j = 0;
	do
	{
		f = false;
		for (size_t i = 0; i < n - 1 - j; i++)
			if (gr[i].standing > gr[i + 1].standing) {
				swap(gr[i], gr[i + 1]);
				f = true;
			}
		j++;
	} while (f);
}
void EditAll(employees*& Date, int n) {
	system("cls");
	cout << "Edit file" << endl << endl;
	cout << "Old name\t\t";
	cout << Date[n].name << '\t';
	printf_s("Ent.New Name \t\t");
	scanf_s("%s", &Date[n].name, 50);
	cout << "Old age\t\t";
	cout << Date[n].age << "\t\t\t";
	printf_s("Ent.New Age\t\t");
	scanf_s("%d", &Date[n].age);
	cout << "Old IDnumber\t";
	cout << Date[n].idnumb << "\t\t\t";
	printf_s("Ent.New idnumb\t\t");
	scanf_s("%d", &Date[n].idnumb);
	cout << "Old Paspnumber\t";
	cout << Date[n].paspnumb << "\t\t\t";
	printf_s("Ent.New PaspNumber\t");
	scanf_s("%s", &Date[n].paspnumb, 10);
	cout << "Old standing\t";
	cout << Date[n].standing << "\t\t\t";
	printf_s("Ent.New Standing\t");
	scanf_s("%d", &Date[n].standing);
	cout << "Old addres\t";
	cout << Date[n].addres << '\t';
	printf_s("Ent.New addres\t\t");
	scanf_s("%s", &Date[n].addres, 100);
	cout << "Old postindex\t";
	cout << Date[n].postindex << "\t\t\t";
	printf_s("Ent.New Post.index\t");
	scanf_s("%d", &Date[n].postindex);
	cout << "Old Compl.Proj.\t";
	cout << Date[n].complproject << "\t\t\t";
	printf_s("Ent.New Completed proj.\t");
	scanf_s("%d", &Date[n].complproject);
	cout << "Old Salary\t";
	cout << Date[n].salary << "\t\t\t";
	printf_s("Ent.New Salary\t\t");
	scanf_s("%lf", &Date[n].salary);
}
void Edit(employees*& Date, int n) {
	const char* Edit_menu[]{
		"Name",
		"Age",
		"ID Number",
		"Pasp.Numb",
		"Standing",
		"Addres",
		"Post Index",
		"Complate project",
		"Salary"
	};
	int SizeEdit = sizeof(Edit_menu) / 4;
	int i = 0;
	bool bo = true;

	while (bo) {
		i = menu(Edit_menu, SizeEdit);
		system("cls");

		switch (i)
		{
		case -1: bo = false;
			break;
		case 0:
			cout << "Old name\t\t";
			cout << Date[n].name << '\t';
			printf_s("Ent.New Name \t\t");
			scanf_s("%s", &Date[n].name, 50);
			break;
		case 1:
			cout << "Old age\t\t";
			cout << Date[n].age << "\t\t\t";
			printf_s("Ent.New Age\t\t");
			scanf_s("%d", &Date[n].age);
			break;
		case 2:
			cout << "Old IDnumber\t";
			cout << Date[n].idnumb << "\t\t\t";
			printf_s("Ent.New idnumb\t\t");
			scanf_s("%d", &Date[n].idnumb);
			break;
		case 3:
			cout << "Old Paspnumber\t";
			cout << Date[n].paspnumb << "\t\t\t";
			printf_s("Ent.New PaspNumber\t");
			scanf_s("%s", &Date[n].paspnumb, 10);
			break;
		case 4:
			cout << "Old standing\t";
			cout << Date[n].standing << "\t\t\t";
			printf_s("Ent.New Standing\t");
			scanf_s("%d", &Date[n].standing);
			break;
		case 5:
			cout << "Old addres\t";
			cout << Date[n].addres << '\t';
			printf_s("Ent.New addres\t\t");
			scanf_s("%s", &Date[n].addres, 100);
			break;
		case 6:
			cout << "Old postindex\t";
			cout << Date[n].postindex << "\t\t\t";
			printf_s("Ent.New Post.index\t");
			scanf_s("%d", &Date[n].postindex);
			break;
		case 7:
			cout << "Old Compl.Proj.\t";
			cout << Date[n].complproject << "\t\t\t";
			printf_s("Ent.New Completed proj.\t");
			scanf_s("%d", &Date[n].complproject);
			break;
		case 8:
			cout << "Old Salary\t";
			cout << Date[n].salary << "\t\t\t";
			printf_s("Ent.New Salary\t\t");
			scanf_s("%lf", &Date[n].salary);
			break;
		}
	}

}

const char** ToString(employees* Date,int n) {
	const char** list = new const char* [n] {0};
	for (size_t i = 0; i < n; i++)
	{
		//list[i] = Date[i].name;
		char buf[200]{ 0 };
		sprintf(buf,"|%-25s |%5d|", Date[i].name, Date[i].age);
		list[i] = strdup(buf);
	}
	return list;
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	size_t n = 1;
	employees* Arr = new employees[n];
	Color(BACKGROUND, FOREGROUND);
	system("cls");
	const char* Main_menu[]{
		"Add employee",
		"Print All",
		"Sort by",
		"Employee",
		"Edit",
		"Search"
	};
	const char* Sort_menu[]{
		"Sort by name",
		"Sort by age",
		"Sort by Standing"
	};
	int SizeMain = sizeof(Main_menu) / 4;
	int SizeSort = sizeof(Sort_menu) / 4;

	bool bo = true;
	while (true)
	{
		int pm = 0;
		pm = menu(Main_menu, SizeMain, pm);
		system("cls");
		switch (pm)
		{
		case -1: return 0;
		case 0:
			AddEmployees(Arr, n);
			/*if (SizeArr == n)
				employees* Arr = new employees[SizeArr+=10];*/ //????????????
			break;
		case 1:               //Print All
			Head();
			PrintAll(Arr, n);
			cout << endl;
			break;
		case 2:                ////////////    Sort by.......
			bo = true; pm = 0;
			pm = menu(Sort_menu, SizeSort, pm);
			system("cls");
			{
				switch (pm)
				{
				case -1:
					bo = false; break;
				case 0:
					cout << "Sort by name\n";
					SortName(Arr, n);
					Head();
					PrintAll(Arr, n);
					break;
				case 1:
					cout << "Sort by age\n";
					SortAge(Arr, n);
					Head();
					PrintAll(Arr, n);
					break;
				case 2:
					cout << "Sort by standing\n";
					SortStanding(Arr, n);
					Head();
					PrintAll(Arr, n);
					break;
				}
				Color(BACKGROUND, 2);
				cout << "done\n";
				_getch();
			}
			break;
		case 3:
			cout << "Employee\n";
			break;
		case 4: // EDIT
		{
			pm = 0;
			//pm = menu(Arr, n, pm);
			const char** list = ToString(Arr, n);
			pm = menu(list, n, pm);
			Edit(Arr, pm);
			delete[] list;
			system("cls");
		}
			break;
		case 5:// Search
			pm = 0;
			//pm = menu(Arr, n, pm);
			system("cls");
			Head();
			Print(Arr, pm);
			break;
		}
		Color(BACKGROUND, 2);
		cout << "done\n";
		_getch();
	}
	delete[] Arr;
}

