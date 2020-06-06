#include <iostream>
#include <string.h> //char*
using namespace std;
// strlen 
// strcpy 
// strncpy 
// strcat 
// strncat 
// strchr
// strstr
// strcmp
// strtok


char* PIBskor(const char* PIB) {
	char* PIBlit = new char[strlen(PIB)]{ 0 };
	size_t i = 0;
	size_t st = 0;
	while (PIB[i] == ' ') i++;
	st = i;
	i = (strchr(PIB + st, ' ') - PIB);
	strncpy(PIBlit, PIB + st, i - st + 1);
	while (PIB[i] == ' ') i++;
	strncat(PIBlit, PIB + i, 1);
	strcat(PIBlit, ".");
	i = (strchr(PIB + i, ' ') - PIB);
	while (PIB[i] == ' ') i++;
	strncat(PIBlit, PIB + i, 1);
	strcat(PIBlit, ".");
	return PIBlit;
}

int* FoundAllChar(const char* PIB, char ch, int& count) {
	count = 0;
	size_t length = strlen(PIB);
	for (size_t i = 0; i < length; i++)
		if (ch == PIB[i]) count++;
	int* rez = nullptr;
	if (count > 0) {
		int i = 0;
		rez = new int[count] {0};
		const char* find=strchr(PIB, ch);
		while (find) {
			rez[i++]= find - PIB;
			find = strchr(find +1, ch);
		}
	}
	return rez;
}


void Task1()
{
	char name[100] = "Piter";
	cout << name << endl;
	const char* iv = "Ivan";
	// name = "Ivans";
	strcpy(name, "\"Ivan\"");
	cout << name << endl;
	char pib[100] = "garbage ";
	// "Petrenko" "Petro"
	strcpy(pib, "Petrenko");
	strcat(pib, " ");
	strcat(pib, "Petro");
	cout << pib << endl;
	cout << strlen("Petrenko Ivan Stepanovych") << endl;

	char PIB[] = "Petrenko Ivan Stepanovych";//


	char* pp = PIBskor(PIB);

	cout << pp << endl;//Petrenko I.S.

	delete[] pp;


	cout << PIBskor("Petrenko Ivan Stepanovych") << endl;//Petrenko I.S.

	cout << strchr(PIB, 't') << endl;
	cout << (strchr(PIB, 't') - PIB) << endl;

	//"Petrenko Ivan Stepanovych"
	//t=2
	//t=15

	strcpy(PIB, "Petrenko Ivan Stepanovych");
	int size = 20;
	int* tt = FoundAllChar(PIB, 'w', size);

	for (size_t i = 0; i < size; i++)
		cout << "->" << tt[i] << endl;


}
void Sort(const char**mas, int n) {
	bool f;
	int j = 0;
	do
	{
		f = false;
		for (size_t i = 0; i < n - 1 - j; i++)
			if (strcmp(mas[i], mas[i + 1]) > 0) {
				swap(mas[i], mas[i + 1]);
				f = true;
			}
		j++;
	} while (f);
}

void Task2()
{
	char name1[] = "Petro";
	char name2[] = "Pitro2";
	// error
	//if (name1 > name2)
	//	cout << name1 << ">" << name2 << endl;
	//else
	//	cout << name1 << "<=" << name2 << endl;
	//name1<name2 ->   <0  -1
	//name1>name2 ->   >0   1
	//name1==name2 ->  =0   0

	if (strcmp(name1, name2) < 0)
		cout << name1 << "<" << name2 << endl;
	else
		if (strcmp(name1, name2) > 0)
			cout << name1 << ">" << name2 << endl;
		else
			cout << name1 << "==" << name2 << endl;

	const char* stud[]{
		"Ivan", //const char*
		"Stepan",//const char*
		"Anna",//const char*
		"Taras"//const char*
	};
	Sort(stud, 4);
	for (size_t i = 0; i < 4; i++)
	{
		cout << stud[i] << endl;
	}

}

void Task3()
{
	char name[100] = "Petranko Ivan Stepanovych";
	//"an"

	char * find=strstr(name, "an");
	while (find) {
		cout <<"->"<< find - name<<endl;
		find = strstr(find +1, "an");
	}

}
void Task4()
{
	char name[100] = "Hello, Petranko Ivan Stepanovych? Hi";
	//"an"

	char* find = strtok(name, " ,.?!");
	while (find) {
		cout << "->" << find<< endl;
		find = strtok(NULL, " ,.?!");
	}

}


int main(){

	//Task1();
	//Task2();
	//Task3();
	Task4();

	return 0;
}
