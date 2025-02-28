﻿// 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int array[10], k = 0; // инициализация переменных для первого кейса

    int size_str, size_vowels; // для второго кейса
    char vowels[] = { 'A','a','E','e','I','i','Y','y','U','u', 'O', 'o',
    'А','Е','Ё','И','О','У','Ы','Э','Ю','Я','а','е','ё','и','о','у','ы','э','ю','я' };
    char str[256];
    char newstr[256];

    int cs = 0, i = 0, j = 0; // общие

    cout << "Введите номер программы:" << endl
        << "1 - Исключение из массива всех отрицательных чисел;" << endl
        << "2 - Нахождение всех гласных в строке и вывод их на экран." << endl;
    cin >> cs;
    switch (cs)
    {
    case (1):
        cout << "Введите массив из 10 чисел: ";
        for (i = 0; i < 10; i++)    // ввод массива
        {
            cin >> array[i];
        }

        for (i = 0; i < sizeof(array) / sizeof(*array) - 1 - k; i++)
        {
            if (array[i] < 0)
            {
                k++;
                for (j = i; j < sizeof(array) / sizeof(*array) - 1; j++)
                {
                    array[j] = array[j + 1];    // смещение массива, если отрицательное число
                }
                i--;
            }
        }
        for (i = 0; i < sizeof(array) / sizeof(*array) - 1 - k; i++)
        {
            cout << array[i] << " ";    // вывод массива без отрицательных чисел
        }
        break;

    case (2):
        cout << "Введите строку: "; //ввод
        cin >> str;

        cout << "Гласные буквы в строке: ";
        for (i = 0; i < strlen(str); i++) // поиск и вывод гласных букв
            for (j = 0; j < strlen(vowels); j++)
                if (str[i] == vowels[j])
                    cout << str[i];

        cout << endl;
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
