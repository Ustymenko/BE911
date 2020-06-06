#include <iostream>
using namespace std;

struct Student {
	char Name[100];
	int Age = 15;
	char sex;
	int Age2;
	double Avg;
	char s[3];
	// int Age2;
	// int Age3;
};

short d[3];
struct Date {
	unsigned short day : 5;
	unsigned short month : 4;
	unsigned short year : 12;
};
union MyUnion
{
	int a;
	double b;
	unsigned char name[8];
};
void Test1()
{
	//cout << "size="<<sizeof(Date)<<endl;
	//Student st{0};
	//cout << "size="<<sizeof(Student)<<endl;

	//MyUnion my;
	//cout << "size="<<sizeof(MyUnion)<<endl;
	//my.a = 123;
	//cout << "my.a=" << my.a << endl;
	//my.b = 789.333;
	//cout << "my.b=" << my.b << endl;

	//strcpy_s((char*)my.name,8,"PitePen" );
	//cout << "my.name=" << my.name << endl;
	//
	//MyUnion un{ 0 };
	//un.b =- 1.0;
	//for (size_t i = 0; i < 8; i++)
	//{
	//    cout <<i<< "=" << (size_t)un.name[i] << endl;
	//}


	Date Bday{ 15,5,2020 };
	cout << Bday.day << "." << Bday.month / 10 << Bday.month % 10 << "." << Bday.year << "." << endl;

	// cin>> Bday.day; error
	unsigned short buf;
	cin >> buf;
	Bday.day = buf;

	cout << Bday.day << "." << Bday.month / 10 << Bday.month % 10 << "." << Bday.year << "." << endl;

}

void DtoB(unsigned int d) {
	if (d < 1) return;
	DtoB(d / 2);
	cout << d % 2;
}
void Test2() {

	int a = 10;
	int b = 3;
	/*  DtoB(a);
	  cout <<endl;
	  DtoB(b);*/
	cout << "---------------<<-------------" << endl;
	{ //<<  *2
		DtoB(a);
		cout << endl;
		DtoB(a << 1);
		cout << endl;
		DtoB(20);
		cout << endl;
	}
	cout << "--------------->>-------------" << endl;
	{//>> /2
		DtoB(a >> 1);
		cout << endl;
		DtoB(5);
		cout << endl;
	}
	cout << "---------------|---------------" << endl;
	{// | 
		a = 10;
		b = 7;
		DtoB(a);
		cout << endl;
		DtoB(b);
		cout << endl;
		int k = a | b;
		cout << k << endl;
		DtoB(k);
		cout << endl;
	}
	cout << "---------------&---------------" << endl;
	{// & 
		a = 10;
		b = 7;
		DtoB(a);
		cout << endl;
		DtoB(b);
		cout << endl;
		int k = a & b;
		cout << k << endl;
		DtoB(k);
		cout << endl;
	}
	cout << "---------------^---------------" << endl;
	{// ^
		a = 10;
		b = 7;
		DtoB(a);
		cout << endl;
		DtoB(b);
		cout << endl;
		int k = a ^ b;
		cout << k << endl;
		DtoB(k);
		cout << endl;
	}

	cout << "-------------- ~ --------------" << endl;
	{// ~
		a = 10;
		DtoB(b);
		cout << endl;
		int k = ~ b;
		cout << k << endl;
		DtoB(k);
		cout << endl;
	}
	{
		a = 110;
		if (a & 1)
			cout << "Neparne";
		else
			cout << "parne";
	}
	{
		unsigned short dd=0; //1010 0111
		a = 10; //1010
		b = 7;  //0111
		dd = a; // 0000 1010
		dd=dd << 4;   //1010 0000
					  //0000 0111
		dd = dd | b;  //1010 0111
		cout << dd << endl;
		DtoB(dd);
		cout << endl;
	}


}

int main()
{
	//Test1();
	Test2();

}