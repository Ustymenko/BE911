#include <iostream>
#include <Windows.h>

using namespace std;
void show(char m[][50],int n) {
    cout <<"-------------------------------------------"<< endl;
    for (size_t i = 0; i < n; i++)
    {
        cout << m[i] << endl;
    }

}


int main()
{
  /*  system("cp 1251");*/
  
    setlocale(LC_ALL, "ukr");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //SetConsoleOutputCP(1251);
    char stud[][50] = {
        "Анна",
        "Іван","Ярослав","Ігор", "Ваня" };
    show(stud, 5);
    int size = 5;
    // Сортировка массива пузырьком
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcoll(stud[j] , stud[j + 1])>0) {
                // меняем элементы местами
                swap(stud[j],stud[j+1]);
            }
        }
    }
    show(stud, 5);



}
