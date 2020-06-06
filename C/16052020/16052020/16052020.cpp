#include <iostream>
using namespace std;

void Save() {
	FILE* fs = NULL;
	//r - read    w - write    r+  rb wb rt wt w+t w+b
	//a - add tail b - binary t - text 	//fs = fopen("1.txt", "w");
	int error = fopen_s(&fs, "1.txt", "w");
	if (error) {
		//if ( fs == NULL) {
		cout << "I can not create the file";
		return;
		exit(error);
	}
	putc('A', fs);
	fputc('B', fs);
	char name[] = "\nHello\n";
	fputs(name, fs);
	int a = 123456;
	fprintf(fs, "%d\n", a);
	double d = -123.456;
	fprintf(fs, "%10.2lf\n", d);
	fclose(fs);
}
double func(double x) {
	return cos(x) - sin(x);
}
void FuncToSave(const char* file, double a, double b, double step) {
	FILE* fs = NULL;
	int error = fopen_s(&fs, file, "a");
	if (error) {
		cout << "I can not create the file"; exit(error);
	}
	fputs("|------------------------------------------------|\n", fs);
	fputs("|          x          |             y            |\n", fs);
	fputs("|------------------------------------------------|\n", fs);
	for (; a <= b; a += step)
		fprintf(fs, "|%21.2lf|%26.3lf|\n", a, func(a));
	fputs("|------------------------------------------------|\n", fs);
	fclose(fs);
}

void ShowFile(const char* file) {
	FILE* fs = NULL;
	int error = fopen_s(&fs, file, "r");
	if (error) {
		cout << "I can not read the file";
		exit(error);
	}
	/*while(!feof(fs))
	{
		char ch = getc(fs);
		cout << ch;
	}*/
	char buf[100]{ 0 };
	do {
		cout << buf;
		fgets(buf, 100, fs);
	} while (!feof(fs));
	fclose(fs);
}
void SaveConfig(double a, double b, double step) {
	FILE* fs = NULL;
	int error = fopen_s(&fs, "config.txt", "w");
	if (error) {
		cout << "I can not create the file"; exit(error);
	}
	fprintf(fs, "%lf ", a);
	fprintf(fs, "%lf ", b);
	fprintf(fs, "%lf", step);	
	fclose(fs);
}
void LoadConfig(double& a, double& b, double &step) {
	FILE* fs = NULL;
	int error = fopen_s(&fs, "config.txt", "r");
	if (error) {
		cout << "I can not create the file"; exit(error);
	}
	fscanf(fs, "%lf ", &a);
	fscanf(fs, "%lf ", &b);
	fscanf(fs, "%lf", &step);
	fclose(fs);
}


int main()
{
	//y=cos(x)-sin(x)  -5  5 крок=0.5
	//		x	|	y		|
//	|	-5		|	0.3652	|
//	|	-4.5	|	0.313	|

//	|	5		| 0.5		|	

	//Save();

	SaveConfig(-3, 2, 0.5);
	double a=0, b=0, c=0;
	LoadConfig(a, b, c);
	FuncToSave("func.txt", a, b, c);

	ShowFile("func.txt");
	//ShowFile("16052020.cpp");
	//for
}
