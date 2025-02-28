﻿// 8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

double average(int* array, int size) { // функция определения среднего арифметического
    double sum = 0;
    for (int i = 0; i < size; i++)
        sum += array[i];
    sum /= size;
    return sum;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int num = 0, arr[5]; // инициализация переменных для кейса 1

    char letter; // для кейса 2

    int size = 0; // для кейса 3

    int cs = 0, i = 0; // общие
    cout << "Введите номер программы:" << endl 
         << "1 - Составить программу, которая будет считывать введённое пятизначное число. После чего, каждую цифру этого числа необходимо вывести в новой строке.;" << endl 
         << "2 - Напишите программу, которая позволяет пользователю ввести в консоли латинскую букву нижнего регистра, переводит её в верхний регистр и результат выводит в консоль;" << endl 
         << "3 - Написать функцию, подсчитывающую среднее арифметическое целого массива. Предварительно объявив и, при необходимости, инициализировав переменные." << endl;
    cin >> cs;
    switch (cs)
    {
    case (1): 
        cout << "Введите пятизначное число: ";
        cin >> num;
        for (i = 0; i < 5; i++) // заполнение массива цифрами
        {
            arr[i] = num % 10;
            num /= 10;
        }

        for (i = 4; i >= 0; i--)    // вывод массива в обратном порядке (для правильного порядка чисел)
            cout << arr[i] << endl;
        break;

    case (2):
        cout << "Введите строчную букву: ";
        cin >> letter;  // ввод буквы
        letter = toupper(letter);   // перевод буквы в верхний регистр
        cout << "Буква в верхнем регистре: " << letter; // вывод
        break;

    case (3):
        cout << "Введите размер массива: ";
        cin >> size;

        int* array = new int[size]; // создание и заполнение динамического массива
        cout << "Заполните массив: " << endl;
        for (i = 0; i < size; i++)
            cin >> array[i];

        cout << "Среднее арифметическое значений массива: " << average(array, size);    // вывод среднего арифметического
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
