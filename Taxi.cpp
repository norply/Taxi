#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    setlocale(LC_CTYPE, "rus");
    float n = 0;// число сотрудников, машин.
    int i = 0;// счётчик
    int i1 = 0;// счётчик
    for (;;)// проверка ввода числа машин, сотрудников
    {
        cout << "Введите число сотрудников, которых необходимо отвезти на такси (не меньше 1, не больше 1000): ";
        cin >> n;
        if (!cin)
        {
            cout << "Вы ввели не число"<<endl;
        }
        else
        { 
        if (n < 1)
        {
            cout << "Вы ввели число меньше 1"<<endl;
        }
        else
        {
            if (n > 1000)
            {
                cout << "Вы ввели число больше 1000"<<endl;
            }
            else
            {
                if (short(n) != n)
                    cout << "Вы ввели нецелое число"<<endl;
                else
                {
                    break;
                }
            }
        }
        }
        cin.clear();
        cin.ignore(1000, '\n');
    }
}
