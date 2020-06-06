#include <iostream>
using namespace std;
//COUNT CHAR
size_t Length(const char* str) {
	//piter0
	//str[5] = 10;const char error
	size_t k = 0;
	while (*str++)
		k++;
	return k;
}
//Hello hello   l=4
//size_t CountChar(const char* str,char f=32) { 
size_t CountChar(const char* str,char f=' ') { 
	size_t k = 0;
	/*while (*str) {
		if (*str == f) k++;
		str++;
	}*/
	for (size_t i = 0; i < strlen(str); i++)
		if (str[i] == f) k++;
	return k;
}

void CatSTR(char* dest, const char* source) {
	/* Ivanenko0}}}}}}}}}}}}}}}}}}}
	           Ivan0*/
	size_t lendest = strlen(dest);//8
	for (size_t i = 0; i <=strlen(source); i++) //4
			dest[lendest+i] = source[i];
}

void CopySTR(char* dest, const char* source) {
	for (size_t i = 0; i <= strlen(source); i++) 
		dest[i] = source[i];
}

void Task0()
{
	int d = 10;
	char b = 'W';
	char txt1[100] = "Piter";
	char txt2[5] = { 'H','e','l','l','o' };

	/*for (size_t i = 0; i < 5; i++)
	{
		cout << txt1[i] << '|';
	}*/
	cout << '|' << txt1 << '|' << endl;
	cout << '|' << txt2 << '|' << endl;
	//"Piter";
	txt1[1] = 'e';
	txt1[3] = 'r';
	txt1[4] = 'o';
	cout << '|' << txt1 << '|' << endl;
	txt1[5] = ' ';
	txt1[6] = '1';
	cout << '|' << txt1 << '|' << endl;
	char txt3[10];
	txt3[0] = 'e';
	txt3[1] = 'r';
	txt3[2] = 'o';
	txt3[4] = 0;// '\0';
	cout << '|' << txt3 << '|' << endl;
	cin >> txt3;//Pet
	cout << '|' << txt3 << '|' << endl;
	cin.get();// \n
	cin.getline(txt3, 10);//  
	cout << "||" << txt3 << "||" << endl;

}
void Task1() {

	char buf[100]{ 0 };
	cout << "Enter string =";
	cin.getline(buf, 100);

	cout << "length =" << Length(buf) << endl;
	cout << "length =" << Length("Piter") << endl;
	//	cout << "length =" << Length(NULL) << endl;

	cout << "length =" << strlen(buf) << endl;
	cout << "length =" << strlen("Piter") << endl;
	//	cout << "length =" << strlen(NULL) << endl;
}
void Task2() {
	char buf[100]{ 0 };
	cout << "Enter string =";
	cin.getline(buf, 100);
	cout << "Enter char =";
	char c;
	cin>>c;
	cout << "count =" << CountChar(buf,c) << endl;
	cout << "count space=" << CountChar(buf) << endl;
}
void Task3() {

	char lname[100] = "Ivanenko";
	char fname[] = "Ivan";

	CatSTR(lname," ");
	CatSTR(lname,fname);

	cout << lname;
	//Ivanenko
	//Ivan
	// 
	//IvanenkoIvan 
}
void Task4() {

	char lname[] = "Ivanenko";
	char fname[] = "Ivan";

	char PIB[100]="Petrenko";

	/*CopySTR(PIB, lname);
	CatSTR(PIB, " ");
	CatSTR(PIB, fname);*/

	strcpy(PIB, lname);
	strcat(PIB, " ");
	strcat(PIB, fname);

	cout << PIB<<endl;	//Ivanenko Ivan 
	 
	//PIB[10] = "Stepan"; error
	CopySTR(PIB,"Stepan");
	cout << PIB;

}

int main()
{
	//Task1();
	//Task2();
	//Task3();
	Task4();


}