﻿// 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int array[10]; // инициализация переменных для первого кейса

    char sym; // для второго кейса
    string str;
    bool flag = true;

    int matrix[3][3], det = 0; // для третьего кейса

    int cs = 0, i = 0, j = 0; // общие
    
    cout << "Введите номер программы:" << endl 
         << "1 - Написать программу, которая заменяет все четные числа в целочисленном статическом массиве на 0. (массив из 10 элементов);" << endl 
         << "2 - Ввод символа с клавиатуры (с проверкой что это именно символ), ввод строки с клавиатуры (с проверкой что это именно строка). Вывод в консоль номера, который символ занимает в строке, если он там есть. Если нет — вывод сообщения об отсутствии символа;" << endl 
         << "3 - Расчет определителя матрицы, матрица размером 3 на 3. Ввод чисел построчно. Числа только целые." << endl;
    cin >> cs;
    switch (cs)
    {
    case (1):
        for (i = 0; i < 10; i++)    // ввод массива
        {
            cout << "Введите элемент №" << i << " ";
            cin >> array[i];
        }
        for (i = 0; i < 10; i++)    // замена четных чисел на 0
        {
            if (array[i] % 2 == 0)
                array[i] = 0;
        }
        for (i = 0; i < 10; i++)    // вывод массива
        {
            cout << array[i] << " ";
        }
        break;

    case (2):
        cout << "Введите символ: ";
        cin >> sym;
        while (isdigit(sym))    // проверка и ввод символа
        {
            cout << "Ошибка. Введите символ!" << endl;
            cin >> sym;
        }
        cout << "Введите строку: ";
        cin >> str;
        for (i = 0; i < str.length(); i++)
        {
            if (sym == str[i] && flag)  // первая встреча символа в строке
            {
                cout << "Первый раз символ встречается в строке на " << i + 1 << " месте" << endl;
                flag = false;
            }
        }
        if (flag)
            cout << "Символ в строке не найден!" << endl;
        break;

    case (3):
        for (i = 0; i < 3; i++) // ввод матрицы
        {
            for (j = 0; j < 3; j++)
            {
                cout << "Введите элемент [" << i << "][" << j << "]: ";
                cin >> matrix[i][j];
            }
        }
        det = matrix[0][0] * matrix[1][1] * matrix[2][2]    // формула определителя
            + matrix[0][1] * matrix[1][2] * matrix[2][0]
            + matrix[0][2] * matrix[1][0] * matrix[2][1]
            - matrix[0][2] * matrix[1][1] * matrix[2][0]
            - matrix[0][0] * matrix[1][2] * matrix[2][1]
            - matrix[0][1] * matrix[1][0] * matrix[2][2];
        cout << "Определитель = " << det;   //вывод определителя матрицы
        break;
    }
}
    

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
