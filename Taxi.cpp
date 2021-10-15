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
    int w;// пременная для замены
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

int* taxi = new int[n];// номера машин
    int* employee = new int[n];// номера сотрудников
    float* tarif = new float [n];// тарифы
    float* dist = new float[n];// расстояние
    
        for (i = 0; i < n; i++)
        {
            for (;;)// проверка ввода расстояния 
            {
                cout << "Введите в километрах расстояние (целое число, не меньше 1, не больше 1000) от работы до дома для сотрудника номер " << i + 1 << ": ";
                cin >> dist[i];
                if (!cin)
                {
                    cout << "Вы ввели не число"<<endl;
                }
                else
                {
                    if (dist[i] < 1)
                    {
                        cout << "Вы ввели число меньше 1"<<endl;
                    }
                    else
                    {
                        if (dist[i] > 1000)
                        {
                            cout << "Вы ввели число больше 1000"<<endl;
                        }
                        else
                        {
                            if (short(dist[i]) != dist[i])
                                cout << "Вы ввели нецелое число"<<endl;
                            else
                            {
                                employee[i] = i + 1;
                                break;
                            }
                        }
                    }
                }
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }
        
for (i = 0; i < n; i++)
    {
        for (;;)// проверка ввода тарифов
        {
            cout << "Введите тариф (целое число, не меньше 1, не больше 10000) за проезд 1 километра в такси номер " << i + 1 << ": ";
            cin >> tarif[i];
            if (!cin)
            {
                cout << "Вы ввели не число" << endl;
            }
            else
            {
                if (tarif[i] < 1)
                {
                    cout << "Вы ввели число меньше 1" << endl;
                }
                else
                {
                    if (tarif[i] > 1000)
                    {
                        cout << "Вы ввели число больше 1000" << endl;
                    }
                    else
                    {
                        if (short(tarif[i]) != tarif[i])
                            cout << "Вы ввели нецелое число" << endl;
                        else
                        {
                            taxi[i] = i + 1;
                            break;
                        }
                    }
                }
            }
            cin.clear();
            cin.ignore(1000, '\n');
        }

    }
for(i = 0; i < n; i++)// сортирует тарифы от меньшего к большему
    {
        for (i1 = 0; i1 < n; i1++)
        {
            if (tarif[i] < tarif[i1] && (i > i1))
            {
                w = tarif[i];
                tarif[i] = tarif[i1];
                tarif[i1] = w;
                
                w = taxi[i];
                taxi[i] = taxi[i1];
                taxi[i1] = w;
            }
        }

    }
for (i = 0; i < n; i++)// сортирует расстояния от большего к меньшему
    {
        for (i1 = 0; i1 < n; i1++)
        {
            if (dist[i] < dist[i1] && (i < i1))
            {
                w = dist[i];
                dist[i] = dist[i1];
                dist[i1] = w;

                w = employee[i];
                employee[i] = employee[i1];
                employee[i1] = w;
            }
        }
    }
            for (i = 0; i < n; i++)// расставляет номера сотрудников и их расстояния по порядку(1, 2, 3, ...)
    {
        for (i1 = 0; i1 < n; i1++)
        {
            if (employee[i] < employee[i1] && (i > i1))
            {
                w = employee[i];
                employee[i] = employee[i1];
                employee[i1] = w;

                w = taxi[i];
                taxi[i] = taxi[i1];
                taxi[i1] = w;
            }
        }
    }
    for (i = 0; i < n; i++)// вывод результатов
    {
        cout << endl << "сотрудник №" << i+1 << " едет на такси №" << taxi[i];
    }

 }
