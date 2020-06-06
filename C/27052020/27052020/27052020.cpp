#include <iostream>

using namespace std;

char textmenu[20];

void menu()
{
    // cout << "Menu"<<endl;
    // cout << "Меню"<<endl;
    cout << textmenu << endl;
}
int  loadlang()
{
    
    
    return 0;
}
void  deflang()
{
    strcmp(textmenu, "Menu");
   
}
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

bool Name(employees e1, employees e2) {
    return strcoll(e1.name ,e2.name)<0;
}
bool Standing(employees e1, employees e2) {
    return e1.standing > e2.standing;
}
bool Age(employees e1, employees e2) {
    return e1.age > e2.age;
}
typedef bool (*CMPemp)(employees, employees);

//void Sort(employees* gr, size_t n, bool (*funkcmp)(employees, employees)) {
void Sort(employees* gr, size_t n, CMPemp funkcmp) {
    bool f;
    int j = 0;
    do
    {
        f = false;
        for (size_t i = 0; i < n - 1 - j; i++)
            if (funkcmp(gr[i],gr[i+1])) {
                swap(gr[i], gr[i + 1]);
                f = true;
            }
        j++;
    } while (f);
}
int main()
{
    employees* gr = new  employees[5];
    Sort(gr, 5, Age);
    Sort(gr, 5, Standing);
    Sort(gr, 5, Name);

    CMPemp massort[]{ Age ,Standing,Name };
    Sort(gr, 5, massort[2]);




    if (loadlang())
    {
        deflang();
    }

   // cout << "Меню"<<endl;
    cout << textmenu << endl;
}


//SFML