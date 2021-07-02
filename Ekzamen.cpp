﻿// Ekzamen.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;

class Harbinger
{
private:
	string h_name;
	int h_age;
	string CatchPhrase;
public:
	Harbinger(string name = "Иисус", int age = 2000)
		: h_name(name), h_age(age)
	{
	}

	Harbinger(string name, int age, string phrase) : h_name(name), h_age(age), CatchPhrase(phrase) {}
	string getName() const { return h_name; }
	int getAge() const {
		return h_age;
	}

	void setAge(int age) {
		h_age = age;
	}

	void setName(string name) {
		h_name = name;
	}

	void setPhrase(string phrase) {
		CatchPhrase = phrase;
	}

	string getPhrase() const { return CatchPhrase; }
};


class Prophet : public Harbinger {
private:
	string* MagnumOpus = new string[3];
	string ph_name;
	int ph_age;
	string ph_call;
public:

	Prophet(string name = "Александр", int age = 20, string call = "") : ph_name(name), ph_age(age), ph_call(call) {
		setMagnum();
	}

	void setMagnum(string* arr = NULL) {
		if (arr) {
			for (int i = 0; i < 3; i++)
			{
				if (arr[i].length() > 25) cout << "Ошибка длины строки!";
				return;
			}
			MagnumOpus = arr;
			setCall();
		}

		else {
			MagnumOpus[0] = "АБВ";
			MagnumOpus[1] = "АБ";
			MagnumOpus[2] = "А";
			setCall();
		}
	}

	string* getMagnum() {
		return MagnumOpus;
	}

	void setCall() {
		string max = MagnumOpus[0];
		if (MagnumOpus[1].length() > max.length())
			max = MagnumOpus[1];
		if (MagnumOpus[2].length() > max.length())
			max = MagnumOpus[2];
		if (ph_call.length() < max.length())
			ph_call = max;
	}

	string getCall() { return ph_call; }

	void setAge(int age) { ph_age = age; }
	int getAge() { return ph_age; }

	void setName(string name) { ph_name = name; }
	string getName() { return ph_name; }
};

class DeusEx : public Prophet {
private:
	string gd_name;
	int gd_year;
	Harbinger hb;
	Prophet pr;

public:
	DeusEx() {
		gd_year = 2021;
		gd_name = "Бог";
	}
	void print() {
		cout << hb.getName() << " в возрасте " << hb.getAge() << " говорил, что " << hb.getPhrase() << endl;
		cout << endl;
		cout << "Первое пророчество: " << (pr.getMagnum())[1] << endl;
		cout << "Второе пророчество: " << (pr.getMagnum())[2] << endl;
		cout << "Главное пророчество: " << (pr.getCall()) << endl;
		cout << endl;
		cout << "Так говорил " << pr.getName() << " в возрасте " << pr.getAge() << endl;
		cout << "В год " << gd_year << " пришел " << gd_name << ", которого предрекали " << hb.getName() << " и " << pr.getName() << endl;
	}

	string getName() { return gd_name; }
	int getYear() { return gd_year; }

};

class Believer : private DeusEx {
private:
	string bv_name;
	int bv_age;
	DeusEx de;
	Prophet ph;
public:

	Believer(string name, int age) {
		bv_name = name;
		bv_age = age;
	}
	void setName(string name) { bv_name = name; }
	void setAge(int age) { bv_age = age; }

	string getName() { return bv_name; }
	int getAge() { return bv_age; }

	void print() {
		cout << endl;
		cout << "Верующий " << bv_name << " молится " << de.getName() << " именем " << ph.getName() <<
			" с " << de.getYear() << endl;
	}
};

int main() {
	setlocale(LC_ALL, "Russian");

	const string name = "Кирилл";
	const int age = 200;

	DeusEx obj;
	obj.print();

	Believer obj2(name, age);
	obj2.print();

	return 0;
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
